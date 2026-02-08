
#include "pch.hpp"

int plus(int a, int b) {
    return a + b;
}
double plus(double a, double b) {
    return a + b;
}
using std::string;
string plus(const string& a, const string& b) {
    return a + b;
}
int main() {
    const int n{plus(3, 4)};
    const double d{plus(3.2, 4.2)};
    const string s{plus("he", "llo")};
    const string s1{"aaa"};
    const string s2{"bbb"};
    const string s3{plus(s1, s2)};
    // compiler does not which overload to use, double or int.
    // const auto x{plus(3, 4.2)};
}
