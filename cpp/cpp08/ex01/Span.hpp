/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:33:01 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/20 22:33:02 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[m"

class Span {
private:
    unsigned int _n;
    std::vector<int> _myVector;
    Span();

public:
    Span(unsigned int N);
    Span(Span const &obj);
    virtual ~Span();
    Span &operator=(Span const &obj);

    void addNumber(int const &num);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class ContainerFullException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};


#endif //SPAN_HPP
