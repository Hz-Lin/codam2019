/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:52:03 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/12 14:52:04 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main() {
	std::cout << std::endl << "testing clockwise triangle" << std::endl;
	bool inTri = bsp(Point(0,0), Point(0,6.5), Point(6.6,0), Point(3,3.5));
	std::cout << "Point inside triangle: " << inTri << std::endl;

	bool outTri = bsp(Point(0,0), Point(0,6.5), Point(6.6,0), Point(7,3.5));
	std::cout << "Point outside triangle: " << outTri << std::endl;

	bool onTri = bsp(Point(0,0), Point(0,6.5), Point(6.6,0), Point(0,3.5));
	std::cout << "Point on the line of triangle: " << onTri << std::endl;

	std::cout << std::endl << "testing anti-clockwise triangle" << std::endl;
	inTri = bsp(Point(0,0), Point(6.6,0), Point(0,6.5), Point(3,3.5));
	std::cout << "Point inside triangle: " << inTri << std::endl;

	outTri = bsp(Point(0,0), Point(6.6,0), Point(0,6.5), Point(7,3.5));
	std::cout << "Point outside triangle: " << outTri << std::endl;

	onTri = bsp(Point(0,0), Point(6.6,0), Point(0,6.5), Point(0,3.5));
	std::cout << "Point on the line of triangle: "  << onTri << std::endl;

	return 0;
}
