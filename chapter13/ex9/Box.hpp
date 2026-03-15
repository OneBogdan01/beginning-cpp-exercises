#pragma once
#include <algorithm>
#include <compare>
#include <cstdint>
#include <string>

class RandomGen {
  public:
    RandomGen(uint32_t n) : m_seed(n % 100) {}

    int operator()() {
        m_seed = (m_seed * 41 + 7) % 100;
        return m_seed;
    };

  private:
    int m_seed;
};
class Box {
  public:
    Box() = default; // Default constructor
    Box(double length, double width, double height)
        : m_length{std::max(length, width)}, m_width{std::min(length, width)}, m_height{height} {}

    double volume() const; // Function to calculate the volume

    // Accessors
    double getLength() const {
        return m_length;
    }
    double getWidth() const {
        return m_width;
    }
    double getHeight() const {
        return m_height;
    }

    // Functions that add full support for comparison operators
    std::partial_ordering operator<=>(const Box& aBox) const;
    std::partial_ordering operator<=>(double value) const;
    bool operator==(const Box& aBox) const = default;
    Box operator+(const Box& aBox) const; // Function to add two Box objects
    const Box& operator+=(const Box& aBox);

    Box operator*(double value) const;

    Box operator/(double value) const;

    const Box& operator*=(double value);
    const Box& operator/=(double value);

  private:
    double m_length{1.0};
    double m_width{1.0};
    double m_height{1.0};
};

Box operator*(double value, const Box& box);

// Conversion to string
std::string to_string(const Box& box);
