// Using nested classes

#include "LinkedList.hpp"

#include <print>

int main() {
    LinkedList<std::string> words;
    words.push_back("the");
    words.push_back("old");
    words.push_back("pond");
    words.push_back("a");
    words.push_back("frog");
    words.push_back("jumps");
    words.push_back("in");
    words.push_back("sound");
    words.push_back("of");
    words.push_back("water");

    {
        auto lastIter = words.getIterator();
        auto currentNode = lastIter.getFirst();
        const size_t words_per_line{5};
        size_t current_word_cout{};
        while (lastIter.hasNext()) {
            std::print("{} ", currentNode);
            current_word_cout++;
            if (current_word_cout == words_per_line) {
                std::println("");
                current_word_cout = 0;
            }
            currentNode = lastIter.getNext();
        }
        std::println("{} ", currentNode);
    }
    {
        auto lastIter = words.getIterator();
        auto currentNode = lastIter.getLast();
        const size_t words_per_line{5};
        size_t current_word_cout{};
        while (lastIter.hasPrevious()) {
            std::print("{} ", currentNode);
            current_word_cout++;
            if (current_word_cout == words_per_line) {
                std::println("");
                current_word_cout = 0;
            }
            currentNode = lastIter.getPrevious();
        }
        std::println("{} ", currentNode);
    }
}
