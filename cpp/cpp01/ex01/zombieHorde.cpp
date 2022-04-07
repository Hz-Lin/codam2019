/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:11:44 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:11:45 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*    zombieHorde(int N, std::string name) {
	Zombie	*zombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombies[i].setName(name);
	}
	return zombies;
}
