/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:10:36 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/27 21:10:38 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
	ClapTrap(const std::string &name);
	ClapTrap(ClapTrap const &original);
	~ClapTrap();

	ClapTrap	&operator=(ClapTrap const &original);

	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string &getName() const;

protected: //also accessible for the subclasses
	ClapTrap();

	std::string _name;
	int			_hitPoints;
	int 		_energyPoints;
	int 		_attackDamage;

	static void printStatus(std::string name, int hitPoints, int energyPoints);
};

#endif //CLAPTRAP_HPP
