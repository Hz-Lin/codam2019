/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:36:54 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:46:10 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void ShrubberyCreationFormTest() {
	try {
		std::cout << "\n*** ShrubberyCreationForm Tests" << std::endl;
		Bureaucrat low("low", 150);
		Bureaucrat high("high", 100);
		ShrubberyCreationForm doubleTree("DoubleTree");
		std::cout << low << std::endl;
		std::cout << high << std::endl;
		std::cout << doubleTree << std::endl;

		std::cout << "\nExecute ShrubberyCreationForm without sign" << std::endl;
		high.executeForm(doubleTree);

		std::cout << "\nExecute ShrubberyCreationForm with lower graded bureaucrat" << std::endl;
		high.signForm(doubleTree);
		low.executeForm(doubleTree);
		std::cout << "\nExecute ShrubberyCreationForm with higher graded bureaucrat" << std::endl;
		high.executeForm(doubleTree);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void RobotomyRequestFormTest() {
	try {
		std::cout << "\n*** RobotomyRequestForm Tests" << std::endl;
		Bureaucrat low("low", 100);
		Bureaucrat high("high", 30);
		RobotomyRequestForm robot("Dio Brando");
		std::cout << low << std::endl;
		std::cout << high << std::endl;
		std::cout << robot << std::endl;

		std::cout << "\nExecute RobotomyRequestForm without sign" << std::endl;
		high.executeForm(robot);

		std::cout << "\nExecute RobotomyRequestForm with lower graded bureaucrat" << std::endl;
		high.signForm(robot);
		low.executeForm(robot);
		std::cout << "\nExecute RobotomyRequestForm with higher graded bureaucrat" << std::endl;
		high.executeForm(robot);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void PresidentialPardonFormTests() {
    try {
		std::cout << "\n*** PresidentialPardonForm Tests" << std::endl;
		Bureaucrat low("low", 30);
        Bureaucrat high("high", 3);
        PresidentialPardonForm pardon("Jolyne Cujoh");
        std::cout << low << std::endl;
        std::cout << high << std::endl;
        std::cout << pardon << std::endl;

		std::cout << "\nExecute PresidentialPardonForm without sign" << std::endl;
		high.executeForm(pardon);

		std::cout << "\nExecute PresidentialPardonForm with lower graded bureaucrat" << std::endl;
        high.signForm(pardon);
		low.executeForm(pardon);
		std::cout << "\nExecute PresidentialPardonForm with higher graded bureaucrat" << std::endl;
		high.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
	//If random numbers are generated with rand() without first calling srand()
	// /program will create the same sequence of numbers each time it runs.
    std::srand(time(NULL));
	ShrubberyCreationFormTest();
	RobotomyRequestFormTest();
	PresidentialPardonFormTests();
    return 0;
}
