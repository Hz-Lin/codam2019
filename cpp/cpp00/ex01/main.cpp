/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:50:38 by hlin          #+#    #+#                 */
/*   Updated: 2022/03/23 13:17:47 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int search_phonebook(Contact contactList[8]) {
	int  contactIndex= 0;
	std::string	input;

	std::cout << "     Index| Firstname|  Lastname|  Nickname" << std::endl;
	for (int i = 0; i < 8 && contactList[i].index != -1; i++) {
		contactList[i].displayColumns();
	}
	std::cout << std::endl << "Choose an contact index to search -->";
	while (true) {
		if (!getline(std::cin, input)) {
			return 1;
		}
		else {
			try {
				contactIndex = atoi(input.c_str());
			}
			catch (const std::exception e) {
				std::cout << "Invalid index, please chose an number from 1 to 8 -->";
				continue ;
			}
			contactIndex -= 1;
			if (contactIndex < 0 || contactIndex > 7) {
				std::cout << "Invalid index number, please chose an number from 1 to 8 -->";
			}
			else if (contactList[contactIndex].index == -1) {
				std::cout << "No contact stored within this index, please chose another -->";
			}
			else {
				contactList[contactIndex].displayAllInfo();
				std::cout << std::endl;
				return 0;
			}
		}
	}
}

int main() {
	PhoneBook	pb;
	std::string input;
	int 		count = 0;

	std::cout << "Thank you for using this crappy phonebook!" << std::endl;
	while (true) {
		std::cout << "If you wish to add a contact, type ADD" << std::endl;
		std::cout << "If you wish to search the phonebook, type SEARCH" << std::endl;
		std::cout << "If you wish to exit this program, type EXIT" << std::endl;
		std::cout << "-->";
		if (!getline(std::cin, input)) {
			std::cout << "Error, input cannot be empty" << std::endl;
			return 1;
		}
		if (input == "ADD") {
			pb.contactList[count % 8].update(count % 8);
			count++;
		}
		else if (input == "SEARCH") {
			if (search_phonebook(pb.contactList) == -1) {
				return 1;
			}
		}
		else if (input == "EXIT") {
			return 0;
		}
	}
}
