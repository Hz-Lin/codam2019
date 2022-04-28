/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:12:01 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/27 21:12:03 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap	roland("Roland");
	ScavTrap	axton("Axton");
	FragTrap	gaige("Gaige");
	FragTrap	krieg("Krieg");

	gaige.highFivesGuys();
	gaige.attack("Spiderant");

	roland.attack("Gaige");
	gaige.takeDamage(0);

	axton.attack(gaige);
	axton.attack(gaige);
	axton.attack(gaige);
	gaige.beRepaired(20);

	krieg = gaige;
	gaige.attack("Krieg");
	krieg.takeDamage(30);
	krieg.beRepaired(10);
	krieg.highFivesGuys();
	axton.attack(gaige);
	axton.attack(gaige);
	axton.attack(gaige);

	return 0;
}
