/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:29:29 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:29:31 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

public:
	HumanA(std::string name, Weapon& type);
	~HumanA(void);
	void	attack(void);

private:
	std::string _name;
	Weapon&		_weapon;
};

#endif //HUMANA_HPP
