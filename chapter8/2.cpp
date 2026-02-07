
#include "pch.hpp"

#include <iostream>

std::string reverse_string(const std::string& input) {
    std::string copy = input;
    std::reverse(copy.begin(), copy.end());
    return copy;
}
int main() {
    std::string input;
    std::println("Enter a string to be reversed");
    std::getline(std::cin, input);
    // modern cpp should prefer to return by copy
    std::println("{}", reverse_string(input));
}
