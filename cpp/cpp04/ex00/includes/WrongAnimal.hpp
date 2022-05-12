/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:49:55 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:49:56 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RESET "\033[m"

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &obj);
	virtual ~WrongAnimal();

	WrongAnimal	&operator=(WrongAnimal const &obj);

	const std::string &getType() const;
	void makeSound() const;

protected:
	std::string	_type;
	WrongAnimal(std::string type);
};


#endif //WRONGANIMAL_HPP
