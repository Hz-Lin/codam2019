/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:51:40 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/13 11:43:39 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//based on: https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle

Fixed	sign(Point p1, Point p2, Point p3) {
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	signAB, signBC, signCA;

	signAB = sign(point, a, b);
	signBC = sign(point, b, c);
	signCA = sign(point, c, a);

	if ( ((signAB < 0) && (signBC < 0) && (signCA < 0)) || ((signAB > 0) && (signBC > 0) && (signCA > 0)) ) {
		return true;
	}
	return false;
}
