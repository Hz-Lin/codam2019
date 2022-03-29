/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 10:44:32 by hlin          #+#    #+#                 */
/*   Updated: 2022/03/09 16:55:54 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++) {
			for(unsigned long j = 0; j < ((std::string)argv[i]).length(); j++) {
				char letter = std::toupper(argv[i][j]);
				std::cout << letter << std::flush;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}