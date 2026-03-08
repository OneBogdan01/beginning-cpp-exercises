#pragma once
#include <format>
#include <functional>
#include <memory>
#include <random>
#include <string>

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

    Truckload(SharedBox box) // Constructor - one Box
        ;
    Truckload(const std::vector<SharedBox>& boxes); // Constructor - vector of Boxes
    Truckload(const Truckload& src);                // Copy constructor

    ~Truckload(); // Destructor
    class Iterator;
    Iterator getIterator() const;

    void addBox(SharedBox box); // Add a new SharedBox
    void delete_node(Package* current);
    bool removeBox(SharedBox box); // Remove a Box from the Truckload
    void removeBox(Iterator& box);  // Remove a Box from the Truckload

    void printBoxes() const; // Output the Boxes
    void printBoxesReversed() const;

  private:
    class Package {
      public:
        SharedBox m_box; // Pointer to the Box object contained in this Package
        Package* m_next; // Pointer to the next Package in the list
        Package* m_previous;

        Package(SharedBox box) : m_box{box}, m_next{nullptr}, m_previous{nullptr} {} // Constructor
        ~Package() {
            delete m_next;
        } // Destructor
    };

    Package* m_head{}; // First in the list
    Package* m_tail{}; // Last in the list
};
// Creates a pseudorandom number generator (PRNG) for random doubles between 0 and max
inline auto createUniformPseudoRandomNumberGenerator(double max) {
    std::random_device seeder; // True random number generator to obtain a seed (slow)
    std::default_random_engine generator{seeder()};        // Efficient pseudo-random generator
    std::uniform_real_distribution distribution{0.0, max}; // Generate in [0, max) interval
    return std::bind(distribution, generator);             //... and in the darkness bind them!
}

inline Box randomBox() {
    const int dimLimit{100}; // Upper limit on Box dimensions
    static auto random{createUniformPseudoRandomNumberGenerator(dimLimit)};
    return Box{random(), random(), random()};
}

inline auto randomSharedBox() {
    return std::make_shared<Box>(randomBox()); // Uses copy constructor
}

class Truckload::Iterator {
  public:
    SharedBox getFirstBox();    // Get the first Box
    SharedBox getLastBox();     // Get the first Box
    SharedBox getNextBox();     // Get the next Box
    SharedBox getPreviousBox(); // Get the next Box
    SharedBox getCurrentBox() const;  // Get the next Box
  private:
    Package* m_head;        // The head of the linked list (needed for getFirstBox())
    Package* m_tail;        // The head of the linked list (needed for getFirstBox())
    Package* m_current;     // The package whose Box to retrieve next
    friend class Truckload; // Only a Truckload can create an Iterator
    explicit Iterator(Package* head, Package* tail = nullptr)
        : m_head{head}, m_tail(tail), m_current{nullptr} {}
};
