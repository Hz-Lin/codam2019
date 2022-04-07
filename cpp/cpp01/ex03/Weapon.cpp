/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:30:25 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:39:48 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
}

Weapon::Weapon(std::string type): _type(type) {
}

Weapon::~Weapon(void) {
}

const std::string& Weapon::getType(void) {
	return _type;
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}