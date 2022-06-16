/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 11:35:59 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/15 10:49:16 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

# define BLUE "\033[1;34m"
# define RESET "\033[m"

template<typename T>
void iter(T const *array, int const len, void (*fun)(T const &)) {
    for (int i = 0; i < len; i++) {
        fun(array[i]);
    }
}

template<typename T>
void printElement(T const &element) {
    std::cout << element << std::endl;
}

/*
class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
*/

#endif //ITER_HPP
