/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:42:26 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:42:27 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: ./replace <filename> <str_to_find> <replacement_str>" << std::endl;
		return 1;
	}
	if (!*argv[1] || !*argv[2] || !*argv[3]) {
		std::cerr << "arguments should not be empty" << std::endl;
		return 1;
	}
	Replace	replace(argv[1]);
	replace.replaceStr(argv[2], argv[3]);
	return 0;
}
