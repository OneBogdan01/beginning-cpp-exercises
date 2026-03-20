#pragma once

#include <string>
class Animal {
  public:
    Animal(std::string name, int weight);

  protected:
    void who();

  private:
    std::string m_name;
    int m_weight;
};

class Lion : public Animal {
  public:
    using Animal::who;
};
class Aardvark : public Animal {
  public:
    using Animal::who;
};
