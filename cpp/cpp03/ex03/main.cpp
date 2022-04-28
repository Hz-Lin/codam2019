/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:11:47 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/28 15:08:33 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap maya("Maya");
	DiamondTrap zero("Zero");
	maya.attack("Zer0");
	zero.takeDamage(30);
	zero.beRepaired(12);
	maya.guardGate();
	maya.whoAmI();
	maya.attack(zero);
	maya.attack(zero);
	maya.attack(zero);
	maya.highFivesGuys();
	std::cout << std::endl;

	DiamondTrap amara("Amara");
	FragTrap lilith("Lilith");
	ScavTrap brick("Brick");
	ClapTrap aurelia("Aurelia");
	amara = maya;
	amara.attack("Lilith");
	lilith.takeDamage(30);
	lilith.highFivesGuys();
	amara.whoAmI();
	brick.guardGate();
	lilith.attack("Amara");
	amara.takeDamage(30);
	brick.attack(amara);
	aurelia.attack("Amara");
	amara.attack("Aurelia");
	aurelia.takeDamage(30);
	amara.attack(brick);
	amara.attack(brick);
	amara.attack(brick);
	amara.attack(brick);
	amara.attack(lilith);
	amara.attack(lilith);
	amara.attack(lilith);

	return 0;
}
