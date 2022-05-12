/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:58:10 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/12 10:08:56 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void	subjectTest(){
	std::cout << "\nMain from subject" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	moreTest(){
	std::cout	<< "\nMore Tests\n" << std::endl;
	IMateriaSource *source = new MateriaSource();
	ICharacter	*priest = new Character("Katje");
	ICharacter	*shaman = new Character("Arte");

	source->createMateria("ice"); // have to learn the marteria before create
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	shaman->use(3, *priest); // no materia in this index
	shaman->use(5, *priest); // index out of range
	source->learnMateria(new Cure());
	source->learnMateria(new Cure());
	source->learnMateria(new Ice()); // inventory is full

	std::cout << std::endl;

	AMateria* tmp;
	tmp = source->createMateria("lighting"); // unknown type
	shaman->equip(tmp);
	tmp = source->createMateria("ice");
	shaman->equip(tmp);
	tmp = source->createMateria("cure");
	shaman->equip(tmp);
	tmp = source->createMateria("ice");
	shaman->equip(tmp);
	tmp = source->createMateria("cure");
	shaman->equip(tmp);
	tmp = source->createMateria("ice");
	shaman->equip(tmp); // inventory is full
	shaman->use(0, *priest); // ice damage
	shaman->use(1, *priest); // cure the wound
	shaman->use(2, *priest); // ice damage
	shaman->use(3, *priest); // cure the wound

	std::cout << std::endl;

	shaman->unequip(5); // index out of range
	AMateria *m2 = dynamic_cast<Character *>(shaman)->getInventory(2); //get address of index 2
	shaman->unequip(2); // unequipped ice
	delete m2;
	AMateria *m1 = dynamic_cast<Character *>(shaman)->getInventory(1); //get address of index 1
	shaman->unequip(1); // unequipped cure
	delete m1; // the unequip method must NOT delete Material, so delete here to avoid leaks
	
	shaman->use(0, *priest); // ice damage
	shaman->use(1, *priest); // not available
	shaman->use(2, *priest); // not available
	shaman->use(3, *priest); // cure the wound
	tmp = source->createMateria("ice");
	shaman->equip(tmp); // equip in the first available slot, index: 1
	tmp = source->createMateria("cure");
	shaman->equip(tmp); // equip in the first available slot, index: 2
	shaman->use(0, *priest); // ice damage
	shaman->use(1, *priest); // ice damage
	shaman->use(2, *priest); // cure the wound
	shaman->use(3, *priest); // cure the wound

	delete shaman;
	delete priest;
	delete source;
}

int main()
{
	subjectTest();
	std::cout << std::endl;
	moreTest();
	std::cout << "\nCheck leaks: " << std::endl;
	system ("leaks interface");
}

