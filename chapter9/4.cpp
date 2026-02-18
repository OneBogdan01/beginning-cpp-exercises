#include "pch.hpp"

// Function prototypes
std::optional<double> largest(const std::vector<double>& data);

int main() {
    std::vector<double> data{};

    auto value = largest(data);
    std::println("The largest of data is {}", value.value_or(-1));
}

// Finds the largest of a vector of double values
std::optional<double> largest(const std::vector<double>& data) {
    if (data.empty()) {
        return std::nullopt;
    }
    double max{data[0]};
    for (auto value : data)
        if (max < value)
            max = value;
    return max;
}
