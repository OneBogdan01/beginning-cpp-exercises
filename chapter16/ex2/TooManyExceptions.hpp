#pragma once

#include <exception>
class TooManyExceptions : public std::exception {
  public:
    const char* what() const override {
        return "Too TooManyExceptions";
    }
};
