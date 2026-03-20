#include "Animal.hpp"
#include <print>
void Animal::who() {
    std::println("Animal name is {}, and weight in pounds {}", m_name, m_weight);
}
Animal::Animal(std::string name, int weight) : m_name(name), m_weight(weight) {}
