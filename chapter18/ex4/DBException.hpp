// A simple C++ exception type

#include <stdexcept>
class DatabaseException : public std::runtime_error {
  public:
    using std::runtime_error::runtime_error; // Inherit constructor
};
