#pragma once

#include <exception>
class CurveBall : public std::exception {
  public:
    const char* what() const override {
        return "Cruve ball exception";
    }
};
