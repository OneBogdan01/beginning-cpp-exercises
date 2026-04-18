

#include "truckload.hpp"

#include <print>
Truckload::Truckload(SharedBox box) {
    m_head = m_tail = new Package{box};
}
// Constructor - vector of Boxes
Truckload::Truckload(const std::vector<SharedBox>& boxes) {
    for (const auto& box : boxes) {
        addBox(box);
    }
}

// Copy constructor
Truckload::Truckload(const Truckload& src) {
    for (Package* package{src.m_head}; package; package = package->m_next) {
        addBox(package->m_box);
    }
}
Truckload::Truckload(Truckload&& src) noexcept : m_head(src.m_head), m_tail(src.m_tail) {
    src.m_head = nullptr;
    src.m_tail = nullptr;
    std::println("This is ctor using move semantics");
}
void Truckload::swap(Truckload& truck) noexcept {
    std::swap(m_head, truck.m_head);
    std::swap(m_tail, truck.m_tail);
}
Truckload& Truckload::operator=(Truckload&& src) noexcept {
    auto truck{std::move(src)};
    swap(truck);
    std::println("This is assignment using move semantics");

    return *this;
}
Truckload::~Truckload() {
    delete m_head;
}

void Truckload::printBoxes() const {
    const std::size_t boxesPerLine{4};
    std::size_t count{};
    for (Package* package{m_head}; package; package = package->m_next) {
        std::print(" {}", to_string(*package->m_box));
        if (!(++count % boxesPerLine))
            std::println("");
    }
    if (count % boxesPerLine)
        std::println("");
}
void Truckload::printBoxesReversed() const {
    const std::size_t boxesPerLine{4};
    std::size_t count{};
    for (Package* package{m_tail}; package; package = package->m_previous) {
        std::print(" {}", to_string(*package->m_box));
        if (!(++count % boxesPerLine))
            std::println("");
    }
    if (count % boxesPerLine)
        std::println("");
}

Truckload::Iterator Truckload::getIterator() const {
    return Iterator{m_head, m_tail};
}

SharedBox Truckload::Iterator::getFirstBox() {
    m_current = m_head; // nullptr only for an empty truckload
    return getCurrentBox();
}
SharedBox Truckload::Iterator::getLastBox() {
    m_current = m_tail;
    return getCurrentBox();
}

SharedBox Truckload::Iterator::getNextBox() {
    if (m_current)                     // If there's no next...
        m_current = m_current->m_next; // Move to the next package

    return getCurrentBox();
}
SharedBox Truckload::Iterator::getPreviousBox() {
    if (m_current)                         // If there's no next...
        m_current = m_current->m_previous; // Move to the next package

    return getCurrentBox();
}
SharedBox Truckload::Iterator::getCurrentBox() const {
    return m_current ? m_current->m_box : nullptr;
}

void Truckload::addBox(SharedBox box) {
    auto package{new Package{box}}; // Create a new Package

    if (m_tail) // Check list is not empty
    {
        package->m_previous = m_tail;
        m_tail->m_next = package;
    } // Append the new object to the tail
    else                  // List is empty
        m_head = package; // so new object is the head

    m_tail = package; // Either way: the latest object is the (new) tail
}

void Truckload::delete_node(Package* current) {
    if (current == m_head)
        m_head = current->m_next; // Removing first box
    if (current == m_tail)
        m_tail = current->m_previous; // Removing last box

    if (current->m_previous)
        current->m_previous->m_next = current->m_next;
    if (current->m_next)
        current->m_next->m_previous = current->m_previous;
    current->m_next = nullptr; // Disconnect the current Package from the list
    delete current;
}
bool Truckload::removeBox(SharedBox boxToRemove) {
    Package* current{m_head}; // initialize current to the head of the list
    while (current) {
        if (current->m_box == boxToRemove) // We found the Box!
        {
            // Restore class invariants by updating impacted member variable pointers:
            delete_node(current);

            // and delete it

            return true; // Return true: we found and removed the box
        }
        current = current->m_next; //  - then move current along to the next Package
    }

    return false; // Return false: boxToRemove was not found
}
void Truckload::removeBox(Iterator& box) {
    auto next = box.m_current->m_next;
    delete_node(box.m_current);
    box.m_current = next;
}
