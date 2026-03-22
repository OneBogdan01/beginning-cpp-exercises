

#include <format>
#include <memory>
#include <print>
#include <string>
#include <vector>
class Animal {
  public:
    Animal(std::string name, int weight) : m_name(name), m_weight(weight) {}
    std::string who() {
        return std::format("Animal name is {}, weights {} pounds.", get_name(), get_weight());
    }
    virtual std::string get_name() {
        return m_name;
    }
    virtual std::string get_weight() {
        return std::to_string(m_weight);
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

    std::string get_name() override {
        return "Wolly " + Animal::get_name();
    }
    std::string get_weight() override {
        return std::to_string(m_weight - m_wool_wight);
    }
    std::string sound() override {
        return std::format("Beeee");
    }
    int shear() {
        m_weight -= m_wool_wight;
        m_wool_wight = 0;
        return m_weight;
    }

  private:
    int m_wool_wight;
};

class Cow : public Animal {
  public:
    using Animal::Animal;
    std::string get_weight() override {
        return "secret!";
    }
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
    std::vector<Sheep*> herd() {
        std::vector<Sheep*> sheeps;
        for (auto animal : animals) {
            //     if (typeid(*animal) == typeid(Sheep)) {
            //         sheeps.push_back((Sheep*) animal.get());
            //     }
            if (dynamic_cast<Sheep*>(animal.get())) {
                sheeps.push_back((Sheep*) animal.get());
            }
        }
        return sheeps;
    }
    std::vector<std::shared_ptr<Animal>> animals;
};
