/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:37:35 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:37:36 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
AForm("Shrubbery Creation", 145, 137) {
    setTarget(target);
    std::cout << BLUE "Shrubbery Creation Form on " << getTarget() << " has been created." RESET <<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) :
AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
    setTarget(obj.getTarget());
    std::cout << BLUE "Shrubbery Creation Form on " << getTarget() << " has been copied." RESET <<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << BLUE "Shrubbery Creation Form on " << getTarget() << " has been destroyed." RESET <<std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (this != &obj) {
        setTarget(obj.getTarget());
    }
    std::cout << BLUE "Shrubbery Creation Form on " << getTarget() << " has been assigned." RESET <<std::endl;
    return *this;
}

void ShrubberyCreationForm::action() const {
    std::ofstream myFile;
    std::string fileName = getTarget() + "_shrubbery";
    myFile.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
    if (!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    myFile << "               ,@@@@@@@,\n"
           << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
           << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
           << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
           << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
           << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
           << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
           << "       |o|        | |         | |\n"
           << "       |.|        | |         | |\n"
           << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ ";

    myFile.close();
}
