/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:42:49 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:42:50 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("Robotomy Request", 72, 45) {
    setTarget(target);
    std::cout << BLUE "Robotomy Request Form on " << getTarget() << " has been created." RESET <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) :
AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
    setTarget(obj.getTarget());
    std::cout << BLUE "Robotomy Request Form on " << getTarget() << " has been copied." RESET <<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << BLUE "Robotomy Request Form on " << getTarget() << " has been destroyed." RESET <<std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this != &obj) {
        setTarget(obj.getTarget());
    }
    std::cout << BLUE "Robotomy Request Form on " << getTarget() << " has been assigned." RESET <<std::endl;
    return *this;
}

void RobotomyRequestForm::action() const {
    std::cout << YELLOW << "drilling noises: Rrrzzz Rrrzzz Rrrzzz" RESET << std::endl;
    if (std::rand() % 2) {
        std::cout << YELLOW << getTarget() << " has been robotomized successfull." RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "The robotomy on " << getTarget() << " has failed." RESET << std::endl;
    }
}
