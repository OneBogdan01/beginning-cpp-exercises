#pragma once
#include <cstddef>
#include <stdexcept>
#include <string>

// Based on chapter 12 ex 8
template <typename T>
class LinkedList {
  public:
    class Iterator; // Forward declaration

    LinkedList() = default;

    LinkedList(const LinkedList& src) {
        for (Package* package{src.m_head}; package; package = package->m_next) {
            push_back(package->m_value);
        }
    }

    // Destructor
    ~LinkedList() {
        clear();
    }

    // Add element to end of list
    void push_back(const T& value) {
        auto* package{new Package{value}}; // Create a new Package

        if (m_tail) // Check list is not empty
        {
            package->m_previous = m_tail;
            m_tail->m_next = package;
        } else {
            m_head = package;
        }

        m_tail = package;
        ++m_size;
    }

    // Add element to front of list
    void push_front(const T& value) {
        auto* package{new Package{value}}; // Create a new Package

        if (m_head) // Check list is not empty
        {
            package->m_next = m_head;
            m_head->m_previous = package;
        } else {
            m_tail = package;
        }

        m_head = package;
        ++m_size;
    }

    // Remove all elements from the list
    void clear() {
        Package* current{m_head}; // Start at the head
        while (current) {
            Package* next{current->m_next};
            current->m_next = nullptr;
            delete current; // Delete the current package
            current = next; // Move to the next package
        }
        m_head = m_tail = nullptr;
        m_size = 0;
    }

    bool empty() const {
        return m_size == 0;
    }
    std::size_t size() const {
        return m_size;
    }

    Iterator getIterator() const {
        return Iterator{m_head, m_tail};
    }

  private:
    struct Package {
        T m_value;
        Package* m_next{nullptr};
        Package* m_previous{nullptr};

        Package(const T& value) : m_value{value} {}
    };

    Package* m_head{nullptr}; // First in the list
    Package* m_tail{nullptr}; // Last in the list
    std::size_t m_size{0};    // Number of elements
};

template <typename T>
class LinkedList<T>::Iterator {
  public:
    // Forward traversal
    const T& getFirst() {
        m_current = m_head; // Reset to the head
        return m_current->m_value;
    }
    const T& getNext() {
        m_current = m_current->m_next; // Move to the next package
        return m_current->m_value;     // Extract the value to return
    }
    bool hasNext() const {
        return m_current && m_current->m_next != nullptr;
    }

    // Backward traversal
    const T& getLast() {
        m_current = m_tail; // Reset to the tail
        return m_current->m_value;
    }
    const T& getPrevious() {
        m_current = m_current->m_previous; // Move to the previous package
        return m_current->m_value;         // Extract the value to return
    }
    bool hasPrevious() const {
        return m_current && m_current->m_previous != nullptr;
    }

  private:
    Package* m_head;
    Package* m_tail;
    Package* m_current{nullptr};

    friend class LinkedList;
    explicit Iterator(Package* head, Package* tail) : m_head{head}, m_tail{tail} {}
};
