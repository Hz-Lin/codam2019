/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:11:25 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:11:26 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
	Zombie(void);
	~Zombie(void);
	void	setName(std::string name);
	void	announce(void) const;

private:
	std::string _name;
};

Zombie*    zombieHorde(int N, std::string name);

#endif //ZOMBIE_HPP
