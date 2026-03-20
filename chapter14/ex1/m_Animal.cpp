#include "Animal.hpp"
#include <print>
void Person::who() {
    std::println("Animal name is {}, and weight in pounds {}", m_name, m_weight);
}
Person::Person(std::string name, int weight) : m_name(name), m_weight(weight) {}
