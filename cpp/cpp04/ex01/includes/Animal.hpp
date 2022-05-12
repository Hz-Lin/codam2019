/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:52:31 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:52:32 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

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

class Animal {
public:
	Animal();
	Animal(Animal const &obj);
	virtual ~Animal();

	Animal	&operator=(Animal const &obj);

	const std::string &getType() const;
	virtual void makeSound() const;

protected:
	std::string	_type;
	Animal(std::string type);
};

#endif //ANIMAL_HPP
