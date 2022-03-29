/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 22:11:46 by hlin          #+#    #+#                 */
/*   Updated: 2022/03/22 22:56:54 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
	this->index = -1;
}

Contact::~Contact() {
	return;
}

void	Contact::update(int i) {
	std::string input;

	this->index = i + 1;
	std::cout << "First Name: ";
	if (!getline(std::cin, input))
		return ;
	this->_firstName = input;

	std::cout << "Last Name: ";
	if (!getline(std::cin, input))
		return ;
	this->_lastName = input;

	std::cout << "Nickname: ";
	if (!getline(std::cin, input))
		return ;
	this->_nickname = input;

	std::cout << "Phone Number: ";
	if (!getline(std::cin, input))
		return ;
	this->_phoneNum = input;

	std::cout << "Darkest Secret: ";
	if (!getline(std::cin, input))
		return ;
	this->_darkestSecret = input;
}

std::string crop_string(std::string str) {
	if (str.length() > 10) {
		return (str.substr(0,9) + ".");
	}
	return (str);
}

void Contact::displayColumns(void) const {
	std::cout << std::setw(10) << this->index << "|";
	std::cout << std::setw(10) << crop_string(this->_firstName) << "|";
	std::cout << std::setw(10) << crop_string(this->_lastName) << "|";
	std::cout << std::setw(10) << crop_string(this->_nickname) << std::endl;
}

void Contact::displayAllInfo(void) const {
	std::cout << std::endl << "Contact Index:   " << this->index << std::endl;
	std::cout << "First Name:      " << this->_firstName << std::endl;
	std::cout << "Last Name:       " << this->_lastName << std::endl;
	std::cout << "Nickname:        " << this->_nickname << std::endl;
	std::cout << "Phone Number:    " << this->_phoneNum << std::endl;
	std::cout << "Darkest Secret:  " << this->_darkestSecret << std::endl;
}