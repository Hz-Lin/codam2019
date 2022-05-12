/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:55:39 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:55:40 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	_brain = new Brain();
	std::cout << BLUE "Cat has been created by default constructor" RESET << std::endl;
}

// Deep copy: an object is created by copying data of all variables,
// and it also allocates similar memory resources with the same value to the object
// In order to perform Deep copy, we need to explicitly define the copy constructor
// and assign dynamic memory as well if required.

Cat::Cat(const Cat &obj) : AAnimal(obj.getType()) {
	_brain = new Brain();
	*_brain = *(obj._brain);
	std::cout << BLUE "Cat has been copied" RESET << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << RED "Cat has left this realm" RESET << std::endl;
}

Cat &Cat::operator=(const Cat &obj) {
	std::cout << BLUE "This cat has been converted" RESET << std::endl;
	if (this != &obj) {
		_type = obj._type;
		*_brain = *obj._brain;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << MAGENTA "Meow Meow" RESET << std::endl;
}

Brain *Cat::getBrain() const {
	return _brain;
}
