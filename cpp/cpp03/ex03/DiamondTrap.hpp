/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:09:50 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/28 15:11:56 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap(const std::string &name);
	DiamondTrap(DiamondTrap const &original);
	~DiamondTrap();

	DiamondTrap	&operator=(DiamondTrap const &original);

	void whoAmI();

	void	attack(std::string const &target);

private:
	std::string _name;
	DiamondTrap();
};


#endif //DIAMONDTRAP_HPP
