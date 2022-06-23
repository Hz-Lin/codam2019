/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:32:14 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/22 10:58:20 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <array>
#include <list>
#include <deque>

void vectorTest() {
    std::cout << BLUE "*** Vector Test ***" RESET << std::endl;
    std::vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(6);
    myVector.push_back(-8);
    myVector.push_back(2);
    myVector.push_back(1);

    try {
        std::vector<int>::iterator found = easyfind(myVector, 6);
        std::cout << CYAN "Int " << *found << " found at index " << std::distance(myVector.begin(), found) << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::vector<int>::iterator found = easyfind(myVector, 3);
        std::cout << CYAN "Int " << *found << " found at index " << std::distance(myVector.begin(), found) << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void dequeTest() {
    std::cout << BLUE "*** Deque Test ***" RESET << std::endl;
    std::deque<int> myDeque;
    myDeque.push_back(10);
    myDeque.push_back(6);
    myDeque.push_back(8);
    myDeque.push_back(2);
    myDeque.push_back(1);

    try {
        std::deque<int>::iterator found = easyfind(myDeque, 6);
        std::cout << CYAN "Int " << *found << " found at index " << std::distance(myDeque.begin(), found) << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::deque<int>::iterator found = easyfind(myDeque, 3);
        std::cout << CYAN "Int " << *found << " found at index " << std::distance(myDeque.begin(), found) << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void listTest() {
    std::cout << BLUE "*** List Test ***" RESET << std::endl;
    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(6);
    myList.push_back(8);
    myList.push_back(200);
    myList.push_back(0);

    try {
        std::list<int>::iterator found = easyfind(myList, 6);
        std::cout << CYAN "Int " << *found << " found at index " << std::distance(myList.begin(), found) << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::list<int>::iterator found = easyfind(myList, 3);
        std::cout << CYAN "Int " << *found << " found at index " << std::distance(myList.begin(), found) << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    dequeTest();
	std::cout << std::endl;
    vectorTest();
	std::cout << std::endl;
    listTest();
    return 0;
}
