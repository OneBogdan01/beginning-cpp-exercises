

#include <format>
#include <memory>
#include <print>
#include <string>
#include <vector>
class Animal {
  public:
    Animal(std::string name, int weight) : m_name(name), m_weight(weight) {}
    virtual std::string who() {
        return std::format("Animal name is {}, weights {} pounds.", m_name, m_weight);
    }
    virtual std::string sound() = 0;

  protected:
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
    Sheep(std::string name, int weight) : Animal(name, weight), m_wool_wight(0.1 * m_weight) {}

    std::string who() override {
        return std::format("Animal name is Wolly{}, weights {} pounds.", m_name,
                           m_weight - m_wool_wight);
    }

    std::string sound() override {
        return std::format("Beeee");
    }

  private:
    int m_wool_wight;
};

class Cow : public Animal {
  public:
    std::string who() override {
        return std::format("Animal name is {}, the weight is a secret!.", m_name);
    }
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
