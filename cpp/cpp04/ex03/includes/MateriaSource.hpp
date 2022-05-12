/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:57:27 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:57:28 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();

	MateriaSource(MateriaSource const &obj);

	virtual ~MateriaSource();

	MateriaSource &operator=(MateriaSource const &obj);

	void learnMateria(AMateria *);

	AMateria *createMateria(std::string const &type);

protected:
	AMateria *_inventory[4];
};


#endif //MATERIASOURCE_HPP
