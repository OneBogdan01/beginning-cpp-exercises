#pragma once

#include <cstdint>
#include <string>
class Person {
  public:
    Person(std::string name, uint32_t age, std::string gender)
        : m_name(name), m_age(age), m_gender(gender) {}

    void who() const;

  protected:
    std::string get_name() const {
        return m_name;
    }
    std::string get_gender() const {
        return m_gender;
    }

    uint32_t get_age() const {
        return m_age;
    }
    void increase_age(uint32_t years) {
        m_age += years;
    }

  private:
    std::string m_name;
    uint32_t m_age;
    std::string m_gender;
};
class Employee : public Person {
  public:
    Employee(uint32_t age, std::string name, std::string gender, uint32_t id)
        : Person(name, age, gender), m_id(id) {}

    void who() const;

  private:
    uint32_t m_id;
};
class Executive : public Employee {
  public:
    using Employee::Employee;
    void who() const;
};
