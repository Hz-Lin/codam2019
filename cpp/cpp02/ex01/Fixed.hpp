/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:50:47 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/13 11:01:10 by hlin          ########   odam.nl         */
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
	Fixed&	operator=(Fixed const& original);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int					_fixedPointValue;
	static const int	_fractionalBits;
};

// passing as a (const) reference to prevent unnecessary copies
// because it alter an instance of another class (ostream), have to declare this outside the Fixed class
std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif //FIXED_HPP
