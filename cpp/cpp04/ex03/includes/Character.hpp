/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:56:53 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:56:54 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
	Character(const std::string &name);

	Character(Character const &obj);

	virtual ~Character();

	Character &operator=(Character const &obj);

	const std::string &getName() const;

	virtual void equip(AMateria *m);

	virtual void unequip(int idx);

	virtual void use(int idx, ICharacter &target);

	AMateria *getInventory(unsigned int idx) const;

private:
	Character();

	AMateria *_inventory[4];
	std::string _name;
};

#endif //CHARACTER_HPP
