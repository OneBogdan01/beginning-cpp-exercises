/*
  Creating RAII classes to manage resource handles returned by a C interface
  Remember: RAII is not just for dynamic memory: every resource should be managed by an object!
 */

#include "DB.h"
#include "DBException.hpp"
#include "Customer.hpp"

#include <functional>
#include <print>
#include <vector>

class SQLConnection {
  public:
    SQLConnection(DB_CONNECTION* connection) : m_connection(connection) {}
    SQLConnection(const SQLConnection&) = delete;
    SQLConnection& operator=(const SQLConnection&) = delete;
    SQLConnection(SQLConnection&& connection) noexcept
        : m_connection(std::exchange(connection.m_connection, nullptr)) {};

    SQLConnection& operator=(SQLConnection&& connection) noexcept {
        m_connection = std::exchange(connection.m_connection, nullptr);
        return *this;
    }
    ~SQLConnection() {
        if (m_connection)
            db_disconnect(m_connection);
    }
    void swap(SQLConnection& moved) noexcept {
        std::swap(m_connection, moved.m_connection);
    };
    operator DB_CONNECTION*() const {
        return m_connection;
    }

  private:
    DB_CONNECTION* m_connection;
};
class QueryResult {
  public:
    QueryResult(DB_QUERY_RESULT* result = nullptr) : m_result(result) {}
    ~QueryResult() {
        if (m_result)
            db_free_result(m_result);
    }
    QueryResult(const QueryResult&) = delete;
    QueryResult& operator=(const QueryResult&) = delete;
    QueryResult(QueryResult&& query) noexcept : m_result(std::exchange(query.m_result, nullptr)) {};

    QueryResult& operator=(QueryResult&& query) noexcept {
        m_result = std::exchange(query.m_result, nullptr);
        return *this;
    }
    operator DB_QUERY_RESULT*() const {
        return m_result;
    }

  private:
    DB_QUERY_RESULT* m_result;
};
void verifyCustomerFields(
    DB_QUERY_RESULT* result); // Sanity check on the number of fields returned by our query
std::vector<Customer>
readCustomers(DB_QUERY_RESULT* result); // Convert the DB result to a series of C++ objects

int main() {
    SQLConnection connection{db_connect()};
    SQLConnection moved{std::move(connection)};
    try {
        QueryResult result{db_query(moved, "SELECT * FROM CUSTOMER_TABEL")};
        QueryResult result2;
        result2 = std::move(result);
        if (!result2) {
            throw DatabaseException{"Query failed"};
        }

        std::vector customers{readCustomers(result2)};

        if (customers.empty()) {
            std::println("No customers found?");
            return 2;
        }

        for (auto& customer : customers) {
            std::println("{}", to_string(customer));
        }

    } catch (std::exception& caught) {
        std::println("{}", caught.what());
        return 1;
    }

    return 0;
}

std::vector<Customer> readCustomers(DB_QUERY_RESULT* result) {
    // Sanity check
    // (if the number of fields does not match 5,
    // the code below would crash!)
    verifyCustomerFields(result);

    std::vector<Customer> customers;

    auto row{db_fetch_row(result)};
    while (row) {
        customers.push_back(Customer{
            row[0],            // Surname
            row[1],            // Name
            row[2],            // Street
            std::stoi(row[3]), // Street number
            row[4]             // City
        });

        row = db_fetch_row(result);
    }

    return customers;
}

void verifyCustomerFields(DB_QUERY_RESULT* result) {
    const int numFields{db_num_fields(result)};
    if (numFields < 0) {
        throw DatabaseException{"db_num_fields() failed"};
    }
    if (numFields != 5) {
        throw DatabaseException{"Unexpected number of fields: " + std::to_string(numFields)};
    }
}