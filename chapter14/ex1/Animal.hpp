#pragma once

#include <string>
class Person {
  public:
    Person(std::string name, int weight) {}
    void who();

  private:
    std::string m_name;
    int m_weight;
};

class Lion : public Person {};
class Aardvark : public Person {};
