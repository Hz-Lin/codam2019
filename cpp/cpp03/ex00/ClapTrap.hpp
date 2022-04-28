/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 17:31:18 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/28 10:16:38 by hlin          ########   odam.nl         */
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

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	ClapTrap();
	std::string _name;
	int			_hitPoints;
	int 		_energyPoints;
	int 		_attackDamage;
};

#endif //CLAPTRAP_HPP
