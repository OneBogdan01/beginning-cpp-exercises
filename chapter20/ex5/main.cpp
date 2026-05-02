#include <algorithm>
#include <numeric>
#include <print>
#include <vector>

double compute_average(auto begin, auto end) {
    auto count{std::distance(begin, end)};
    auto sum{std::accumulate(begin, end, 0.0)};
    return sum / count;
}
int main() {
    std::vector<double> numbers{1, 2, 3, 4, 5};
    std::println("{}", compute_average(std::begin(numbers), std::end(numbers)));
}