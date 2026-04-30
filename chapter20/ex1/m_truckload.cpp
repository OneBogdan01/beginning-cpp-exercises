

#include "truckload.hpp"

#include <print>
Truckload::Truckload(SharedBox box) {
    m_boxes.emplace_back(box);
}
// Constructor - vector of Boxes
Truckload::Truckload(const std::vector<SharedBox>& boxes) {
    for (const auto& box : boxes) {
        addBox(box);
    }
}

// Copy constructor
Truckload::Truckload(const Truckload& src) : m_boxes{src.m_boxes} {}
Truckload::Truckload(Truckload&& src) noexcept : m_boxes(std::move(src.m_boxes)) {
    std::println("This is ctor using move semantics");
}
void Truckload::swap(Truckload& truck) noexcept {
    std::swap(m_boxes, truck.m_boxes);
}
Truckload& Truckload::operator=(Truckload&& src) noexcept {
    auto truck{std::move(src)};
    swap(truck);
    std::println("This is assignment using move semantics");

    return *this;
}

Truckload::~Truckload() {}

void Truckload::printBoxes() const {
    const std::size_t boxesPerLine{4};
    std::size_t count{};

    for (auto& box : m_boxes) {
        std::print(" {}", to_string(*box));
        if (!(++count % boxesPerLine))
            std::println("");
    }
    if (count % boxesPerLine)
        std::println("");
}
void Truckload::printBoxesReversed() const {
    const std::size_t boxesPerLine{4};
    std::size_t count{};
    for (auto package{m_boxes.rbegin()}; package != m_boxes.rend(); ++package) {
        std::print(" {}", to_string(**package));
        if (!(++count % boxesPerLine))
            std::println("");
    }
    if (count % boxesPerLine)
        std::println("");
}

Truckload::Iterator Truckload::getIterator() const {
    return Iterator{m_boxes.begin(), m_boxes.end()};
}

SharedBox Truckload::Iterator::getFirstBox() {
    if (m_head == m_tail)
        return nullptr;
    m_current = m_head;
    return getCurrentBox();
}
SharedBox Truckload::Iterator::getLastBox() {
    if (m_head == m_tail)
        return nullptr;
    m_current = std::prev(m_tail);
    return getCurrentBox();
}
SharedBox Truckload::Iterator::getNextBox() {
    if (m_current != m_tail && std::next(m_current) != m_tail)
        ++m_current;
    return getCurrentBox();
}

SharedBox Truckload::Iterator::getPreviousBox() {
    if (m_current != m_head)
        --m_current;
    return getCurrentBox();
}
SharedBox Truckload::Iterator::getCurrentBox() const {
    return *m_current;
}

void Truckload::addBox(SharedBox box) {
    m_boxes.emplace_back(box);
}

void Truckload::delete_node(const SharedBox& current) {
    std::erase(m_boxes, current);
}
bool Truckload::removeBox(SharedBox boxToRemove) {
    auto it = std::ranges::find(m_boxes, boxToRemove);
    if (it == m_boxes.end())
        return false;
    m_boxes.erase(it);
    return true;
}
void Truckload::removeBox(Iterator& box) {
    auto offset = std::distance(m_boxes.cbegin(), box.m_current);
    delete_node(box.getCurrentBox());
    box.m_current = m_boxes.cbegin() + offset;
    box.m_head = m_boxes.cbegin();
    box.m_tail = m_boxes.cend();
}