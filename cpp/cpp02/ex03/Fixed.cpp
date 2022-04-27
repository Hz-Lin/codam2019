/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:51:48 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/13 11:42:37 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

//constructors & destructor
Fixed::Fixed() {
	_fixedPointValue = 0;
}

Fixed::Fixed(const int value) {
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_fixedPointValue = std::roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& original) {
	*this = original;
}

Fixed::~Fixed() {
}

// getters & setters & convert member functions
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

//operator overload functions
Fixed&	Fixed::operator=(const Fixed &original) {
	if (this == &original) {
		return *this;
	}
	_fixedPointValue = original.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

//pre-increment
Fixed&	Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

//post-increment
Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	this->_fixedPointValue++;
	return tmp;
}

//pre-decrement
Fixed&	Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}

//post-decrement
Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	this->_fixedPointValue--;
	return tmp;
}

//overload min & max member functions
Fixed&	Fixed::min(Fixed &fixedNum1, Fixed &fixedNum2) {
	if (fixedNum1 < fixedNum2) {
		return fixedNum1;
	}
	return fixedNum2;
}

Fixed const&	Fixed::min(const Fixed &fixedNum1, const Fixed &fixedNum2) {
	if (fixedNum1 < fixedNum2) {
		return fixedNum1;
	}
	return fixedNum2;
}

Fixed&	Fixed::max(Fixed &fixedNum1, Fixed &fixedNum2) {
	if (fixedNum1 > fixedNum2) {
		return fixedNum1;
	}
	return fixedNum2;
}

Fixed const&	Fixed::max(const Fixed &fixedNum1, const Fixed &fixedNum2) {
	if (fixedNum1 > fixedNum2) {
		return fixedNum1;
	}
	return fixedNum2;
}

//overload of the insertion operator
std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed) {
	float value = fixed.toFloat();
	stream << value;
	return stream;
}
