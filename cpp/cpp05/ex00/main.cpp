/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:15:47 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:15:48 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testOne() {
	std::cout << "*** tests with invalid grade value ***" << std::endl;
	try {
		Bureaucrat tom("Tom", 200);
		std::cout << tom << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat tom("Tom", -1);
		std::cout << tom << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "*** tests with valid grade value ***" << std::endl;
	try {
		Bureaucrat tom("Tom", 100);
		std::cout << tom << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testTwo() {
	std::cout << "*** tests with increment ***" << std::endl;
	try {
		Bureaucrat spike("Spike", 2);
		std::cout << spike << std::endl;
		spike.incrementGrade();
		std::cout << spike << std::endl;
		spike.incrementGrade();
		std::cout << spike << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "*** tests with decrement ***" << std::endl;
	try {
		Bureaucrat tyke("Tyke", 149);
		std::cout << tyke << std::endl;
		tyke.decrementGrade();
		std::cout << tyke << std::endl;
		tyke.decrementGrade();
		std::cout << tyke << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	testOne();
	testTwo();
	return 0;
}
