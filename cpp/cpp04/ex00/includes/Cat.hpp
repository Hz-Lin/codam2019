/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:49:38 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:49:40 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &obj);
	virtual ~Cat();

	Cat &operator=(const Cat &obj);

	void makeSound() const;
};

#endif //CAT_HPP
