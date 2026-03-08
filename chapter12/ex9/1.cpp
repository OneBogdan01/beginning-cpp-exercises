// Using nested classes

#include "truckload.hpp"

#include <print>
Truckload::Iterator find_largest_box(const Truckload& load1) {
    // Find the largest Box in the list
    auto iterator{load1.getIterator()};
    iterator.getFirstBox();
    auto biggestIterator{iterator};

    while (iterator.getNextBox()) {
        if (iterator.getCurrentBox()->compare(*biggestIterator.getCurrentBox()) > 0) {
            biggestIterator = iterator;
        }
    }
    return biggestIterator;
}
Truckload::Iterator find_smallest_box(const Truckload& load1) {
    auto iterator{load1.getIterator()};
    iterator.getFirstBox();
    auto biggestIterator{iterator};

    while (iterator.getNextBox()) {
        if (iterator.getCurrentBox()->compare(*biggestIterator.getCurrentBox()) < 0) {
            biggestIterator = iterator;
        }
    }
    return biggestIterator;
}
int main() {
    Truckload load1; // Create an empty list

    // Add 12 random Box objects to the list
    const std::size_t boxCount{12};
    for (std::size_t i{}; i < boxCount; ++i)
        load1.addBox(randomSharedBox());

    std::println("The first list:");
    load1.printBoxes();

    // Copy the truckload
    Truckload copy{load1};
    std::println("The copied truckload:");
    copy.printBoxes();

    auto largestBox = find_largest_box(load1);

    std::println("\nThe largest box in the first list is {}",
                 to_string(*largestBox.getCurrentBox()));
    load1.removeBox(largestBox);
    std::println("\nAfter deleting the largest box, the list contains:");

    load1.printBoxes();
    std::println("");
    load1.printBoxesReversed();

    const std::size_t nBoxes{16}; // Number of vector elements
    std::vector<SharedBox> boxes; // Array of Box objects

    for (std::size_t i{}; i < nBoxes; ++i)
        boxes.push_back(randomSharedBox());

    Truckload load2{boxes};
    std::println("\nThe second list:");
    load2.printBoxes();

    auto smallestBox{find_smallest_box(load2)};

    std::println("\nThe smallest box in the second list is {}",
                 to_string(*smallestBox.getCurrentBox()));
}
