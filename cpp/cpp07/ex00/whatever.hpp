/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 11:36:38 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/15 10:48:35 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

# define BLUE "\033[1;34m"
# define RESET "\033[m"

template<typename T>
void swap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
T min(T const &x, T const &y) {
    if (x < y) {
        return x;
    }
    return y;
}

template<typename T>
T max(T const &x, T const &y) {
    if (x > y) {
        return x;
    }
    return y;
}

/*
class Awesome
{
public:
	Awesome(void) : _n(0) {}
	Awesome( int n ) : _n( n ) {}
	Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
	int get_n() const { return _n; }
private:
	int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }
*/

#endif //WHATEVER_HPP
