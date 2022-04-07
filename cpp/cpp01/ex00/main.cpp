/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 10:26:16 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:10:04 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main() {
    Zombie	*zb;

    zb = newZombie("Karen"); //allocated on heap
    if (zb != NULL) {
    	zb->announce();
    	delete zb;
    }
	randomChump("Jim"); //allocated on stack, destroy by compiler
    return 0;
}
