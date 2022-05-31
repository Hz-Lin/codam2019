/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:41:53 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:41:54 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
private:
	std::string const _formName;
	bool _isSigned;
	int const _gradeSign;
	int const	_gradeExecute;
    std::string _target;

protected:
    virtual void action() const = 0;
    void setTarget(const std::string &target);
	AForm();

public:
	AForm(const std::string &name, const int &gradeSign, const int &gradeExecute);
	AForm(const AForm &obj);
	virtual ~AForm();

	AForm &operator=(const AForm &obj);

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;
    const std::string &getTarget() const;

	void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const &bureaucrat) const;

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

    class FormNotSignedException: public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif //FORM_HPP
