/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:29:54 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:29:55 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

public:
	HumanB(std::string name);
	~HumanB(void);
	void	attack(void);
	void 	setWeapon(Weapon& type);

private:
	std::string _name;
	Weapon		*_weapon;
};


#endif //HUMANB_HPP
