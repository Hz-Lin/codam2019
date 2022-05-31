/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:42:39 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:42:40 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("Presidential Pardon", 25, 5) {
    setTarget(target);
    std::cout << BLUE "Presidential Pardon Form on " << getTarget() << " has been created." RESET <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) :
AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
    setTarget(obj.getTarget());
    std::cout << BLUE "Presidential Pardon Form on " << getTarget() << " has been copied." RESET <<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << BLUE "Presidential Pardon Form on " << getTarget() << " has been destroyed." RESET <<std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj) {
        setTarget(obj.getTarget());
    }
    std::cout << BLUE "Presidential Pardon Form on " << getTarget() << " has been assigned." RESET <<std::endl;
    return *this;
}

void PresidentialPardonForm::action() const {
    std::cout << YELLOW << getTarget() << " has been pardoned by Zaphod Beeblebrox." RESET << std::endl;
}
