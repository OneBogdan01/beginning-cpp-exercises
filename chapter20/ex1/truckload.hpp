#pragma once
#include <cstddef>
#include <format>
#include <functional>
#include <memory>
#include <random>
#include <stdexcept>
#include <string>
#include <utility>

class Box {
  public:
    Box() = default;
    Box(double length, double width, double height)
        : m_length{length}, m_width{width}, m_height{height} {};

    double volume() const {
        return m_length * m_width * m_height;
    }

    int compare(const Box& box) const {
        if (volume() < box.volume())
            return -1;
        if (volume() == box.volume())
            return 0;
        return +1;
    }

    friend std::string to_string(const Box& box) {
        return std::format("Box({:.1f},{:.1f},{:.1f})", box.m_length, box.m_width, box.m_height);
    }

  private:
    double m_length{1.0};
    double m_width{1.0};
    double m_height{1.0};
};

using SharedBox = std::shared_ptr<Box>;

class Truckload {
  public:
    class Package;

    Truckload() = default; // Default constructor - empty truckload

    Truckload(SharedBox box); // Constructor - one Box

    Truckload(const std::vector<SharedBox>& boxes); // Constructor - vector of Boxes
    Truckload(const Truckload& src);                // Copy constructor
    Truckload& operator=(const Truckload& src) {
        if (&src == this)
            return *this;
        m_boxes = src.m_boxes;
        return *this;
    }
    Truckload(Truckload&& src) noexcept;
    void swap(Truckload& truck) noexcept;
    Truckload& operator=(Truckload&& src) noexcept;

    SharedBox& operator[](std::size_t index) {
        return m_boxes.at(index);

    } // Overloaded subscript operator

    ~Truckload(); // Destructor
    class Iterator;
    Iterator getIterator() const;

    void addBox(SharedBox box); // Add a new SharedBox
    void delete_node(const SharedBox& current);
    bool removeBox(SharedBox box); // Remove a Box from the Truckload
    void removeBox(Iterator& box); // Remove a Box from the Truckload

    void printBoxes() const; // Output the Boxes
    void printBoxesReversed() const;

  private:
    std::vector<SharedBox> m_boxes;
};

class Truckload::Iterator {
  public:
    SharedBox getFirstBox();         // Get the first Box
    SharedBox getLastBox();          // Get the first Box
    SharedBox getNextBox();          // Get the next Box
    SharedBox getPreviousBox();      // Get the next Box
    SharedBox getCurrentBox() const; // Get the next Box
  private:
    std::vector<SharedBox>::const_iterator m_head;
    std::vector<SharedBox>::const_iterator m_tail;
    std::vector<SharedBox>::const_iterator m_current;
    friend class Truckload; // Only a Truckload can create an Iterator
    explicit Iterator(std::vector<SharedBox>::const_iterator begin,
                      std::vector<SharedBox>::const_iterator end)
        : m_head{begin}, m_tail{end} {}
};
