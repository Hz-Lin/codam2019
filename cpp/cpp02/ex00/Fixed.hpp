/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:50:18 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/12 14:50:19 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& original);
	~Fixed();
	Fixed&	operator=(Fixed const& original);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int					_fixedPointValue;
	static const int	_fractionalBits;
};


#endif //FIXED_HPP
