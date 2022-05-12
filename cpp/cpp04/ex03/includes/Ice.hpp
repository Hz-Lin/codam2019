/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:57:07 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:57:09 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
    Ice();

    Ice(Ice const &obj);

    virtual ~Ice(void);

    Ice &operator=(Ice const &obj);

    AMateria *clone() const;

    void use(ICharacter &target);
};

#endif //ICE_HPP
