#pragma once

#include <string>
class Animal {
  public:
    Animal(std::string name, int weight);

    void who();

  private:
    std::string m_name;
    int m_weight;
};

class Lion : public Animal {
  public:
    void who();
};
class Aardvark : public Animal {
  public:
    void who();
};
