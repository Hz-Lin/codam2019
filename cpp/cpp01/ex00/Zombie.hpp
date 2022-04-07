/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 10:27:00 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 10:48:04 by hlin          ########   odam.nl         */
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
	void	announce(void);

private:
	std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif //ZOMBIE_HPP
