#include "Person.hpp"
#include <print>
void Person::who() const {
    std::println("This person's name is {}, {} old and {}", m_name, m_age, m_gender);
}

void Employee::who() const {
    std::println("This is an employee {} with id {}", get_name(), m_id);
}
void Executive::who() const {
    std::println("This is executive {}", get_name());
}
