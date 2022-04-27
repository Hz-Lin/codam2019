/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:51:56 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/12 14:51:57 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& original);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed&	operator=(Fixed const& original);

	bool	operator>(Fixed const& rhs) const;
	bool	operator<(Fixed const& rhs) const;
	bool	operator>=(Fixed const& rhs) const;
	bool	operator<=(Fixed const& rhs) const;
	bool	operator==(Fixed const& rhs) const;
	bool	operator!=(Fixed const& rhs) const;

	Fixed	operator+(Fixed const& rhs) const;
	Fixed	operator-(Fixed const& rhs) const;
	Fixed	operator*(Fixed const& rhs) const;
	Fixed	operator/(Fixed const& rhs) const;

	Fixed&	operator++(); //prefix
	Fixed	operator++(int); //postfix
	Fixed&	operator--(); //prefix
	Fixed	operator--(int); //postfix

	static Fixed&	min(Fixed& fixedNum1, Fixed& fixedNum2);
	static Fixed const&	min(Fixed const& fixedNum1, Fixed const& fixedNum2);
	static Fixed&	max(Fixed& fixedNum1, Fixed& fixedNum2);
	static Fixed const&	max(Fixed const& fixedNum1, Fixed const& fixedNum2);

private:
	int					_fixedPointValue;
	static const int	_fractionalBits;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif //FIXED_HPP
