/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/27 21:02:36 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/27 21:02:38 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(const std::string &name);
	FragTrap(FragTrap const &original);
	~FragTrap();

	FragTrap	&operator=(FragTrap const &original);

	void highFivesGuys();

private:
	FragTrap();
};


#endif //FRAGTRAP_HPP
