/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:30:32 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:30:33 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	const std::string&	getType(void);
	void	setType(std::string type);

private:
	std::string	_type;
};


#endif //WEAPON_HPP
