/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:50:41 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:50:42 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << BLUE "Wrong cat has been created by default constructor" RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj.getType()) {
	std::cout << BLUE "Wrong cat has been copied" RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RED "Wrong cat has left this realm" RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj) {
	std::cout << BLUE "This wrong cat has been converted" RESET << std::endl;
	if (this != &obj) {
		_type = obj._type;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << MAGENTA "Rrrr Rrrr" RESET << std::endl;
}