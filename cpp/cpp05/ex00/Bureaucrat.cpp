/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:15:30 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:15:32 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade() {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return MAGENTA "Bureaucrat grade is too high. Grade must be between 1 and 150." RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return MAGENTA "Bureaucrat grade is too low. Grade must be between 1 and 150." RESET;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << CYAN << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
	return os;
}
