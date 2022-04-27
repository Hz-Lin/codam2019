/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:51:25 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/12 17:50:58 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	//test in-decrement
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	//test arithmetic operators
	Fixed	c(Fixed(2.5f) + Fixed(3.3f));
	Fixed	d(Fixed(7.6f) - Fixed(6.4f));
	Fixed const	e(Fixed(1.1f) * Fixed(5));
	Fixed const f(Fixed(9.3f) / Fixed(3));

	std::cout << "Testing operator +: " << c << std::endl;
	std::cout << "Testing operator -: " << d << std::endl;
	std::cout << "Testing operator *: " << e << std::endl;
	std::cout << "Testing operator /: " << f << std::endl;

	//test comparison operators
	Fixed	cCopy(c);
	std::cout << "Created a copy of c, value is: " << cCopy << std::endl;
	std::cout << "Testing comparison operator ==: " << (c == cCopy) << std::endl;
	std::cout << "Testing comparison operator !=: " << (c != cCopy) << std::endl;
	std::cout << "Testing comparison operator >: " << (c > d) << std::endl;
	std::cout << "Testing comparison operator <: " << (c < d) << std::endl;
	std::cout << "Testing comparison operator >=: " << (c >= d) << std::endl;
	std::cout << "Testing comparison operator <=: " << (c <= d) << std::endl;

	//test min and max
	std::cout << "Testing min:         " << Fixed::min(c, d) << std::endl;
	std::cout << "Testing max:         " << Fixed::max(c, d) << std::endl;
	std::cout << "Testing min (const): " << Fixed::min(e, f) << std::endl;
	std::cout << "Testing max (const): " << Fixed::max(e, f) << std::endl;
	return 0; }
