

#include <map>
#include <print>
#include <ranges>
#include <vector>
// Type aliases

using namespace std::views;

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

    double m_length{1.0};
    double m_width{1.0};
    double m_height{1.0};
};

template <>
class std::formatter<Box> {
  public:
    constexpr auto parse(auto& context) {
        if (std::ranges::empty(context)) {
            return context.begin();
        }
        auto closing{std::ranges::find(context, '}')};
        if (closing == context.end()) {
            throw std::runtime_error{"Cannot find closing '}'"};
        }

        std::string temporary{context | filter([](auto character) { return character != 'n'; }) |
                              std::ranges::to<std::string>()};
        std::format_parse_context temp_context{temporary};
        m_double_helper.parse(temp_context);
        m_no_paranthesis = *(closing - 1) == 'n';

        return closing;
    }
    auto format(const Box& box, std::format_context& context) const {
        auto iter{std::format_to(context.out(), "Box: ")};
        context.advance_to(iter);
        iter = m_double_helper.format(box.m_length, context);
        *iter++ = ',';
        *iter++ = ' ';
        context.advance_to(iter);

        iter = m_double_helper.format(box.m_width, context);
        iter = std::format_to(iter, ", ");
        context.advance_to(iter);
        iter = m_double_helper.format(box.m_height, context);
        context.advance_to(iter);
        return iter;
    }

  private:
    bool m_no_paranthesis;

    std::formatter<double> m_double_helper;
};

int main() {
    Box box{1.321, 2.2312, 3.1};
    std::println("Well {:.2}.", box);
    std::println("No more () {:.2n}.", box);
}
