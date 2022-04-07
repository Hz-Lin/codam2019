/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:21:20 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:21:21 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string s = "HI THIS IS BRAIN";

	std::string*	stringPTR = &s;
	std::string&	stringREF = s;

	std::cout << "the memory address of the string variable: " << &s << std::endl;
	std::cout << "the memory address held by stringPTR:      " << stringPTR << std::endl;
	std::cout << "the memory address held by stringREF:      " << &stringREF << std::endl;

	std::cout << "the value of the string variable:  " << s << std::endl;
	std::cout << "the value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "the value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}
