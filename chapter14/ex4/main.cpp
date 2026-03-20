#include "Person.hpp"
#include <vector>

int main() {
    std::vector<Employee> employees
        // used the examples from the book
        {

            Employee{21, "Randy Marathon", "Male", 34567},

            Employee{32, "Anna Pothecary", "Female", 34578},

            Employee{46, "Peter Out", "Male", 34589},

            Employee{37, "Sheila Rangeit", "Female", 34598},

            Employee{65, "Jack Ittin", "Male", 34667}

        };

    for (const auto& employee : employees) {
        employee.Person::who();
        employee.who();
    }

    std::vector<Executive> executives

        {

            {44, "Irwin Pootlemeyer", "Male", 35567},

            {32, "Alexa Workwell", "Female", 35578},

            {42, "Steve Stove", "Other", 35589},

            {33, "Sue Neenuf", "Female", 35598},

            {29, "Melanie Clair", "Female", 35667}

        };
    for (const auto& employee : executives) {
        employee.who();
    }
}
