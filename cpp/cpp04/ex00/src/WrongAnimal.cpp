/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:50:36 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:50:37 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << BLUE "Wrong animal has been created by default constructor" RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << BLUE "Wrong animal has been created with a type" RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : _type(obj._type) {
	std::cout << BLUE "Wrong animal has been copied" RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED "Wrong animal has left this realm" RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &obj) {
	std::cout << BLUE "This wrong animal has been converted" RESET << std::endl;
	if (this != &obj) {
		_type = obj._type;
	}
	return *this;
}

const std::string &WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << MAGENTA "Generic wrong animal noises" RESET << std::endl;
}
