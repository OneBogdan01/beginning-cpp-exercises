

#include <format>
#include <memory>
#include <print>
#include <string>
#include <vector>
class Animal {
  public:
    Animal(std::string name, int weight) : m_name(name), m_weight(weight) {}
    std::string who() {
        return std::format("Animal name is {}, weights {} pounds.", m_name, m_weight);
    }
    virtual std::string sound() = 0;

  private:
    std::string m_name;
    int m_weight;
};
class Dog : public Animal {
  public:
    using Animal::Animal;

    std::string sound() override {
        return std::format("Ham Ham");
    }
};
class Sheep : public Animal {
  public:
    using Animal::Animal;

    std::string sound() override {
        return std::format("Beeee");
    }
};

class Cow : public Animal {
  public:
    using Animal::Animal;
    std::string sound() override {
        return std::format("Moo");
    }
};

struct Zoo {
    void print_all_animals() {
        for (const auto& animal : animals) {
            std::println("Animal sound {}, some extra info {}", animal->sound(), animal->who());
        }
    }

    std::vector<std::shared_ptr<Animal>> animals;
};
