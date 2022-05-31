/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:42:10 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:44:09 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << BLUE "Intern has been created." RESET <<std::endl;
}

Intern::Intern(const Intern &obj) {
	*this = obj;
	std::cout << BLUE "Intern has been copied." RESET <<std::endl;
}

Intern::~Intern() {
	std::cout << BLUE "Intern has been destroyed." RESET <<std::endl;
}

Intern &Intern::operator=(const Intern &obj) {
	if (this != &obj) {
		(void) obj;
	}
	std::cout << BLUE "Intern has been assigned." RESET <<std::endl;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	std::string formType[] = { "shrubbery creation", "robotomy request", "presidential pardon"};
	int formCase = 4;
	for (int i = 0; i < 4; i++) {
		if (formName == formType[i]) {
			formCase = i;
			break;
		}
	}
	AForm *newForm;
	switch (formCase) {
		case 0:
			newForm = new ShrubberyCreationForm(target);
			break;
		case 1:
			newForm = new RobotomyRequestForm(target);
			break;
		case 2:
			newForm = new PresidentialPardonForm(target);
			break;
		default:
			throw NonExistenceFormException();
	}
	std::cout << YELLOW "Intern creates " << formName << RESET << std::endl;
	return newForm;
}

const char *Intern::NonExistenceFormException::what() const throw() {
	return MAGENTA "Invalid form type.'\nAvailable: \n- shrubbery creation\n- robotomy request\n- presidential pardon" RESET;
}
