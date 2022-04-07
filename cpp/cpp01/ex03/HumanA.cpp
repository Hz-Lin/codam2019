/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:29:22 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:36:52 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& type) : _name(name), _weapon(type){
}

HumanA::~HumanA(void) {
}

void HumanA::attack(void) {
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}