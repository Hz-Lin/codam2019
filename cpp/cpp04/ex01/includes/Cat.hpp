/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:52:55 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:52:56 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &obj);
	virtual ~Cat();

	Cat &operator=(const Cat &obj);

	void makeSound() const;

	Brain *getBrain() const;

private:
	Brain *_brain;
};

#endif //CAT_HPP
