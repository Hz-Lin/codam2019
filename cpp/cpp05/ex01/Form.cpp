/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:27:23 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:27:24 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _gradeSign(0), _gradeExecute(0){
}

Form::Form(const std::string &name, const int &gradeSign, const int &gradeExecute) :
_formName(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
    if (gradeSign > 150 || gradeExecute > 150) {
        throw Form::GradeTooLowException();
    }
    if (gradeSign < 1 || gradeExecute < 1) {
        throw Form::GradeTooHighException();
    }
    std::cout << BLUE "Form " << _formName << " has been created." RESET << std::endl;
}

Form::Form(const Form &obj) :
_formName(obj._formName), _isSigned(obj._isSigned), _gradeSign(obj._gradeSign), _gradeExecute(obj._gradeExecute) {
    std::cout << BLUE "Form " << _formName << " has been copied." RESET << std::endl;
}

Form::~Form() {
    std::cout << BLUE "Form " << _formName << " has been destroyed." RESET << std::endl;
}

Form &Form::operator=(const Form &obj) {
    if (this != &obj) {
        (void) obj;
    }
    std::cout << BLUE "Form " << _formName << " has been assigment." RESET << std::endl;
    return *this;
}

const std::string &Form::getName() const {
    return _formName;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExecute() const {
    return _gradeExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (_isSigned) {
        throw Form::FormAlreadySignedException();
    }
    if (bureaucrat.getGrade() > _gradeSign) {
        throw Bureaucrat::GradeTooLowException();
    }
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return MAGENTA "Grade of the form is too high. Grade must be between 1 and 150." RESET;
}

const char *Form::GradeTooLowException::what() const throw() {
    return MAGENTA "Grade of the form is too low. Grade must be between 1 and 150." RESET;
}

const char *Form::FormAlreadySignedException::what() const throw() {
    return MAGENTA "Form is already signed." RESET;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << CYAN << "Form name: " << form.getName()
    << ", signed status: " << std::boolalpha << form.getIsSigned()
    << ", grade to sign: " << form.getGradeSign()
    << ", grade to execute: " << form.getGradeExecute() << RESET;
    return os;
}
