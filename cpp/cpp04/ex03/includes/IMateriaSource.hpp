/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IMateriaSource.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:57:22 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:57:23 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}

	virtual void learnMateria(AMateria *) = 0;

	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif //IMATERIASOURCE_HPP
