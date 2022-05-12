/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:55:07 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:55:08 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
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
