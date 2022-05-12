/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:53:44 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:53:46 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	_brain = new Brain();
	std::cout << BLUE "Dog has been created by default constructor" RESET << std::endl;
}

// Deep copy: an object is created by copying data of all variables,
// and it also allocates similar memory resources with the same value to the object
// In order to perform Deep copy, we need to explicitly define the copy constructor
// and assign dynamic memory as well if required.

Dog::Dog(const Dog &obj) : Animal(obj.getType()) {
	_brain = new Brain();
	*_brain = *obj._brain;
	std::cout << BLUE "Dog has been copied" RESET << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << RED "Dog has left this realm" RESET << std::endl;
}

Dog &Dog::operator=(const Dog &obj) {
	std::cout << BLUE "This dog has been converted" RESET << std::endl;
	if (this != &obj) {
		_type = obj._type;
		*_brain = *obj._brain;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << MAGENTA "Woof Woof" RESET << std::endl;
}

Brain *Dog::getBrain() const {
	return _brain;
}
