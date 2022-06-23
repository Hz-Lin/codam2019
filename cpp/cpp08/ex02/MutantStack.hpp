/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:33:30 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/20 22:33:32 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[m"

/*
** The functions associated with stack are:
** empty() – Returns whether the stack is empty
** size() – Returns the size of the stack
** top() – Returns a reference to the top most element of the stack
** push(g) – Adds the element ‘g’ at the top of the stack
** pop() – Deletes the top most element of the stack

** the additional iterators feature:
** begin() – Returns an iterator pointing to the first element in the vector
** end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
** rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
** rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
** there is no cbegin() and the other const_iterator implemented here, because they are C++11 feature
 */

// By default, if no container class is specified for a particular stack class instantiation, the standard container deque is used.
template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>() {};

    MutantStack(MutantStack<T> const &obj) : std::stack<T>() {
        *this = obj;
    }

    virtual ~MutantStack() {};

    MutantStack &operator=(MutantStack<T> const &obj) {
        if (this != &obj) {
            std::stack<T>::operator=(obj);
        }
        return *this;
    }

    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::reverse_iterator reverseIterator;

    // c is the 'container_type' from stack class
    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    reverseIterator rbegin() {
        return this->c.rbegin();
    }

    reverseIterator rend() {
        return this->c.rend();
    }
};

#endif //MUTANTSTACK_HPP
