/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:50:04 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:50:05 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &obj);
	virtual ~WrongCat();

	WrongCat &operator=(const WrongCat &obj);

	void makeSound() const;
};


#endif //WRONGCAT_HPP
