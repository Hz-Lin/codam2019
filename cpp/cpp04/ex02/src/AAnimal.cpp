/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:55:21 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:55:22 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << BLUE "AAnimal has been created by default constructor" RESET << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << BLUE "AAnimal has been created with a type" RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj) : _type(obj._type) {
	std::cout << BLUE "AAnimal has been copied" RESET << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << RED "AAnimal has left this realm" RESET << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &obj) {
	std::cout << BLUE "This animal has been converted" RESET << std::endl;
	if (this != &obj) {
		_type = obj._type;
	}
	return *this;
}

const std::string &AAnimal::getType() const {
	return _type;
}
