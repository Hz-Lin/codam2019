/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 11:36:23 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/15 10:48:56 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void intTest() {
    std::cout << std::endl;
    std::cout << BLUE "*** INT ***" << RESET << std::endl;
    int a = 2;
    int b = 3;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap( a, b );
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

void stringTest() {
    std::cout << std::endl;
    std::cout << BLUE "*** STRING ***" <<RESET << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void doubleTest() {
    std::cout << std::endl;
    std::cout << BLUE "*** DOUBLE ***" << RESET << std::endl;
    double f = 24.24;
    double g = -42.42;
    std::cout << "Before swap: f = " << f << ", g = " << g << std::endl;
    ::swap(f, g);
    std::cout << "After swap:  f = " << f << ", g = " << g << std::endl;
    std::cout << "min( f, g ) = " << ::min(f, g) << std::endl;
    std::cout << "max( f, g ) = " << ::max(f, g) << std::endl;
}

void charTest() {
    std::cout << std::endl;
    std::cout << BLUE "*** CHAR ***" << RESET << std::endl;
    char j = 'A';
    char k = 'M';
    std::cout << "Before swap: j = " << j << ", k = " << k << std::endl;
    ::swap(j, k);
    std::cout << "After swap:  f = " << j << ", g = " << k << std::endl;
    std::cout << "min( f, g ) = " << ::min(j, k) << std::endl;
    std::cout << "max( f, g ) = " << ::max(j, k) << std::endl;
}

/*
void classTest() {
	std::cout << std::endl;
    std::cout << BLUE "*** CLASS ***" << RESET << std::endl;
	Awesome a1(3), a2(4);
	std::cout << "Before swap: a1 = " << a1 << ", a2 = " << a2 << std::endl;
	::swap(a1, a2);
	std::cout << "After swap:  a1 = " << a1 << ", a2 = " << a2 << std::endl;
	std::cout << max(a1, a2) << std::endl;
	std::cout << min(a1, a2) << std::endl;
}
*/

int main() {
    intTest();
    stringTest();
    doubleTest();
    charTest();
	// classTest();
    return 0;
}
