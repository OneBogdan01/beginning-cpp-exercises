// Sorting words recursively
import std;
import words2;

int main() {
    std::string text;                   // The string to be sorted
    const auto separators{" ,.!?\"\n"}; // Word delimiters

    // Read the string to be processed
    std::println("Enter a string terminated by *:");
    getline(std::cin, text, '*');

    Words words{wrds::extract_words(text, separators)};
    if (words.empty()) {
        std::println("No words in text.");
        return 0;
    }

    w::sort(words);        // Sort the words
    w::print_words(words); // Output the words
}
