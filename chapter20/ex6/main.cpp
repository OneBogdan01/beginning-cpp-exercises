
#include <numeric>
#include <print>
#include <vector>
std::vector<int> fillVector_1toN(int N); // Fill a vector with 1, 2, ..., N
void removeEvenNumbers(auto& numbers);

int main() {
    const int num_numbers{15};

    auto numbers{fillVector_1toN(num_numbers)};

    std::println("The original set of numbers: {:n}", numbers);

    removeEvenNumbers(numbers);

    std::println("The numbers that were kept: {:n}", numbers);
}

std::vector<int> fillVector_1toN(int N) {
    std::vector<int> numbers;
    numbers.resize(N);

    std::iota(std::begin(numbers), std::end(numbers), 1);
    return numbers;
}

void removeEvenNumbers(auto& numbers) /* Correct! */
{
    for (auto iter{numbers.begin()}; iter != numbers.end();) {
        if (*iter % 2 == 0)
            iter = numbers.erase(iter);
        else
            ++iter;
    }
}