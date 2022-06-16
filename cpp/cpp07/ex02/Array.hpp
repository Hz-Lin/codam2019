/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 13:03:30 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/14 13:03:32 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[m"

template<typename T>
class Array {
private:
    unsigned int _size;
    T *_array;

public:
    Array<T>() : _size(0), _array(NULL) {}; //create an empty array

    Array(unsigned int n): _size(n), _array(new T[_size]()) {}; //create an array of T

    Array<T>(Array<T> const &obj): _size(obj._size), _array(new T[obj._size]()) {
        for (unsigned int i = 0; i < obj._size; i++) {
            _array[i] = obj._array[i];
        }
    }

    ~Array<T>() {
        delete[] _array;
    }

    Array<T> &operator=(const Array<T> &obj) {
        if (this != &obj) {
            delete[] _array;
            _size = obj._size;
            _array = new T[obj._size]();
            for (unsigned int i = 0; i < obj._size; i++) {
                _array[i] = obj._array[i];
            }
        }
        return *this;
    }

    //overload array subscript operator
    T &operator[](unsigned int idx) {
        if (idx >= _size) {
            throw Array::OutOfBoundsException();
        }
        return _array[idx];
    }

    unsigned int size() const {
        return _size;
    }

    //function for overload << operator
    T *getArray() const {
        return _array;
    }

    //nested class for out of bounds exception
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return RED "index is out of bounds." RESET;
        }
    };

};

//overload the MM operator for testing
template<typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array) {
    for (unsigned int i = 0; i < array.size(); i++) {
        os << YELLOW << array.getArray()[i] << " ";
    }
    return os;
}

#endif //ARRAY_HPP
