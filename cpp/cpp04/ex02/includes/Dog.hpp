/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:55:12 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:55:14 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
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
