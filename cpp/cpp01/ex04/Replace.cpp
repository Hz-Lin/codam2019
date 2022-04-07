/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Replace.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:42:40 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:42:42 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename)
	: _infile(filename), _outfile(filename + ".replace", std::ios_base::trunc){

	if (!_infile.is_open()) {
		std::cerr << "Could not open file: " << filename << std::endl;
		exit(1);
	}
	if (!_outfile.is_open()) {
		std::cerr << "Could not open file: " << filename << ".replace" << std::endl;
		exit(1);
	}
}

Replace::~Replace(void) {
	_infile.close();
	_outfile.close();
}

void Replace::replaceStr(std::string s1, std::string s2) {
	std::string content;

	std::getline(_infile, content, '\0');
	size_t	pos = 0;
	size_t	start = 0;
	while(true) {
		start = pos;
		pos = content.find(s1, pos);
		if (pos == std::string::npos) {
			break;
		}
		_outfile << content.substr(start, pos - start) << s2;
		pos = pos + s1.length();
	}
	_outfile << content.substr(start, pos - start);
	content.clear();
}
