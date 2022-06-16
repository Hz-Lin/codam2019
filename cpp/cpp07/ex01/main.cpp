/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 11:35:51 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/15 10:49:54 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iomanip>

// create more functions for iteration
static void dividedFloat(float const &n) {
    float res = (n / 2);
    std::cout << std::setprecision(2) << std::fixed << res << std::endl;
}

static void powerInt(int const &n) {
    std::cout << n * n << std::endl;
}

// test different data types

void charTest() {
    std::cout << std::endl;
    std::cout << BLUE << "*** CHAR ***" << RESET << std::endl;
    char chars[] = {'a', '&', 'd', 'J', '*'};
    ::iter(chars, 5, printElement<char>);
    std::cout << std::endl;
}

void stringTest() {
    std::cout << std::endl;
    std::cout << BLUE << "*** STRING ***" << RESET << std::endl;
    std::string chars[] = {"One", "ring", "to", "rule", "them", "all!"};
    ::iter(chars, 6, printElement<std::string>);
    std::cout << std::endl;
}

void intTest() {
    std::cout << std::endl;
    std::cout << BLUE << "*** INT ***" << RESET << std::endl;
    int num[] = {1,2, 3, 4, 5, 6};
    ::iter(num, 6, printElement<int>);
    std::cout << std::endl;
    ::iter(num, 6, powerInt);
    std::cout << std::endl;
}

void floatTest() {
    std::cout << std::endl;
    std::cout << BLUE << "*** FLOAT ***" << RESET << std::endl;
    float num[] = {1.2f, 9.99f, 42.7945613165f, -42.36f, 0.1f};
    ::iter(num, 5, printElement<float>);
    std::cout << std::endl;
    ::iter(num, 5, dividedFloat);
    std::cout << std::endl;
}

/*
void classTest() {
	std::cout << std::endl;
	std::cout << BLUE << "*** CLASS ***" << RESET << std::endl;
	Awesome tab1[3];
	Awesome tab2[5];
	::iter(tab1, 3, printElement);
	std::cout << std::endl;
	::iter(tab2, 5, printElement);
	std::cout << std::endl;
}
*/

int main() {
    charTest();
    stringTest();
    intTest();
    floatTest();
	// classTest();
    return 0;
}
