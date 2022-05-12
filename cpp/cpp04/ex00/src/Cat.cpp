/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:50:17 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:50:20 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << BLUE "Cat has been created by default constructor" RESET << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj.getType()) {
	std::cout << BLUE "Cat has been copied" RESET << std::endl;
}

Cat::~Cat() {
	std::cout << RED "Cat has left this realm" RESET << std::endl;
}

Cat &Cat::operator=(const Cat &obj) {
	std::cout << BLUE "This cat has been converted" RESET << std::endl;
	if (this != &obj) {
		_type = obj._type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << MAGENTA "Meow Meow" RESET << std::endl;
}
