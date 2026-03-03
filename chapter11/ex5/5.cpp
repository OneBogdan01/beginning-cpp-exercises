// Sorting words recursively
import std;
import words;

int main() {
    std::string text;                   // The string to be sorted
    const auto separators{" ,.!?\"\n"}; // Word delimiters
    words::Words words_rename;
    // Read the string to be processed
    std::println("Enter a string terminated by *:");
    getline(std::cin, text, '*');

    words::extract_words(words_rename, text, separators);
    if (words_rename.empty()) {
        std::println("No words in text.");
        return 0;
    }

    words::sort(words_rename);        // Sort the words
    words::print_words(words_rename); // Output the words
}
