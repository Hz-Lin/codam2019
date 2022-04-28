/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 18:54:58 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/28 11:44:15 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main() {
	ClapTrap hunter("Mordecai");
	hunter.attack("Scythids");
	hunter.takeDamage(5);
	hunter.beRepaired(4);
	hunter.takeDamage(2);
	hunter.beRepaired(7);
	hunter.takeDamage(15);
	std::cout << std::endl;

	ClapTrap siren("Lilith");
	ClapTrap sirenReborn(siren);
	sirenReborn.attack("Larva Crab Worm");
	sirenReborn.takeDamage(5);
	sirenReborn.attack("Trash Feeder");
	sirenReborn.takeDamage(2);
	sirenReborn.attack("Drifter");
	sirenReborn.takeDamage(3);
	std::cout << std::endl;

	ClapTrap soldier("Roland");
	soldier.attack("Bandit");
	soldier.takeDamage(5);
	soldier.attack("Tankenstein");
	soldier.takeDamage(2);
	soldier.attack("Loot Goon");
	soldier.takeDamage(2);
	soldier.beRepaired(4);
	soldier.attack("Corpse Eater");
	soldier.takeDamage(2);
	soldier.beRepaired(3);
	soldier.attack("Psycho Zombie");
	soldier.takeDamage(2);
	soldier.beRepaired(3);
	soldier.attack("Skelerakk");
	soldier.takeDamage(2);
	soldier.beRepaired(3);
	soldier.attack("Wereskag");
	std::cout << std::endl;

	return 0;
}
