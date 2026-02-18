#include "pch.hpp"

double average10(std::span<const double, 10> array); // Function prototype

int main() {
    std::vector<double> values{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0};
    // std::array<double,3> values{ 1.0, 2.0, 3.0 };           // Only three values!!!
    std::println("Average = {}",
                 average10(std::span<const double, 10>{values.begin(), values.end()}));
}

// Function to compute an average
double average10(std::span<const double, 10> array) {
    double sum{}; // Accumulate total in here
    for (double val : array)
        sum += val;            // Sum array elements
    return sum / array.size(); // Return average
}
