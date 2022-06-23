/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:32:54 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/20 22:32:55 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <numeric> // std::adjacent_difference

Span::Span() {
}

Span::Span(unsigned int N) : _n(N) {
}

Span::Span(const Span &obj):  _n(obj._n) {
    *this = obj;
}

Span::~Span() {
}

Span &Span::operator=(const Span &obj) {
    if (this != &obj) {
        _n = obj._n;
        _myVector = obj._myVector;
    }
    return *this;
}

// size() – Returns the number of elements in the vector.
void Span::addNumber(const int &num) {
    if (_myVector.size() >= _n) {
        throw Span::ContainerFullException();
    }
    _myVector.push_back(num);
}

// vector_name.insert(position, iterator1, iterator2)
// position – It specifies the iterator which points to the position where the insertion is to be done.
// iterator1 – It specifies the starting position from which the elements are to be inserted
// iterator2 – It specifies the ending position till which elements are to be inserted
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    _myVector.insert(_myVector.end(), begin, end);
    if (_myVector.size() > _n) {
        throw Span::ContainerFullException();
    }
}

// OutputIterator adjacent_difference (InputIterator first, InputIterator last, OutputIterator result);
// Assigns to every element in the range starting at result the difference between its corresponding element in the
// range [first,last) and the one preceding it (except for *result, which is assigned *first).
// If x represents an element in [first,last) and y represents an element in result, the ys can be calculated as:
//y0 = x0; y1 = x1 - x0; y2 = x2 - x1; ...
// min_element: find the smallest not in the whole list, but in a sub-section of the list
unsigned int Span::shortestSpan() const {
    if (_myVector.size() < 2) {
        throw Span::NoSpanException();
    }
    std::vector<int> copy(_myVector);
    std::sort(copy.begin(), copy.end());
    std::adjacent_difference(copy.begin(), copy.end(), copy.begin());
    unsigned int shortest = *(std::min_element(copy.begin() + 1, copy.end()));
    return shortest;
}

// at(g) – Returns a reference to the element at position ‘g’ in the vector
unsigned int Span::longestSpan() const {
    if (_myVector.size() < 2) {
        throw Span::NoSpanException();
    }
    std::vector<int> copy(_myVector);
    std::sort(copy.begin(), copy.end());
    unsigned int longest = copy.at(copy.size() - 1) - copy.at(0);
    return longest;
}

const char *Span::ContainerFullException::what() const throw() {
    return MAGENTA "Container is already full."RESET;
}

const char *Span::NoSpanException::what() const throw() {
    return MAGENTA "Do not have enough elements to determine span." RESET;
}
