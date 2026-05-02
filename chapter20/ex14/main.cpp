

#include <map>
#include <print>
#include <ranges>
#include <vector>
// Type aliases
using namespace std::views;
int main() {
    std::vector multiple_3{iota(5) | take_while([](auto x) { return x <= 50; }) |
                           filter([](auto x) { return x % 3 == 0; }) |
                           std::ranges::to<std::vector<int>>()};
    std::println("{}", multiple_3);
    // auto zip_number{zip(multiple_3, repeat(std::string{"zip zip"})) |
    //                 std::ranges::to<std::map<int, std::string>>()};
    auto map{zip(multiple_3, repeat(std::string("zip zip"))) |
             std::ranges::to<std::map<int, std::string>>()};
    std::println("{}", map);

    for (auto& [key, value] : map) {
        value = "zap zap";
    }
    for (auto& value : values(map)) {
        value = "zop";
    }
    std::println("{}", map);
}
