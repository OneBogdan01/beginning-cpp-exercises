
#include "pch.hpp"

#include <iostream>
#include <utility>

u32 month();
u32 year();
std::string day(u32 month, u32 year);

u32 validate_input(u32 lower, u32 upper, const std::string& input);
int main() {
    auto month_val{month()};
    auto year_val{year()};
    auto day_val = day(month_val, year_val);

    std::string month_name{};
    switch (month_val) {
    case 1:
        month_name = "January";
        break;
    case 2:
        month_name = "February";
        break;

    case 3:
        month_name = "March";
        break;

    case 4:
        month_name = "April";
        break;

    case 5:
        month_name = "May";
        break;

    case 6:
        month_name = "June";
        break;

    case 7:
        month_name = "July";
        break;

    case 8:
        month_name = "August";
        break;

    case 9:
        month_name = "September";
        break;

    case 10:
        month_name = "October";
        break;

    case 11:
        month_name = "November";
        break;

    case 12:
        month_name = "December";
        break;
    }
    std::println("Birtday is {} of {}, {}", day_val, month_name, year_val);
}

u32 validate_input(u32 lower, u32 upper, const std::string& input) {
    std::string user_input;
    i32 input_number;
    do {
        std::println("Please enter a valid {} number ({}-{})", input, lower, upper);

        std::getline(std::cin, user_input);
        input_number = std::stoi(user_input);
    } while ((std::cmp_greater_equal(input_number, lower) &&
              std::cmp_less_equal(input_number, upper)) == false);
    return input_number;
}
u32 month() {
    return validate_input(1, 12, "month");
}

u32 year() {
    return validate_input(1582, 2026, "year");
}
std::string day(u32 month, u32 year) {
    u32 upper = 31;
    bool leap_year = false;
    if (year % 400 == 0) {
        leap_year = true;
    } else if (year % 4 == 0 && year % 100 != 0) {
        leap_year = true;
    }
    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
        upper = 30;
        break;
        // feb
    case 2:
        if (leap_year) {
            upper = 29;
        } else {
            upper = 28;
        }
        break;
    default:
        break;
    }
    // determine what day is valid based on month and year
    auto value = validate_input(1, upper, "day");
    auto str_val{std::to_string(value)};
    switch (value) {
    case 1:
        str_val += "st";
        break;
    case 2:
        str_val += "nd";
        break;
    case 3:
        str_val += "rd";
        break;
    default:
        str_val += "th";
        break;
    }
    return str_val;
}
