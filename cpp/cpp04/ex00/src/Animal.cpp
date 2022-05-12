/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:50:10 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:50:13 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << BLUE "Animal has been created by default constructor" RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << BLUE "Animal has been created with a type" RESET << std::endl;
}

Animal::Animal(const Animal &obj) : _type(obj._type) {
	std::cout << BLUE "Animal has been copied" RESET << std::endl;
}

Animal::~Animal() {
	std::cout << RED "Animal has left this realm" RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &obj) {
	std::cout << BLUE "This animal has been converted" RESET << std::endl;
	if (this != &obj) {
		_type = obj._type;
	}
	return *this;
}

const std::string &Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << MAGENTA "Generic animal noises" RESET << std::endl;
}
