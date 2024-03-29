/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 13:03:37 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/14 13:03:39 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750

void subjectTest() {
    std::cout << BLUE << "*** SUBJECT TEST ***" << RESET << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return;
        }
    }
    try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

void defaultConstructorTest() {
    std::cout << std::endl;
    std::cout << BLUE << "*** DEFAULT CONSTRUCTOR TEST ***" << RESET << std::endl;
    Array<int> empty; //need a typename to instantiate
    std::cout << MAGENTA << "Size: " << empty.size() << RESET << std::endl;
    try {
        std::cout << empty[0] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        empty[0] = 10;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void deepCopyTest() {
    std::cout << std::endl;
    std::cout << BLUE << "*** DEEP COPY TEST ***" << RESET << std::endl;
    unsigned int size = 6;
    Array<char> original(size);
    original[0] = 'H';
    original[1] = 'e';
    original[2] = 'l';
    original[3] = 'l';
    original[4] = 'o';
    original[5] = '.';

    std::cout << MAGENTA << "Size of original: " << original.size() << RESET << std::endl;
    std::cout << MAGENTA << "the 5th element of original: " << original[4] << RESET << std::endl;

    std::cout << CYAN << "Original: " << original << RESET << std::endl;
    Array<char> copied(original); //call the copy constructor
    std::cout << CYAN << "Copied:   " << copied << RESET << std::endl;
    Array<char> assigned(size);
    assigned = original; //use the assigment operator
    std::cout << CYAN << "Assigned: " << assigned << RESET << std::endl;

    std::cout << std::endl;
    std::cout << MAGENTA << "Size of copied: " << copied.size() << RESET << std::endl;
    std::cout << MAGENTA << "the 2th element of copied: " << copied[1] << RESET << std::endl;
    try {
        copied[1] = 'a';
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << CYAN << "After changing the 3th element of copied" << std::endl;
    std::cout << CYAN << "Original: " << original << RESET << std::endl;
    std::cout << CYAN << "Copied:   " << copied << RESET << std::endl;
    std::cout << CYAN << "Assigned: " << assigned << RESET << std::endl;

    std::cout << std::endl;
    std::cout << MAGENTA << "Size of assigned: " << assigned.size() << RESET << std::endl;
    std::cout << MAGENTA << "the 2th element of assigned: " << assigned[5] << RESET << std::endl;
    try {
        assigned[5] = '!';
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << CYAN << "After changing the 6th element of assigned" << std::endl;
    std::cout << CYAN << "Original: " << original << RESET << std::endl;
    std::cout << CYAN << "Copied:   " << copied << RESET << std::endl;
    std::cout << CYAN << "Assigned: " << assigned << RESET << std::endl;
}

int main(int, char**)
{
    subjectTest();
    defaultConstructorTest();
    deepCopyTest();
    return 0;
}
