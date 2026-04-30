// (with improvement suggested in the "A Better Stack" section: see Stack<> source)
#include "stack.hpp"

#include <iostream>
#include <print>
#include <stack>
#include <string>

int main() {
    std::string words[]{"The", "quick", "brown", "fox", "jumps"};
    std::stack<std::string> wordStack; // A stack of strings

    for (const auto& word : words)
        wordStack.emplace(word);

    std::stack<std::string> newStack{wordStack}; // Create a copy of the stack

    // Display the words in reverse order
    while (!newStack.empty()) {
        std::print("{} ", newStack.top());
        newStack.pop();
    }
    std::println("");

    // Reverse wordStack onto newStack
    while (!wordStack.empty()) {
        newStack.push(wordStack.top());
        wordStack.pop();
    }

    // Display the words in original order
    while (!newStack.empty()) {
        std::print("{} ", newStack.top());
        newStack.pop();
    }
    std::println("");

    std::println("\nEnter a line of text:");
    std::string text;
    std::getline(std::cin, text); // Read a line into the string object

    Stack<char> characters; // A stack for characters

    for (std::size_t i{}; i < text.length(); ++i)
        characters.push(text[i]); // Push the string characters onto the stack

    while (!characters.isEmpty())
        std::print("{}", characters.pop()); // Pop the characters off the stack

    std::println("");
}