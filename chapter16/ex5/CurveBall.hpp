#pragma once

#include <exception>
#include <stdexcept>
class CurveBall : public std::exception {
  public:
    const char* what() const override {
        return "Cruve ball exception";
    }
};
class NegativeNumber : public std::domain_error {
  public:
    NegativeNumber(const std::string& nan) : std::domain_error{"NegativeNumber" + nan} {}
};

class NotANumber : public std::domain_error {
  public:
    NotANumber(const std::string& nan) : std::domain_error{"nan" + nan} {}
};
class OddNumber : public std::domain_error {
  public:
    OddNumber(const std::string& nan) : std::domain_error{"OddNumber" + nan} {}
};
