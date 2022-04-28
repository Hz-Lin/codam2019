/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 18:59:29 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/27 18:59:49 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::printStatus(std::string name, int hitPoints, int energyPoints) {
	std::cout << "--- " << name << " HP: " << hitPoints << " & EP: " << energyPoints << " ---" << std::endl;
}

ClapTrap::ClapTrap() {
}

ClapTrap::ClapTrap(const std::string &name)
	: _name(name),_hitPoints(10) , _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
	: _name(original._name), _hitPoints(original._hitPoints),
	_energyPoints(original._energyPoints), _attackDamage(original._attackDamage){
	std::cout << "ClapTrap " << original._name << " has been cloned" << std::endl;
	*this = original;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &original) {
	if (this != &original) {
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " has been created by assignment operator" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " points of damage!" << std::endl;
		printStatus(_name, _hitPoints, _energyPoints);
	}
	else {
		std::cout << "ClapTrap " << _name << " does not have enough energy to attack" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already died, RIP" << std::endl;
	}
	else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " has taken " << amount << " point of damage " << std::endl;
		if (_hitPoints <= 0) {
			std::cout << "ClapTrap " << _name << " has been brutally killed" << std::endl;
		}
		else {
			printStatus(_name, _hitPoints, _energyPoints);
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already died, it can not be repaired" << std::endl;
		return;
	}
	if (_energyPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " has got " << amount << " hit point restored" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << _name << " does not have enough energy to repair" << std::endl;
	}
	printStatus(_name, _hitPoints, _energyPoints);
}

const std::string &ClapTrap::getName() const {
	return _name;
}
