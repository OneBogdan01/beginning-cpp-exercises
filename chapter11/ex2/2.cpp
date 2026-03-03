// Sorting words recursively
import std;
import words2;

int main() {
    using namespace words;
    std::string text;                   // The string to be sorted
    const auto separators{" ,.!?\"\n"}; // Word delimiters

    // Read the string to be processed
    std::println("Enter a string terminated by *:");
    getline(std::cin, text, '*');

    Words words{extract_words(text, separators)};
    if (words.empty()) {
        std::println("No words in text.");
        return 0;
    }

    sort(words);        // Sort the words
    print_words(words); // Output the words
}
