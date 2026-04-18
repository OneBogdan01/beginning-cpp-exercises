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
    LinkedList<std::string> original;
    original.push_back("hello");
    original.push_back("world");
    original.push_back("foo");
    LinkedList<std::string> moved{std::move(original)};
    std::println("After move construct: original size={}, moved size={}", original.size(),
                 moved.size());

    LinkedList<std::string> target;
    target.push_back("will be replaced");
    target = std::move(moved);
    std::println("After move assign: moved size={}, target size={}", moved.size(), target.size());

    std::print("contents: ");
    auto it = target.getIterator();
    auto val = it.getFirst();
    while (true) {
        std::print("{} ", val);
        if (!it.hasNext())
            break;
        val = it.getNext();
    }
    std::println("");

    LinkedList<std::string> test;
    std::string temp{"this will be moved"};
    std::println("Before push_back: temp={}", temp);
    test.push_back(std::move(temp));
    std::println("After push_back:  temp={}", temp);
}
