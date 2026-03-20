#pragma once

#include <string>
class Person {
  public:
    Person(std::string name, int weight);

  protected:
    void who();

  private:
    std::string m_name;
    int m_weight;
};

class Lion : public Person {
  public:
    using Person::who;
};
class Aardvark : public Person {
  public:
    using Person::who;
};
