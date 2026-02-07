#include "pch.hpp"

int main(int argc, char* argv[]) {
    bool in_range = argc >= 2 && argc <= 4;
    if (in_range == false) {
        std::println("not enough or too many arguments");
        return 0;
    }
    for (i32 i = 0; i < argc; i++) {
        std::println("{}", argv[i]);
    }
}
