
#include <algorithm>
#include <print>
#include <string>
#include <vector>
int main() {
    std::vector<std::string> names{"Frodo Baggins",  "Gandalf the Gray",  "Aragon",
                                   "Samwise Gamgee", "Peregrin Took",     "Meriadoc Brandybuck",
                                   "Gimli",          "Legolas Greenleaf", "Boromir"};

    // Sort the names lexicographically
    std::ranges::sort(names);
    std::println("Names sorted lexicographically: {:n}", names);

    // Sort the names by length
    std::ranges::sort(names, [](const auto& left, const auto& right) {
        auto c{std::ranges::less{}(left.length(), right.length())};
        return c;
    });
    std::println("Names sorted by length: {:n}", names);

    // std::ranges::sort(
    //     names, [](const auto& left, const auto& right) { return left.length() < right.length();
    //     });
    // std::println("Names sorted by length: {:n}", names);
}