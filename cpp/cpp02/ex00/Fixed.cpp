/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:50:07 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/13 10:58:16 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_fixedPointValue = 0;
}

// This is a copy constructor, without it only the addresses for pointers will be copied - not what they point to.
// Then there will be two or more objects with members pointing to the same object. So change to an object may affect all the duplicate objects
Fixed::Fixed(const Fixed& original) {
	std::cout << "Copy constructor called" << std::endl;
//	_fixedPointValue = original.getRawBits();
	*this = original; // this implementation will call the copy assignment operator
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &original) {
	std::cout << "Copy assignation operator called" << std::endl;
	// to avoid self assignment
	if (this == &original) {
		return *this;
	}
	_fixedPointValue = original.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}
