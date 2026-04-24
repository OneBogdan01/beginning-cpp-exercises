#include <string>
#include <vector>
#include <stdint.h>
#include <print>
int main() {
    std::vector<std::string> words;
    words.push_back("Something");
    words.push_back("Cat");
    words.push_back("Bonjour");
    words.push_back("Dog");
    words.push_back("Big Time");
    words.push_back("Hello");
    words.push_back("Bass");
    words.push_back("Haiti");
    auto check_first_letter = [&words](char letter) {
        auto count{0};
        for (std::string& word : words) {
            if (word[0] == letter) {
                ++count;
            }
        }
        return count;
    };

    std::println("{}", check_first_letter('a'));
    std::println("{}", check_first_letter('B'));
    std::println("{}", check_first_letter('C'));
    std::println("{}", check_first_letter('H'));
}