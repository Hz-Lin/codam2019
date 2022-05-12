/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:57:00 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:57:03 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure();

	Cure(Cure const &obj);

	virtual ~Cure();

	Cure &operator=(Cure const &obj);

	AMateria *clone() const;

	void use(ICharacter &target);
};

#endif //CURE_HPP
