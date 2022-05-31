/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:41:58 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:41:59 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _grade() {
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	std::cout << BLUE "Bureaucrat " << _name << " has been created." RESET <<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _grade() {
	*this = obj;
	std::cout << BLUE "Bureaucrat " << _name << " has been copied." RESET <<std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << BLUE "Bureaucrat " << _name << " has been destroyed." RESET <<std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj) {
		_grade = obj._grade;
	}
	std::cout << BLUE "Bureaucrat " << _name << " has been assigned." RESET <<std::endl;
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
	std::cout << YELLOW "Bureaucrat " << _name << "'s grade has been increased. Grade: " << _grade << RESET << std::endl;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
	std::cout << YELLOW "Bureaucrat " << _name << "'s grade has been decreased. Grade: " << _grade << RESET << std::endl;
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << GREEN << _name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << MAGENTA << _name << " coudn't signed " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
    catch (AForm::FormAlreadySignedException &e) {
        std::cout << MAGENTA << _name << " coudn't signed " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.execute(*this);
        std::cout << GREEN << _name << " executed " << form.getName() << RESET << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << MAGENTA << _name << " coudn't executed " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
    catch (AForm::FormNotSignedException &e) {
        std::cout << MAGENTA << _name << " coudn't executed " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return MAGENTA "Bureaucrat grade is too high." RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return MAGENTA "Bureaucrat grade is too low." RESET;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << CYAN << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
	return os;
}
