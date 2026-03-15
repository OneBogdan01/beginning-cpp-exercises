#include "Box.hpp"
#include <algorithm>
#include <compare>
#include <format>

double Box::volume() const {
    return m_length * m_width * m_height;
}

Box Box::operator+(const Box& aBox) const {
    Box box{*this};
    box += aBox;
    return box;
}

const Box& Box::operator+=(const Box& aBox) {
    m_length = std::max(m_length, aBox.m_length);
    m_width = std::max(m_width, aBox.m_width);

    m_height += aBox.m_height;
    return *this;
}
std::partial_ordering Box::operator<=>(const Box& aBox) const {
    return volume() <=> aBox.volume();
}

std::partial_ordering Box::operator<=>(double value) const {
    return volume() <=> value;
}

std::string to_string(const Box& box) {
    return std::format("Box({:.1f}, {:.1f}, {:.1f})", box.getLength(), box.getWidth(),
                       box.getHeight());
}
Box Box::operator*(double value) const {
    Box copy{*this};
    copy *= value;
    return copy;
}
Box Box::operator/(double value) const {
    Box copy{*this};
    copy /= value;
    return copy;
}
Box operator*(double value, const Box& box) {
    return box * value;
}

const Box& Box::operator*=(double value) {
    m_height *= value;
    return *this;
}
const Box& Box::operator/=(double value) {
    m_height /= value;
    return *this;
}
