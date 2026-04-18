#include <exception>
#include <print>
#include <string>
#include <stacktrace>
// exercise 18-6. to conclude, look back at the constructors of the Trouble and
// TracingException exception classes from Chapter 16. notice anything suboptimal?
// how would you improve TracingException knowing what you know now? Give it a try.
// hypothetically, what could still go wrong, and how could you fix it?

class TracingException : public std::exception {
  public:
    TracingException(std::string_view message,
                     std::stacktrace trace = std::stacktrace::current()) //<-- Magic happens here!
        : m_message{message}, m_trace{std::move(trace)} {}
    const char* what() const noexcept override {
        return m_message.c_str();
    }
    const auto& where() const noexcept {
        return m_trace;
    }

  private:
    std::string m_message;
    std::stacktrace m_trace;
};
int f3() {
    throw TracingException{"Something's amiss!"};
} // Obtains a stack trace!
int f2() {
    return f3();
}
int f1() {
    return f2();
}
int main() {
    try {
        f1();
    } catch (const TracingException& ex) {
        std::println("Exception of type {} caught: {}; trace:\n{}", typeid(ex).name(), ex.what(),
                     ex.where());
    }
}
