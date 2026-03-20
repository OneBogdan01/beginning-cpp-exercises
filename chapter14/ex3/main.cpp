#include "Animal.hpp"

int main() {
    Lion lion{{"Leo", 400}};
    Aardvark ardi{{"algemenon", 50}};
    lion.who();
    Person* base{&lion};
    base->who();
    base = &ardi;
    ardi.who();
    base->who();
}
