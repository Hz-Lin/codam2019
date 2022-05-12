/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:57:48 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:57:50 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() { //not used in the main
}

Character::Character(const std::string &name) : _inventory(), _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

// deep copy
Character::Character(const Character &obj) : _inventory(), _name(obj._name) {
	for (int i = 0; i < 4; i++) {
		if (obj._inventory[i]) {
			_inventory[i] = obj._inventory[i]->clone();
		}
		else {
			_inventory[i] = NULL;
		}
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
		}
	}
}

Character &Character::operator=(const Character &obj) {
	if (this != &obj) {
		_name = obj._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (obj._inventory[i]) {
				_inventory[i] = obj._inventory[i]->clone();
			}
		}
	}
	return *this;
}

const std::string &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) {
	if (!m) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << YELLOW "Character " << _name << " has equipped ";
			std::cout << m->getType() << " on index: " << i << RESET << std::endl;
			return;
		}
		if (i == 3 && _inventory[i] != NULL) {
			std::cout << RED "Inventory is full, no more storage" RESET << std::endl;
			delete m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << RED "Index: " << idx << " out of rang, please chose between 0-3" << std::endl;
		return;
	}
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		std::cout << YELLOW "Character " << _name << " has unequipped ";
		std::cout << _inventory[idx]->getType() << " on index: " << idx << RESET << std::endl;
		_inventory[idx] = NULL;
	}
}

void  Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
	}
	else if (idx >= 0 && idx < 4 && _inventory[idx] == NULL) {
		std::cout << RED "No materia available on index: " << idx << RESET << std::endl;
	}
	else {
		std::cout << RED "Not a valid index: " << idx << RESET << std::endl;
	}
}

AMateria *Character::getInventory(unsigned int idx) const {
	if (idx >= 4) {
		return NULL;
	}
	return _inventory[idx];
}
