#include "pch.hpp"

#include <algorithm>

void print_numbers(const std::array<u32, 5>& numbers) {
    for (u32 number : numbers) {
        std::print("{} ", number);
    }
    std::println("");
}
std::array<u32, 5> highest_grades(const std::vector<u32>& vector) {
    std::array<u32, 5> grades;
    i32 index{0};
    std::copy_n(vector.rbegin(), 5, grades.begin());

    return grades;
}
std::array<u32, 5> lowest_grades(const std::vector<u32>& vector) {
    std::array<u32, 5> grades;
    std::copy_n(vector.begin(), 5, grades.begin());
    return grades;
}
u32 average(const std::vector<u32>& vector) {
    u32 sum{0};
    for (u32 grade : vector) {
        sum += grade;
    }
    return sum / vector.size();
}
void print_median(const std::vector<u32>& vector) {
    if (vector.size() % 2 == 1) {
        std::println("Mean value is:{}", vector[vector.size() / 2]);
        return;
    }
    auto size = vector.size();
    auto mean_middle_values = (vector[size / 2] + vector[size / 2 - 1]) / 2;
    std::println("Median value is:{}", mean_middle_values);
}
u32 variance(const std::vector<u32>& vector) {
    auto avg = average(vector);

    u32 sum{0};
    for (u32 grade : vector) {
        i32 dif = grade - avg;
        sum += dif * dif;
    }
    sum /= vector.size();
    return sum;
}
int main() {
    std::vector<u32> input_grades;

    i32 grade_input;
    do {
        std::cin >> grade_input;

        if (grade_input <= 100 && grade_input >= 0)
            input_grades.emplace_back(grade_input);

    } while (grade_input >= 0);

    if (input_grades.size() < 5) {
        return 0;
    }
    std::ranges::sort(input_grades);

    std::array<u32, 5> highest{highest_grades(input_grades)};
    std::array<u32, 5> lowest{lowest_grades(input_grades)};
    print_numbers(highest);
    print_numbers(lowest);

    std::println("Average is:{}", average(input_grades));
    print_median(input_grades);
    auto standard_derivation = variance(input_grades);
    std::println("Variance is:{}", standard_derivation);
    std::println("Standard derivation is:{}", sqrt(standard_derivation));
}
