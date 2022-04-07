/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:57:00 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:58:27 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	_level[0]= "DEBUG";
	_level[1] = "INFO";
	_level[2] = "WARNING";
	_level[3] = "ERROR";

	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;
}

Harl::~Harl(void) {
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (level == this->_level[i]) {
			(this->*func[i])();
		}
	}
}

void Harl::debug() {
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years ";
	std::cout << "whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
