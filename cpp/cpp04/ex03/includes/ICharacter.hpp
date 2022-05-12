/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ICharacter.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:57:14 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:57:16 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RESET "\033[m"

// ICharacter and AMateria depend on each other
// Forward declaration of ICharacter here solve this circular dependency problem
// ICharacter contains a AMateria reference
class AMateria;

class ICharacter {
public:
	virtual ~ICharacter() {}

	virtual std::string const &getName() const = 0;

	virtual void equip(AMateria *m) = 0;

	virtual void unequip(int idx) = 0;

	virtual void use(int idx, ICharacter &target) = 0;
};

#endif //ICHARACTER_HPP
