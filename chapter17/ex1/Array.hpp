#include <cstdio>
#include <stdexcept>
#include <string>

template <typename T>
class Array {
  public:
    explicit Array(std::size_t size); // Constructor
    Array() : m_elements(nullptr), m_size(0) {};
    ~Array();                                     // Destructor
    Array(const Array& array);                    // Copy constructor
    Array& operator=(const Array& rhs);           // Copy assignment operator
    T& operator[](std::size_t index);             // Subscript operator
    const T& operator[](std::size_t index) const; // Subscript operator-const arrays
    std::size_t getSize() const noexcept;         // Accessor for m_size
    void swap(Array<T>& rhs) noexcept {
        std::swap(m_size, rhs.m_size);
        std::swap(m_elements, rhs.m_elements);
    }
    void push_back(const T& element) {
        Array temp{m_size + 1};
        for (std::size_t i{}; i < m_size; ++i)
            temp.m_elements[i] = m_elements[i];

        temp[m_size] = element;
        swap(temp);
    }

  private:
    T* m_elements;      // Array of elements of type T
    std::size_t m_size; // Number of array elements
};

// Template for getter of m_size member
template <typename T>
std::size_t Array<T>::getSize() const noexcept {
    return m_size;
}

// Constructor template
template <typename T>
Array<T>::Array(std::size_t size) : m_elements{new T[size]{}}, m_size{size} {}

// Copy constructor template
template <typename T>
Array<T>::Array(const Array& array) : Array{array.m_size} {
    for (std::size_t i{}; i < m_size; ++i)
        m_elements[i] = array.m_elements[i];
}

// Destructor template
template <typename T>
Array<T>::~Array() {
    delete[] m_elements;
}

// const subscript operator template
template <typename T>
const T& Array<T>::operator[](std::size_t index) const {
    if (index >= m_size)
        throw std::out_of_range{"Index too large: " + std::to_string(index)};
    return m_elements[index];
}

// Non-const subscript operator template in terms of const one
// Uses the 'const-and-back-again' idiom
template <typename T>
T& Array<T>::operator[](std::size_t index) {
    return const_cast<T&>(std::as_const(*this)[index]);
}

// Copy assignment operator template (not exception safe)
template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
    if (&rhs != this)        // If lhs != rhs...
    {                        // ...do the assignment...
        delete[] m_elements; // Release any free store memory

        m_size = rhs.m_size; // Copy the members of rhs into lhs
        m_elements = new T[m_size];
        for (std::size_t i{}; i < m_size; ++i)
            m_elements[i] = rhs.m_elements[i];
    }
    return *this; // ... return lhs
}

class Box {
  public:
    Box() : Box{1.0, 1.0, 1.0} {}
    Box(double l, double w, double h) : m_length{l}, m_width{w}, m_height{h} {}

    double volume() const {
        return m_length * m_width * m_height;
    }

  private:
    double m_length, m_width, m_height;
};
