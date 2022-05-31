/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:27:16 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:27:17 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

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

class Form;

class Bureaucrat {
private:
	std::string const	_name;
	int	_grade;
	Bureaucrat();

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &obj);
	virtual ~Bureaucrat();

	Bureaucrat&	operator=(Bureaucrat const &obj);

	std::string const	&getName() const;
	int 	getGrade() const;
	void	incrementGrade();
	void 	decrementGrade();
	void	signForm(Form &form) const;

	// create custom exception class
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
		// const char *what() is the member function
		// throw() declares that the function throws no exceptions, is not a method, it is an empty list
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //BUREAUCRAT_HPP
