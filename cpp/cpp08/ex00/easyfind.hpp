/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:31:58 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/20 22:32:00 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[m"

class NotFoundException : public std::exception {
public:
    virtual const char *what() const throw() {
        return MAGENTA "Int not found" RESET;
    }
};

//begin(): Returns an iterator pointing to the first element in the container.
//end(): Returns an iterator referring to the past-the-end element in the container.
//The past-the-end element is the theoretical element that would follow the last element in the container.
template<typename T>
typename T::iterator easyfind(T &container, int const &num) {
    typename T::iterator iter;
    iter = std::find(container.begin(), container.end(), num);
    if (iter == container.end()) {
        throw NotFoundException();
    }
    return iter;
}

#endif //EASYFIND_HPP
