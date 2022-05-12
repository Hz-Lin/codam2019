/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:53:04 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:53:05 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &obj);
	virtual ~Dog();

	Dog &operator=(const Dog &obj);

	void makeSound() const;

	Brain *getBrain() const;

private:
	Brain *_brain;
};

#endif //DOG_HPP
