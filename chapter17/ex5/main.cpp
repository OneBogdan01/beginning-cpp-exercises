// Using nested classes

#include "LinkedList.hpp"

#include "SparseArray.hpp"
#include <print>

int main() {
    std::string input{
        "Two roads diverged in a yellow wood and sorry I could not travel both and be one "
        "traveler long I stood"};
    const std::string sepators{" ,"};
    const std::string_view letters{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    SparseArray<LinkedList<std::string>> lists;

    size_t start{input.find_first_not_of(sepators)};

    size_t end{input.find_first_of(sepators, start + 1)};

    // very lazy code
    while (end != std::string::npos) {
        auto word = input.substr(start, end - start);

        auto letter{static_cast<char>(std::toupper(word[0]))};
        auto index{letters.find(letter)};
        lists[index].push_back(word);
        start = input.find_first_not_of(sepators, end + 1);
        end = input.find_first_of(sepators, start);
    }
    if (start != std::string::npos) {
        auto word = input.substr(start, end - start);

        auto letter{static_cast<char>(std::toupper(word[0]))};
        auto index{letters.find(letter)};
        lists[index].push_back(word);
    }
    for (size_t i{}; i < letters.size(); i++) {
        if (lists.elementExists(i) == false) {
            continue;
        }
        std::print("{}: ", letters.at(i));
        auto iter = lists[i].getIterator();

        auto current{iter.getFirst()};

        while (true) {
            std::print("{} ", current);

            if (iter.hasNext() == false) {
                break;
            }
            current = iter.getNext();
        }

        std::println("");
    }
}
