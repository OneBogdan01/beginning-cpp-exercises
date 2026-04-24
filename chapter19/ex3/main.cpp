#include "pch.hpp"

using Words = std::vector<std::shared_ptr<std::string>>;
using RealNumbers = std::vector<f64>;
using NaturalNumbers = std::vector<uint64_t>;

template <typename T>
void swap(T& words, std::size_t first, std::size_t second);

template <typename T, typename Comparison>
void sort(T& words, Comparison cmp);

template <typename T, typename Comparison>
void sort(T& words, std::size_t start, std::size_t end, Comparison cmp);

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

template <typename T, typename Comparison>
void slow_sort(T& words, size_t count, Comparison cmp) {
    while (true) {
        bool swapped{false}; // Becomes true when not all values are in order
        for (std::size_t i{}; i < count - 1; ++i) {
            if (cmp(words[i], words[i + 1])) // Out of order so swap them
            {
                const auto temp{words[i]};
                words[i] = words[i + 1];
                words[i + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) // If there were no swaps
            break;    // ...all values are in order...
    }
}
int main() {
    // it seems that the quicksort is getting worse with higher numbers
    //  our functor
    size_t count{0};
    auto count_sort{[&count](int a, int b) {
        ++count;
        return a > b;
    }};

    std::vector<int> random_numbers;
    srand(time(nullptr));
    for (auto counts : {500, 1000, 2000, 4000}) {
        random_numbers.clear();
        for (size_t i{0}; i < counts; ++i) {
            random_numbers.push_back(rand() % 100 + 1);
        }
        std::println("This is with count {}", counts);
        auto copy{random_numbers};
        slow_sort(random_numbers, random_numbers.size(), count_sort);
        std::println("Slow sort has {}", count);
        auto bubble_sort_count{count};

        count = 0;
        sort(copy, count_sort);
        auto quicksort_count{count};

        std::println("Fast sort has {}", count);
        const auto quick_sort = static_cast<unsigned>(counts * std::log2(counts));
        const auto bubble_sort = counts * counts;

        std::println("Number of comparisons for {} elements:\n"
                     " - quicksort: {} (n*log(n): {}; ratio: {:.2})\n"
                     " - bubble sort: {} (n*n: {}; ratio: {:.2})\n",
                     counts, quicksort_count, quick_sort,
                     static_cast<float>(quicksort_count) / quick_sort, bubble_sort_count,
                     bubble_sort, static_cast<float>(bubble_sort_count) / bubble_sort);
    }
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
template <typename T, typename Comparison>
void sort(T& words, Comparison cmp) {
    if (!words.empty())
        sort(words, 0, words.size() - 1, cmp);
}

template <typename T, typename Comparison>
void sort(T& words, std::size_t start, std::size_t end, Comparison cmp) {
    // start index must be less than end index for 2 or more elements
    if (!(start < end))
        return;

    // Choose middle address to partition set
    swap(words, start, (start + end) / 2); // Swap middle address with start

    std::size_t current{start};

    // Check words against chosen word
    for (std::size_t i{start + 1}; i <= end; i++) {
        if (cmp(words[i], words[start])) // Is word less than chosen word?
            swap(words, ++current, i);   // Yes, so swap to the left
    }

    swap(words, start, current); // Swap chosen and last swapped words

    if (current > start)
        sort(words, start, current - 1, cmp); // Sort left subset if exists
    if (end > current + 1)
        sort(words, current + 1, end, cmp); // Sort right subset if exists
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
