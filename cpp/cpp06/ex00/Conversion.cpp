/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 10:39:49 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/09 10:39:55 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <string>
#include <cfloat>
#include <sstream> // istringstream
#include <iomanip> // setprecision

Conversion::Conversion(std::string input) : _input(input) {
}

Conversion::~Conversion() {
}

Conversion::Conversion(const Conversion &obj) {
    *this = obj;
}

Conversion &Conversion::operator=(const Conversion &obj) {
    if (this != &obj) {
        _input = obj._input;
    }
    return *this;
}

std::string Conversion::getInput() {
    return _input;
}

bool Conversion::isChar() {
    if (_input.length() == 1) {
        if (!isprint(_input.c_str()[0])) {
            std::cout << RED << "Do not process non-displayable char" << RESET << std::endl;
            return false;
        }
        return true;
    }
    return false;
}

bool Conversion::isInt() {
    size_t i = 0;
    if (_input.c_str()[i] == '+' || _input.c_str()[i] == '-') {
        i++;
    }
    while (i < _input.length()) {
        if (isdigit(_input.c_str()[i])) {
            i++;
        }
        else {
            return false;
        }
    }
    return true;
}

bool Conversion::isFloat() {
    if (_input == "-inff" || _input == "+inff" || _input == "nanf") {
        return true;
    }
    if (_input.c_str()[_input.length() - 1] != 'f') {
        return false;
    }
    size_t i = 0;
    size_t dotCount = 0;
    if (_input.c_str()[i] == '+' || _input.c_str()[i] == '-') {
        i++;
    }
    while (i < _input.length()) {
        if (_input.c_str()[i] == '.' && isdigit(_input.c_str()[i+1])) {
            i++;
            dotCount++;
        }
        else if (isdigit(_input.c_str()[i]) || (_input.c_str()[i] == 'f' && _input.c_str()[i+1] == '\0')) {
            i++;
        }
        else {
            return false;
        }
    }
    if (dotCount == 1 || dotCount == 0) {
        return true;
    }
    return false;
}

bool Conversion::isDouble() {
    if (_input == "-inf" || _input == "+inf" || _input == "nan") {
        return true;
    }
    size_t i = 0;
    size_t dotCount = 0;
    if (_input.c_str()[i] == '+' || _input.c_str()[i] == '-') {
        i++;
    }
    while (i < _input.length()) {
        if (_input.c_str()[i] == '.' && isdigit(_input.c_str()[i+1])) {
            i++;
            dotCount++;
        }
        else if (isdigit(_input.c_str()[i])) {
            i++;
        }
        else {
            return false;
        }
    }
    if (dotCount == 1) {
        return true;
    }
    return false;
}

bool Conversion::isSpecialValue() {
    std::string special[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    for (int i = 0; i < 6; i++) {
        if (_input == special[i]) {
            return true;
        }
    }
    return false;
}

void Conversion::outputSpecial() {
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    if (_input == "-inf" || _input == "+inf" || _input == "nan") {
        std::cout << "float: " << _input << "f" << std::endl;
    }
    else {
        std::cout << "float: " << _input << std::endl;
    }
    if (_input == "-inff" || _input == "+inff" || _input == "nanf") {
        std::cout << "double: " << _input.substr(0, _input.size() - 1) << std::endl;
    }
    else {
        std::cout << "double: " << _input << std::endl;
    }
}

// fixed: write floating-point values in fixed-point notation.
// setprecision: sets the decimal precision to be used to format floating-point values.
void Conversion::outputChar(std::string input) {
    char c = input[0];
    if (!std::isdigit(c) && std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else if (std::isdigit(c)) {
        outputNum(input);
        return;
    }
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(c) << std::endl;
}

// The std::stringstream acts just like std::cin but instead of getting the input from the user, you load it into the stream with a std::string

void Conversion::outputNum(std::string input) {
    std::istringstream ss(input);
    double res;
    ss >> res;

    if (res > 31 && res < 127)
        std::cout << "char: '" << static_cast<char>(res) << "'" << std::endl;
    else if (res >= 0 && res < 32) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    if (res > INT_MAX || res < INT_MIN) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(res) << std::endl;
    }
    if (res > FLT_MAX || res < -FLT_MAX) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(res) << "f" << std::endl;
    }
    if (res > DBL_MAX || res < -DBL_MAX) {
        std::cout << "double: impossible" << std::endl;
    } else {
        std::cout << "double: " << std::setprecision(1) << std::fixed << res << std::endl;
    }
}

bool Conversion::checkInputType() {
    if (!isInt() && !isFloat() && !isDouble() && !isChar()) {
        return false;
    }
    else {
        return true;
    }
}

void Conversion::outputConversion() {
    if (isSpecialValue()) {
        outputSpecial();
        return;
    }
    std::string temp = _input;
    if (_input.length() == 1) {
        outputChar(temp);
        return;
    }
    if (_input[_input.length() - 1] == 'f') {
        temp = _input.substr(0, _input.length() - 1);
    }
    outputNum(temp);
}
