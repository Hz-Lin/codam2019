/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:27:36 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:32:53 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	createForm(){

    std::cout << "*** Create form with invalid input ***" << std::endl;
    try{
        Form formOne("FormOne", 300, 30);
        std::cout << formOne.getName() << std::endl;
        std::cout << formOne.getGradeSign() << std::endl;
        std::cout << formOne << std::endl;
    }
    catch(Form::GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }

    try{
        Form formOne("FormOne", -1, 30);
        std::cout << formOne.getName() << std::endl;
        std::cout << formOne.getGradeSign() << std::endl;
        std::cout << formOne << std::endl;
    }
    catch(Form::GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }

    try{
        Form formOne("FormOne", 100, 300);
        std::cout << formOne.getName() << std::endl;
        std::cout << formOne.getGradeSign() << std::endl;
        std::cout << formOne << std::endl;
    }
    catch(Form::GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }

    try{
        Form formOne("FormOne", 100, -1);
        std::cout << formOne.getName() << std::endl;
        std::cout << formOne.getGradeSign() << std::endl;
        std::cout << formOne << std::endl;
    }
    catch(Form::GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "*** Create form with valid input ***" << std::endl;
    try{
        Form formOne("formOne", 100, 10);
        std::cout << formOne << std::endl;
    }
    catch(Form::GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void	signForm() {
    std::cout << "*** Bureaucrat grade lower than form grade required to sign ***" << std::endl;
    try {
        Form formTwo("FormTwo", 50, 100);
        std::cout << formTwo << std::endl;
        Bureaucrat tom("Tom", 80);
        std::cout << tom << std::endl;
        tom.signForm(formTwo);
    }
    catch (Form::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::FormAlreadySignedException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "*** Bureaucrat grade higher than form grade required to sign ***" << std::endl;
    try {
        Form formTwo("FormTwo", 50, 100);
        std::cout << formTwo << std::endl;
        Bureaucrat tom("Tom", 30);
        std::cout << tom << std::endl;
        tom.signForm(formTwo);
        std::cout << formTwo << std::endl; //show the form is signed
        formTwo.beSigned(tom); //try to sign an already signed form
    }
    catch (Form::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::FormAlreadySignedException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void mixTest() {
    try {
        std::cout << "*** Mix Tests ***" << std::endl;
        Bureaucrat  jerry("Jerry", 100);
        Form    buildPermit("Building and Construction Permit", 99, 80);
        Form    parkingPermit("Car Parking Permit", 100, 120);

        std::cout << jerry << std::endl;
        std::cout << buildPermit << std::endl;
        std::cout << parkingPermit << std::endl;

        jerry.signForm(buildPermit); //not enough grade
        jerry.signForm(parkingPermit); //signed
        std::cout << buildPermit << std::endl;
        std::cout << parkingPermit << std::endl << std::endl;

        jerry.incrementGrade();
        std::cout << jerry << std::endl;
        jerry.signForm(buildPermit);
        std::cout << buildPermit << std::endl << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(){
    createForm();
    signForm();
    mixTest();
	return 0;
}
