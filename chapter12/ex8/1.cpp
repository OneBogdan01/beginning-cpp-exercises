// Using nested classes

#include "truckload.hpp"

#include <print>
SharedBox find_largest_box(const Truckload& load1) {
    // Find the largest Box in the list
    auto iterator{load1.getIterator()};

    SharedBox largestBox{iterator.getFirstBox()};
    SharedBox nextBox{iterator.getNextBox()};
    while (nextBox) {
        if (nextBox->compare(*largestBox) > 0)
            largestBox = nextBox;
        nextBox = iterator.getNextBox();
    }
    return largestBox;
}
SharedBox find_smallest_box(const Truckload& load1) {
    // Find the largest Box in the list
    auto iterator{load1.getIterator()};

    SharedBox smallesBox{iterator.getFirstBox()};
    SharedBox nextBox{iterator.getNextBox()};
    while (nextBox) {
        if (nextBox->compare(*smallesBox) < 0)
            smallesBox = nextBox;
        nextBox = iterator.getNextBox();
    }
    return smallesBox;
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

    SharedBox largestBox = find_largest_box(load1);

    std::println("\nThe largest box in the first list is {}", to_string(*largestBox));
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

    std::println("\nThe smallest box in the second list is {}", to_string(*smallestBox));
}
