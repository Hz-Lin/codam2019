/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:11:34 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:20:47 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main() {
	int	nb = 5;

	Zombie	*horde = zombieHorde(nb, "Jessica");
	for (int i = 0; i < nb; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
