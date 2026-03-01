#include "pch.hpp"

using Words = std::vector<std::shared_ptr<std::string>>;
using RealNumbers = std::vector<f64>;
using NaturalNumbers = std::vector<uint64_t>;

template <typename T>
void swap(T& words, std::size_t first, std::size_t second);

template <typename T>
void sort(T& words);

template <typename T>
void sort(T& words, std::size_t start, std::size_t end);

template <typename T>
T extract_words(const std::string& text, const std::string& separators);

template <typename T>
void print_words(const T& words);

template <auto field_width, typename T>
void print_words(const std::vector<T>& words) {
    constexpr auto max_char_per_line = 80u;
    auto elements_per_line = max_char_per_line / (field_width + 1);
    auto words_printed = 0u;
    for (auto& element : words) {
        std::print("{:{}} ", element, field_width);
        words_printed++;
        if (words_printed == elements_per_line) {
            words_printed = 0;
            std::println("");
        }
    }
    std::println("");
}

template <typename T>
std::size_t max_word_length(const T& words);

int main() {
    // std::string text;                   // The string to be sorted
    // const auto separators{" ,.!?\"\n"}; // Word delimiters

    //// Read the string to be processed
    // std::println("Enter a string terminated by *:");
    // getline(std::cin, text, '*');

    // Words words{extract_words<Words>(text, separators)};
    RealNumbers real_numbers{-3.34, 1.0, 2.0, 100.0, 100234.0, -1.0};
    NaturalNumbers natural_numbers{1, 2, 100, 100234, 1};
    // if (words.empty()) {
    //     std::println("No words in text.");
    //     return 0;
    // }

    // sort(words);        // Sort the words
    // print_words(words); // Output the words
    print_words<10>(real_numbers); // Output the words

    sort(real_numbers);            // Sort the words
    print_words<10>(real_numbers); // Output the words

    print_words<10>(natural_numbers);
    sort(natural_numbers);
    print_words<10>(natural_numbers);
}

template <typename T>
T extract_words(const std::string& text, const std::string& separators) {
    T words;

    std::size_t start{text.find_first_not_of(separators)}; // Start index of first word
    while (start != std::string::npos) {
        std::size_t end{text.find_first_of(separators, start + 1)}; // Find end of a word
        if (end == std::string::npos)                               // Found a separator?
            end = text.length();                                    // No, so set to end of text
        words.push_back(std::make_shared<std::string>(text.substr(start, end - start)));
        start = text.find_first_not_of(separators, end + 1); // Find start next word
    }

    return words;
}
template <typename T>
void swap(T& words, std::size_t first, std::size_t second) {
    auto temp{words[first]};
    words[first] = words[second];
    words[second] = temp;
}

// Sort strings in ascending sequence
template <typename T>
void sort(T& words) {
    if (!words.empty())
        sort(words, 0, words.size() - 1);
}

template <typename T>
void sort(T& words, std::size_t start, std::size_t end) {
    // start index must be less than end index for 2 or more elements
    if (!(start < end))
        return;

    // Choose middle address to partition set
    swap(words, start, (start + end) / 2); // Swap middle address with start

    std::size_t current{start};
    if constexpr (std::is_pointer_v<T>) {
        // Check words against chosen word
        for (std::size_t i{start + 1}; i <= end; i++) {
            if (*words[i] < *words[start]) // Is word less than chosen word?
                swap(words, ++current, i); // Yes, so swap to the left
        }
    } else {
        // Check words against chosen word
        for (std::size_t i{start + 1}; i <= end; i++) {
            if (words[i] < words[start])   // Is word less than chosen word?
                swap(words, ++current, i); // Yes, so swap to the left
        }
    }

    swap(words, start, current); // Swap chosen and last swapped words

    if (current > start)
        sort(words, start, current - 1); // Sort left subset if exists
    if (end > current + 1)
        sort(words, current + 1, end); // Sort right subset if exists
}
template <typename T>
std::size_t max_word_length(const T& words) {
    std::size_t max{};
    for (auto& pword : words)
        if (max < pword->length())
            max = pword->length();
    return max;
}

template <typename T>
void print_words(const T& words) {
    const std::size_t field_width{max_word_length(words) + 1};
    const std::size_t words_per_line{8};
    std::print("{:{}}", *words[0], field_width); // Output first word

    std::size_t words_in_line{}; // Number of words in current line
    for (std::size_t i{1}; i < words.size();
         ++i) { // Output newline when initial letter changes or after 8 per line
        if ((*words[i])[0] != (*words[i - 1])[0] || ++words_in_line == words_per_line) {
            words_in_line = 0;
            std::println("");
        }
        std::print("{:{}}", *words[i], field_width); // Output a word
    }
    std::println("");
}
