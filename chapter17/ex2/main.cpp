#include <print>
#include "Array.hpp"
int main() {
    {
        Pair<int, std::string> pair{0, "def"};
        pair.setFirst(pair.getFirst() + 1);
        std::println("pair equals ({}, {})", pair.getFirst(), pair.getSecond());
        Pair<int, std::string> pair2{123, "abc"};
        Pair<int, std::string> pair3{123, "dgc"};
        std::println("pair equals ({}, {})", pair2.getFirst(), pair2.getSecond());
        std::println("Comparisons: ({}, {})", pair < pair2, pair2 < pair3);
    }
    Pair pair{0, std::string{"def"}};
    pair.setFirst(pair.getFirst() + 1);
    std::println("pair equals ({}, {})", pair.getFirst(), pair.getSecond());
}
