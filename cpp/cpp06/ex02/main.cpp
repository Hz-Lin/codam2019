/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 10:42:46 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/09 13:54:56 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time

// Dynamic_cast can only be used with pointers and references to polymorphic class types (contain at least one virtual function)
// because only pointers to polymorphic class types contain the information that the dynamic_cast<>() operator needs to check the validity of the conversion
// cast is checked dynamically (executing / at run time), so it may fail at run time, code have to handle the potential failures

Base *generate() {
    int randomCase = std::rand() % 3;
    if (randomCase == 0) {
        std::cout << YELLOW << "A has been generated." RESET << std::endl;
        return new A();
    }
    else if (randomCase == 1) {
        std::cout << YELLOW << "B has been generated." RESET << std::endl;
        return new B();
    }
    else {
        std::cout << YELLOW << "C has been generated." RESET << std::endl;
        return new C();
    }
}

void identify(Base *p) {
    A *ptrA = dynamic_cast<A*>(p);
    if (ptrA) {
        std::cout << BLUE << "A" << RESET << std::endl;
        return;
    }
    B *ptrB = dynamic_cast<B*>(p);
    if (ptrB) {
        std::cout << BLUE << "B" << RESET << std::endl;
        return;
    }
    C *ptrC = dynamic_cast<C*>(p);
    if (ptrC) {
        std::cout << BLUE << "C" << RESET << std::endl;
        return;
    }
}

void identify(Base &p) {
    try {
        A &refA = dynamic_cast<A&>(p);
        (void)refA;
        std::cout << CYAN << "A" << RESET << std::endl;
    } catch (std::exception &e) {}
    try {
        B &refB = dynamic_cast<B&>(p);
        (void)refB;
        std::cout << CYAN << "B" << RESET << std::endl;
    } catch (std::exception &e) {}
    try {
        C &refC = dynamic_cast<C&>(p);
        (void)refC;
        std::cout << CYAN << "C" << RESET << std::endl;
    } catch (std::exception &e) {}
}

int main() {
    std::srand(std::time(NULL));
    Base *basePtr = generate();
    Base &baseRef = *basePtr;

    std::cout << "Type (pointer): ";
    identify(basePtr);

    std::cout << "Type (reference): ";
    identify(baseRef);

    delete basePtr;

    std::cout << "*** LEAK CHECK ***" << std::endl;
    system("leaks realtype");

    return 0;
}
