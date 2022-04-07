/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:11:17 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:11:18 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
}

Zombie::~Zombie(void) {
	std::cout << this->_name << ": RIP" << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}