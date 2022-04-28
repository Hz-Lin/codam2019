/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:11:40 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/27 21:13:40 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	_energyPoints = 50;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original) {
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &original) {
	if (this != &original) {
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	std::cout << "ScavTrap " << _name << " has been created by assignment operator" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " points of damage!" << std::endl;
		printStatus(_name, _hitPoints, _energyPoints);
	}
	else {
		std::cout << "ScavTrap " << _name << " does not have enough energy to attack" << std::endl;
	}
}

void ScavTrap::attack(ClapTrap &target) {
	attack(target.getName());
	target.takeDamage(_attackDamage);
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper node" << std::endl;
}
