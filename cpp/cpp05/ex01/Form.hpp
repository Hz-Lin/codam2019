/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:27:29 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:27:30 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
private:
	std::string const _formName;
	bool _isSigned;
	int const _gradeSign;
	int const	_gradeExecute;

	Form();

public:
	Form(const std::string &name, const int &gradeSign, const int &gradeExecute);
	Form(const Form &obj);
	virtual ~Form();

	Form &operator=(const Form &obj);

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

    class FormAlreadySignedException: public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //FORM_HPP
