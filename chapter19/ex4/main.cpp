#include "pch.hpp"

template <typename T, typename UnaryCondition>
std::vector<T> collect_all_that_satisfy(const std::vector<T>& vec, UnaryCondition cond) {
    std::vector<T> result;

    for (auto& element : vec) {
        if (cond(element)) {
            result.emplace_back(element);
        }
    }
    return result;
}
int main() {
    {
        std::vector whole_numbers{1, 2, 3, 5, 10, 200, 5, 1002};
        std::println("{}", whole_numbers);
        int user_threshold{};
        std::cin >> user_threshold;
        auto above_user_threshold{collect_all_that_satisfy(
            whole_numbers, [user_threshold](auto element) { return element > user_threshold; })};
        std::println("{}", above_user_threshold);
    }
    {
        std::vector characters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'A', 'B', 'C', 'D', 'E'};
        std::println("{}", characters);
        auto capital_characters{collect_all_that_satisfy(
            characters, [](auto element) { return isupper(element) != 0; })};
        std::println("{}", capital_characters);
    }
    {
        std::vector<std::string> strings{"racecar", "kayak", "cat", "dog", "aca", "jooj"};
        std::println("{}", strings);
        auto palindroms{collect_all_that_satisfy(strings, [](std::string_view element) {
            auto middle_index{(element.length() - 1) / 2};
            auto first_half{element.substr(0, element.length() / 2)};
            std::string second_half{element.substr(middle_index + 1, element.length() / 2)};
            std::reverse(second_half.begin(), second_half.end());
            auto result{first_half.compare(second_half)};
            // the same strings so it is a palindrom
            return result == 0;
        })};
        std::println("{}", palindroms);
    }
}