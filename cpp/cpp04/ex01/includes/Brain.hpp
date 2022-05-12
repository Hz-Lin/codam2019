/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:52:41 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:52:42 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

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

class Brain {
public:
	Brain();
	Brain(const Brain &obj);
	virtual ~Brain();

	Brain &operator=(const Brain &obj);

	const std::string *getIdeas() const;

private:
	std::string _ideas[100];
};


#endif //BRAIN_HPP
