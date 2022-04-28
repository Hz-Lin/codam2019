/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:14:04 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/27 21:14:25 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_hitPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original) {
	std::cout << "FragTrap " << _name << " has been cloned" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &original) {
	if (this != &original) {
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	std::cout << "FragTrap " << _name << " has been created by assignment operator" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "Fragtrap " << _name << " would like a high five!" << std::endl;
}
