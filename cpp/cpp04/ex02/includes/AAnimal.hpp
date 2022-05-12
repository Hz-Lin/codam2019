/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:54:53 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:54:56 by hlin          ########   odam.nl         */
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

class AAnimal {
public:
	AAnimal();
	AAnimal(AAnimal const &obj);
	virtual ~AAnimal();

	AAnimal	&operator=(AAnimal const &obj);

	const std::string &getType() const;

	virtual void makeSound() const = 0; //pure virtual function

protected:
	std::string	_type;
	AAnimal(std::string type);
};

#endif //ANIMAL_HPP
