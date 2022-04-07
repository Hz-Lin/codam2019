/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 11:57:07 by hlin          #+#    #+#                 */
/*   Updated: 2022/04/04 11:57:43 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {

public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	std::string _level[4];
	void(Harl::*func[4])(void);
};

#endif //HARL_HPP
