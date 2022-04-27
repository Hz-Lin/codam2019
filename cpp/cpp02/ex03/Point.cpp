/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:52:09 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/12 14:52:10 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {
}

Point::Point(const float x, const float y): _x(x), _y(y) {
}

Point::Point(const Point &original): _x(original._x), _y(original._y) {
}

Point::~Point() {
}

Point&	Point::operator=(const Point &original) {
	(void) original;
	return *this;
}

Fixed const&	Point::getX() const {
	return _x;
}

Fixed const&	Point::getY() const {
	return _y;
}
