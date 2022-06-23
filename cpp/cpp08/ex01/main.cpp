/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:32:42 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/20 22:32:45 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm> // std::generate

void subjectTest() {
	std::cout << BLUE "*** Subject Test ***" RESET << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void exceptionTest() {
    Span sp = Span(3);

    std::cout << std::endl;
    std::cout << BLUE "*** No Element ***" RESET << std::endl;
    try {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    sp.addNumber(6);
    std::cout << std::endl;
    std::cout << BLUE "*** One Element ***" RESET << std::endl;
    try {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    sp.addNumber(3);
    sp.addNumber(9);
    std::cout << std::endl;
    std::cout << BLUE "*** Maximum Storage ***" RESET << std::endl;
    try {
        sp.addNumber(7);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

// for generating random numbers
int randomNumber() {
    return (std::rand() % 1000000000 + 1); // generate in the range 1 to 1000000000
}

void largeNumTest() {
    std::cout << std::endl;
    std::cout << BLUE "*** Large Number Test ***" RESET << std::endl;
    Span spLarge1 = Span(15000);
    std::vector<int> vector1(15000);
    std::generate(vector1.begin(), vector1.end(), randomNumber);
    try {
        spLarge1.addNumber(vector1.begin(), vector1.end());
        std::cout << CYAN "Shortest span: " << spLarge1.shortestSpan() << RESET << std::endl;
        std::cout << CYAN "Longest span:  " << spLarge1.longestSpan() << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << BLUE "*** Large Number Test - Add Multiple vectors ***" RESET << std::endl;
    Span spLarge2 = Span(15000);
    std::vector<int> vector2(10000);
    std::generate(vector2.begin(), vector2.end(), randomNumber);
    try {
        spLarge2.addNumber(vector2.begin(), vector2.end());
        std::cout << CYAN "Shortest span: " << spLarge2.shortestSpan() << RESET << std::endl;
        std::cout << CYAN "Longest span:  " << spLarge2.longestSpan() << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::vector<int> vector3(3000);
    std::generate(vector3.begin(), vector3.end(), randomNumber);
    try {
        spLarge2.addNumber(vector3.begin(), vector3.end());
        std::cout << CYAN "Shortest span: " << spLarge2.shortestSpan() << RESET << std::endl;
        std::cout << CYAN "Longest span:  " << spLarge2.longestSpan() << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::vector<int> vector4(3000);
    std::generate(vector4.begin(), vector4.end(), randomNumber);
    try {
        spLarge2.addNumber(vector4.begin(), vector4.end());
        std::cout << CYAN "Shortest span: " << spLarge2.shortestSpan() << RESET << std::endl;
        std::cout << CYAN "Longest span:  " << spLarge2.longestSpan() << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    std::srand(std::time(NULL));
    subjectTest();
    exceptionTest();
    largeNumTest();
    return 0;
}
