/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:53:18 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:53:21 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << BLUE "Brain has been created by default constructor" RESET << std::endl;
}

Brain::Brain(const Brain &obj) {
	std::cout << BLUE "Brain has been copied" RESET << std::endl;
	*this = obj;
}

Brain::~Brain() {
	std::cout << RED "Brain has been destroyed" RESET << std::endl;
}

Brain &Brain::operator=(const Brain &obj) {
	std::cout << BLUE "This brain has been converted" RESET << std::endl;
	if (this != &obj) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = obj._ideas[i];
		}
	}
	return *this;
}

const std::string *Brain::getIdeas() const {
	return _ideas;
}
