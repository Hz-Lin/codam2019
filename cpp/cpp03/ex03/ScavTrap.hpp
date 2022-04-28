/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:07:14 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/27 21:09:02 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(const std::string &name);
	ScavTrap(ScavTrap const &original);
	~ScavTrap();

	ScavTrap	&operator=(ScavTrap const &original);

	void attack(const std::string &target);
	void attack(ClapTrap &target);

	void guardGate();

protected:
	ScavTrap();
};


#endif //SCAVTRAP_HPP
