/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:50:24 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:50:26 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << BLUE "Dog has been created by default constructor" RESET << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj.getType()) {
	std::cout << BLUE "Dog has been copied" RESET << std::endl;
}

Dog::~Dog() {
	std::cout << RED "Dog has left this realm" RESET << std::endl;
}

Dog &Dog::operator=(const Dog &obj) {
	std::cout << BLUE "This dog has been converted" RESET << std::endl;
	if (this != &obj) {
		_type = obj._type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << MAGENTA "Woof Woof" RESET << std::endl;
}
