/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:52:16 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/13 11:43:26 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_POINT_HPP
#define EX03_POINT_HPP

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& original);
	~Point();

	Point&	operator=(Point const& original);
	Fixed const&	getX() const;
	Fixed const&	getY() const;

private:
	Fixed const	_x;
	Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif //EX03_POINT_HPP
