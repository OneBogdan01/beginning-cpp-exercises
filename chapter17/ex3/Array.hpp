#pragma once
#include <stdexcept>
#include <string>
#include <ostream>
#include <vector>

template <typename T>
class SparseArray {
  public:
    T& operator[](size_t index) {
        // do we get an element already?
        for (std::pair<size_t, T>& pair : m_array) {
            if (pair.first == index) {
                return pair.second;
            }
        }

        // Add a default constructed object at the new index and return that
        return m_array.emplace_back(std::make_pair(index, T{})).second;
    }
    const T& at(size_t index) const {
        for (std::pair<size_t, T>& pair : m_array) {
            if (pair.first == index) {
                return pair.second;
            }
        }
        throw std::out_of_range{"No value found at index:" + std::to_string(index)};
    }
    bool elementExists(size_t index) const {
        for (std::pair<size_t, T>& pair : m_array) {
            if (pair.first == index) {
                return true;
            }
        }
        return false;
    }
    friend std::ostream& operator<<(std::ostream& stream, const SparseArray<T>& array) {
        for (const std::pair<size_t, T>& pair : array.m_array) {
            stream << pair.first << " with value " << pair.second << '\n';
        }
        return stream;
    }

  private:
    std::vector<std::pair<size_t, T>> m_array;
};
