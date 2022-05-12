/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:56:47 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:56:48 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

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
// AMateria contains a ICharacter reference
class ICharacter;

class AMateria {
public:
    AMateria();

    AMateria(std::string const &type);

    AMateria(AMateria const &obj);

    virtual ~AMateria();

    AMateria &operator=(AMateria const &obj);

    std::string const &getType() const;

    virtual AMateria *clone() const = 0;

    virtual void use(ICharacter &target);

protected:
    std::string const _type;
};

#endif //AMATERIA_HPP
