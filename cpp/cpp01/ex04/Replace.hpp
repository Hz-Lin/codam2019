/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Replace.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:42:48 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:42:50 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace {

public:
	Replace(std::string filename);
	~Replace();
	void replaceStr(std::string s1, std::string s2);

private:
	std::ifstream _infile;
	std::ofstream _outfile;
};

#endif //REPLACE_HPP
