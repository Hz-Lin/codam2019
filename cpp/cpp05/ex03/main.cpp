/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:42:21 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:49:06 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

void internInvalidTest() {
	try {
		std::cout << "\n*** Intern create Invalid Form ***" << std::endl;
		Intern lewinsky;
		AForm *form;
		form = lewinsky.makeForm("invalid form", "unknown");
		delete form;
	} catch (Intern::NonExistenceFormException &e) {
		std::cout << e.what() << std::endl;
	}
}

void internShrubberyTest() {
	try {
		std::cout << "\n*** Intern create Shrubbery Creation Form ***" << std::endl;
		Intern lewinsky;
		AForm *form;
		form = lewinsky.makeForm("shrubbery creation", "DoubleTree");
		delete form;
	} catch (Intern::NonExistenceFormException &e) {
		std::cout << e.what() << std::endl;
	}
}

void internRobotomyTest() {
	try {
		std::cout << "\n*** Intern create Robotomy Request Form ***" << std::endl;
		Intern lewinsky;
		AForm *form;
		form = lewinsky.makeForm("robotomy request", "Dio Brando");
		delete form;
	} catch (Intern::NonExistenceFormException &e) {
		std::cout << e.what() << std::endl;
	}
}

void internPresidentialTest() {
	try {
		std::cout << "\n*** Intern create Presidential Pardon Form ***" << std::endl;
		Intern lewinsky;
		AForm *form;
		form = lewinsky.makeForm("presidential pardon", "Jolyne Cujoh");
		delete form;
	} catch (Intern::NonExistenceFormException &e) {
		std::cout << e.what() << std::endl;
	}
}

void shrubberyMixTest() {
	try {
		std::cout << "\n*** Shrubbery Creation Form Mix Tests ***" << std::endl;
		Bureaucrat joestar("Joestar", 100);
		std::cout << joestar << std::endl;
		Intern zeppeli;
		AForm *shrubbery;
		shrubbery = zeppeli.makeForm("shrubbery creation", "DoubleTree");
		std::cout << *shrubbery << std::endl;
		joestar.signForm(*shrubbery);
		joestar.executeForm(*shrubbery);
		delete shrubbery;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void robotomyMixTest() {
	try {
		std::cout << "\n*** Robotomy Request Form Mix Tests ***" << std::endl;
		Bureaucrat joestar("Joestar", 30);
		std::cout << joestar << std::endl;
		Intern zeppeli;
		AForm *robot;
		robot = zeppeli.makeForm("robotomy request", "Bender");
		std::cout << *robot << std::endl;
		joestar.signForm(*robot);
		joestar.executeForm(*robot);
		delete robot;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void presidentialMixTest() {
	try {
		std::cout << "\n*** Presidential Pardon Form Mix Tests ***" << std::endl;
		Bureaucrat joestar("Joestar", 3);
		std::cout << joestar << std::endl;
		Intern zeppeli;
		AForm *pradon;
		pradon = zeppeli.makeForm("presidential pardon", "Rigo");
		std::cout << *pradon << std::endl;
		joestar.signForm(*pradon);
		joestar.executeForm(*pradon);
		delete pradon;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	std::srand(time(NULL));
	internInvalidTest();
	internShrubberyTest();
	internRobotomyTest();
	internPresidentialTest();
	shrubberyMixTest();
	robotomyMixTest();
	presidentialMixTest();

	std::cout <<  "\n*** Leak checks ***"  << std::endl;
	system("leaks intern");
	return 0;
}
