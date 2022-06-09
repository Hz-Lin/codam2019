/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 10:40:03 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/09 10:40:04 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
#define CONVERSION_HPP

# define RED "\033[1;31m"
# define RESET "\033[m"

#include <iostream>

class Conversion {
public:
    // Explicit Keyword is used to mark constructors to not implicitly convert types
    explicit Conversion(std::string input);
    ~Conversion();
    Conversion(Conversion const &obj);
    Conversion &operator=(Conversion const &obj);

    std::string getInput();

    bool checkInputType();

    void outputConversion();

private:
    std::string _input;

    bool isChar();
    bool isInt();
    bool isFloat();
    bool isDouble();

    bool isSpecialValue();
    void outputSpecial();
    void outputChar(std::string input);
    void outputNum(std::string input);
};


#endif //CONVERSION_HPP
