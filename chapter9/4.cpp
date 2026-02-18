#include "pch.hpp"

// Function prototypes
std::optional<double> largest(std::span<const double> data);
std::optional<int> largest(std::span<const int> data);
std::optional<std::string> largest(std::span<const std::string> words);

/* The following function overload would not compile:
   overloaded functions must differ in more than just their return type! */
// int largest(const std::vector<std::string>& words);

int main() {
    double array[]{1.5, 44.6, 13.7, 21.2, 6.7};
    std::vector<int> numbers{15, 44, 13, 21, 6, 8, 5, 2};
    std::vector<double> data{3.5, 5, 6, -1.2, 8.7, 6.4};
    std::vector<std::string> names{"Charles Dickens", "Emily Bronte", "Jane Austen", "Henry James",
                                   "Arthur Miller"};
    std::println("The largest of array is {}", largest(array).value());
    std::println("The largest of numbers is {}", largest(numbers).value());
    std::println("The largest of data is {}", largest(data).value());
    std::println("The largest of names is {}", largest(names).value());
}

// Finds the largest of an array of double values
std::optional<double> largest(std::span<const double> data) {
    if (data.empty()) {
        return {};
    }
    double max{data[0]};
    for (std::size_t i{1}; i < data.size(); ++i)
        if (max < data[i])
            max = data[i];
    return max;
}

// Finds the largest of a vector of int values
std::optional<int> largest(std::span<const int> data) {
    if (data.empty()) {
        return {};
    }

    int max{data[0]};
    for (auto value : data)
        if (max < value)
            max = value;
    return max;
}

// Finds the largest of a vector of string objects
std::optional<std::string> largest(std::span<const std::string> words) {
    if (words.empty()) {
        return {};
    }
    std::string max_word{words[0]};
    for (const auto& word : words)
        if (max_word < word)
            max_word = word;
    return max_word;
}
