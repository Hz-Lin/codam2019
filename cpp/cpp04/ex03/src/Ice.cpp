/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:57:59 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:58:00 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
}

Ice::Ice(Ice const &obj) : AMateria(obj) {
}

Ice::~Ice() {
}

Ice &Ice::operator=(const Ice &) {
    return *this;
}

AMateria *Ice::clone() const {
    AMateria *clone = new Ice(*this);
    return clone;
}

void Ice::use(ICharacter &target) {
    std::cout << CYAN "* shoots an ice bolt at " << target.getName() << " *" RESET << std::endl;
}
