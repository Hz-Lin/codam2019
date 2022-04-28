/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:01:08 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/27 21:01:10 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(const std::string &name);
	ScavTrap(ScavTrap const &original);
	~ScavTrap();

	ScavTrap	&operator=(ScavTrap const &original);

	void attack(const std::string &target);
	void attack(ClapTrap &target);

	void guardGate();

private:
	ScavTrap();
};


#endif //SCAVTRAP_HPP
