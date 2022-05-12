/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:57:42 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:57:43 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria() : _type("") {
}

AMateria::AMateria(const std::string &type) : _type(type) {
}

AMateria::AMateria(const AMateria &obj) : _type(obj._type) {
}

AMateria::~AMateria() {
}

AMateria &AMateria::operator=(const AMateria &) {
    return *this;
}

std::string const &AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter &target) {
    std::cout << WHITE "Does generic " << _type << " effect against " << target.getName() << RESET << std::endl;
}
