/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:57:54 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:57:55 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure &obj) : AMateria(obj) {
}

Cure::~Cure() {
}

Cure &Cure::operator=(const Cure &) {
	return *this;
}

AMateria *Cure::clone() const {
	AMateria *clone = new Cure(*this);
	return clone;
}

void Cure::use(ICharacter &target) {
	std::cout << BLUE "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
}
