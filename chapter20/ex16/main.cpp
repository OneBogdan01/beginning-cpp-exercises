

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
        m_no_paranthesis = *(closing - 1) == 'n';
        std::ranges::copy(context.begin(), m_no_paranthesis ? closing - 1 : closing,
                          std::ranges::begin(m_chars));
        return closing;
    }
    auto format(const Box& box, std::format_context& context) const {
        auto field = std::string{"{:"} + m_chars + "}";
        auto fields = field + ", " + field + ", " + field;
        auto fmt = m_no_paranthesis ? fields : "Box(" + fields + ")";
        const auto args{std::make_format_args(box.m_length, box.m_width, box.m_height)};
        return std::vformat_to(context.out(), fmt, args);
    }

  private:
    bool m_no_paranthesis;
    char m_chars[100]{};
};

int main() {
    Box box{1.321, 2.2312, 3.1};
    std::println("Well {:.2}.", box);
    std::println("No more () {:.2n}.", box);
}
