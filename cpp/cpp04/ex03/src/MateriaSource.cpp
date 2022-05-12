/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:58:06 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:58:07 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _inventory() {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

// deep copy through clone
MateriaSource::MateriaSource(const MateriaSource &obj) : _inventory() {
	for (int i = 0; i < 4; i++) {
		if (obj._inventory[i]) {
			_inventory[i] = obj._inventory[i]->clone();
		}
		else {
			_inventory[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
	if (this != &obj) {
		for (int i = 0; i < 4; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
			}
			if (obj._inventory[i]) {
				_inventory[i] = obj._inventory[i]->clone();
			}
			else {
				_inventory[i] = NULL;
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
		if (_inventory[3] != NULL) {
			std::cout << RED "Inventory is full, cannot learn anymore" RESET << std::endl;
			delete m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && (type == _inventory[i]->getType())) {
			return _inventory[i]->clone();
		}
	}
	std::cout << RED "Unknown type of materia: " << type << RESET << std::endl;
	return 0;
}