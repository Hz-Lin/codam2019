/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:50:41 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/13 11:18:49 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_fixedPointValue = 0;
}

// convert fixed point number: https://www.youtube.com/watch?v=S12qx1DwjVk

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = std::roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& original) {
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &original) {
	std::cout << "Copy assignation operator called" << std::endl;
	if (this == &original) {
		return *this;
	}
	_fixedPointValue = original.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	return _fixedPointValue;
}

void Fixed::setRawBits(const int raw) {
	_fixedPointValue = raw;
}

int Fixed::toInt() const {
	int value = _fixedPointValue >> _fractionalBits;
	return value;
}

float Fixed::toFloat() const {
	float value = (float )_fixedPointValue / (1 << _fractionalBits);
	return value;
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed) {
	float value = fixed.toFloat();
	stream << value;
	return stream;
}
