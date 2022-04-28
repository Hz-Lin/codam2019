/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:12:15 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/28 11:50:34 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main() {

	ScavTrap	lilith("Lilith");
	ScavTrap	maya(lilith);
	ScavTrap	brick("Brick");
	std::cout << std::endl;

	maya.attack("Brick");
	brick.takeDamage(20);
	std::cout << std::endl;

	std::cout << "attack an ClapTrap object" << std::endl;
	ScavTrap	salvador("Salvador");
	ClapTrap	roland("Roland");
	salvador.attack(roland);
	std::cout << std::endl;

	std::cout << "attack ScavTrap objects" << std::endl;
	maya.attack(brick);
	maya.attack(brick);
	maya.attack(brick);
	brick.attack(maya);
	maya.guardGate();
	maya.beRepaired(5);
	maya.attack(brick);
	std::cout << std::endl;

	ScavTrap	jack("Jack");
	ScavTrap	handsomeJack("Handsome Jack");
	handsomeJack = jack;
	handsomeJack.attack("Nisha");
	handsomeJack.attack(roland);
	handsomeJack.attack(maya);
	maya.attack(handsomeJack);
	handsomeJack.guardGate();
	handsomeJack.beRepaired(10);

	return 0;
}
