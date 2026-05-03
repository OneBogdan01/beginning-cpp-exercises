// This exercise was extremely confusing.
#include <format>
#include <iterator>
#include <print>
#include <string>
#include <vector>
template <typename Iterator, typename Comparison>
Iterator oldFindOptimum(Iterator begin, Iterator end, Comparison compare)
    requires std::forward_iterator<Iterator> &&
             std::indirect_strict_weak_order<Comparison, Iterator>
{
    if (begin == end)
        return end;
    Iterator optimum{begin};
    for (Iterator iter{++begin}; iter != end; ++iter) {
        if (compare(*iter, *optimum))
            optimum = iter;
    }
    return optimum;
}
template <
    std::forward_iterator Iterator,
    // sentinel is not neccesarily type of iterator, something that let us know when to stop
    std::sentinel_for<Iterator> Sentinel,
    // complete dark magic, can  accept a member function that is applied before comparison!
    typename Proj = std::identity,
    // magic that checks if what you get after a dereferenced iterator
    std::indirect_strict_weak_order<std::projected<Iterator, Proj>> Comparison = std::ranges::less>
Iterator findOptimum(Iterator begin, Sentinel end, Comparison compare = {}, Proj proj = {})

{
    // the sentinel is not the right type
    if (begin == end)
        return begin;
    Iterator optimum{begin};
    for (Iterator iter{++begin}; iter != end; ++iter) {
        if (std::invoke(compare, std::invoke(proj, *iter), std::invoke(proj, *optimum)))
            optimum = iter;
    }
    return optimum;
}

class Box {
  public:
    Box() = default;
    Box(double length, double width, double height)
        : m_length{length}, m_width{width}, m_height{height} {};

    double volume() const {
        return m_length * m_width * m_height;
    }
    bool operator<(const Box& other) const {
        return volume() < other.volume();
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

int main() {
    std::vector<Box> v{{2.0, 2.0, 3.0}, {1.0, 3.0, 2.0}, {1.0, 2.0, 1.0}, {2.0, 3.0, 3.0}};

    auto smallest = findOptimum(v.begin(), v.end(), &Box::compare);
    std::println("smallest: {}", smallest->volume());

    std::vector<std::string> words{"hi", "hello", "hey"};
    auto shortest = findOptimum(words.begin(), words.end(), std::less{}, &std::string::size);
    std::println("shortest word: {}", *shortest);
}