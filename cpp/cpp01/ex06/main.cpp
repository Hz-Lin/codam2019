/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 13:15:29 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 13:15:30 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int getLevel(std::string input) {
	std::string	levelList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levelList[i] == input) {
			return i;
		}
	}
	return 4;
}

void	printCompain(Harl harl, std::string level) {
	std::cout << "[ " << level << " ]" << std::endl;
	harl.complain(level);
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./harlfilter \"<LEVEL>\"" << std::endl;
		std::cerr << "LEVEL: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	Harl	harl;
	int i = getLevel(argv[1]);
	switch (i) {
		case 0:
			printCompain(harl,"DEBUG");
		case 1:
			printCompain(harl,"INFO");
		case 2:
			printCompain(harl,"WARNING");
		case 3:
			printCompain(harl,"ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}
