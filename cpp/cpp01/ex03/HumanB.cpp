/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:29:37 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:38:56 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {
}

HumanB::~HumanB(void) {
}

void HumanB::setWeapon(Weapon& type) {
	_weapon = &type;
}

void HumanB::attack(void) {
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}