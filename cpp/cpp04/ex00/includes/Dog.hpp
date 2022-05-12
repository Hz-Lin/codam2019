/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:49:46 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:49:48 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &obj);
	virtual ~Dog();

	Dog &operator=(const Dog &obj);

	void makeSound() const;
};

#endif //DOG_HPP
