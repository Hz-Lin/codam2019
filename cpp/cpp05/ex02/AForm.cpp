/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:36:02 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:36:05 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _gradeSign(0), _gradeExecute(0){
}

AForm::AForm(const std::string &name, const int &gradeSign, const int &gradeExecute) :
_formName(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
    if (gradeSign > 150 || gradeExecute > 150) {
        throw AForm::GradeTooLowException();
    }
    if (gradeSign < 1 || gradeExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    std::cout << BLUE "Form " << _formName << " has been created." RESET << std::endl;
}

AForm::AForm(const AForm &obj) :
_formName(obj._formName), _isSigned(obj._isSigned), _gradeSign(obj._gradeSign), _gradeExecute(obj._gradeExecute) {
    std::cout << BLUE "Form " << _formName << " has been copied." RESET << std::endl;
}

AForm::~AForm() {
    std::cout << BLUE "Form " << _formName << " has been destroyed." RESET << std::endl;
}

AForm &AForm::operator=(const AForm &obj) {
    if (this != &obj) {
        (void) obj;
    }
    std::cout << BLUE "Form " << _formName << " has been assigment." RESET << std::endl;
    return *this;
}

void AForm::setTarget(const std::string &target) {
    _target = target;
}

const std::string &AForm::getName() const {
    return _formName;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeSign() const {
    return _gradeSign;
}

int AForm::getGradeExecute() const {
    return _gradeExecute;
}

const std::string &AForm::getTarget() const {
    return _target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (_isSigned) {
        throw AForm::FormAlreadySignedException();
    }
    if (bureaucrat.getGrade() > _gradeSign) {
        throw Bureaucrat::GradeTooLowException();
    }
    _isSigned = true;
}

void AForm::execute(Bureaucrat const &bureaucrat) const {
    if (!_isSigned) {
        throw AForm::FormNotSignedException();
    }
    if (bureaucrat.getGrade() > _gradeExecute) {
        throw Bureaucrat::GradeTooLowException();
    }
    action(); // the pure virtual fuction
}

const char *AForm::GradeTooHighException::what() const throw() {
    return MAGENTA "Grade of the form is too high. Grade must be between 1 and 150." RESET;
}

const char *AForm::GradeTooLowException::what() const throw() {
    return MAGENTA "Grade of the form is too low. Grade must be between 1 and 150." RESET;
}

const char *AForm::FormAlreadySignedException::what() const throw() {
    return MAGENTA "Form is already signed." RESET;
}

const char *AForm::FormNotSignedException::what() const throw() {
    return MAGENTA "Form is not signed." RESET;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << CYAN << "Form name: " << form.getName()
    << ", signed status: " << std::boolalpha << form.getIsSigned()
    << ", grade to sign: " << form.getGradeSign()
    << ", grade to execute: " << form.getGradeExecute() << RESET;
    return os;
}
