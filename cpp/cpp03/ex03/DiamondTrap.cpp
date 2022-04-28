/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:15:16 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/28 15:13:25 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
}

DiamondTrap::DiamondTrap(const std::string &name) : _name(name) {
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original) : ClapTrap(original), ScavTrap(original), FragTrap(original) {
	std::cout << "DiamondTrap " << original._name << " has been cloned" << std::endl;
	*this = original;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " has been destroyed" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &original) {
	if (this != &original) {
		ClapTrap::_name = original.ClapTrap::_name;
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	std::cout << "DiamondTrap " << _name << " has been created by assignment operator" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "The name of this DiamondTrap is " << _name
		<< " and the ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(std::string const &target) {
	ScavTrap::attack(target);
}
