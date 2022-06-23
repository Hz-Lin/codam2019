/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:33:19 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/22 11:04:51 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void mutantStackTest() {
    std::cout << BLUE "*** Mutant Stack Test ***" RESET << std::endl;
    MutantStack<int> mlist;

    std::cout << YELLOW "mutant stack is empty: " << mlist.empty() << std::endl;

    mlist.push(5);
    mlist.push(17);
    std::cout << YELLOW "mutant stack is empty: " << mlist.empty() << std::endl;
    std::cout << CYAN "Top Element is : " << mlist.top() << RESET << std::endl;
    mlist.pop();
    std::cout << CYAN "Top Element is : " << mlist.top() << RESET << std::endl;
    std::cout << YELLOW "mutant stack size : " << mlist.size() << std::endl;

    mlist.push(3);
    mlist.push(5);
    mlist.push(737);
    mlist.push(-42);
    mlist.push(0);

    MutantStack<int>::iterator it = mlist.begin();
    MutantStack<int>::iterator ite = mlist.end();
    ++it;
    --it;
    std::cout << BLUE "*** Mutant Stack Test - Iterator ***" RESET << std::endl;
    int i = 0;
    while (it != ite)
    {
        std::cout << MAGENTA "Index " << i << ": " << *it << RESET << std::endl;
        ++it;
        i++;
    }

    MutantStack<int>::reverseIterator rit = mlist.rbegin();
    MutantStack<int>::reverseIterator rite = mlist.rend();
    ++rit;
    --rit;
    std::cout << BLUE "*** Mutant Stack Test - Reverse Iterator ***" RESET << std::endl;
    i--;
    while (rit != rite){
        std::cout << MAGENTA "index " << i << ":  " <<  *rit << RESET << std::endl;
        ++rit;
        i--;
    }
}

void listTest() {
    std::cout << BLUE "*** List Test ***" RESET << std::endl;
    std::list<int> mlist;

    std::cout << YELLOW "list is empty: " << mlist.empty() << std::endl;

    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << YELLOW "List is empty: " << mlist.empty() << std::endl;
    std::cout << CYAN "Last Element is : " << mlist.back() << RESET << std::endl;
    mlist.pop_back();
    std::cout << CYAN "Last Element is : " << mlist.back() << RESET << std::endl;
    std::cout << YELLOW "list size : " << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(-42);
    mlist.push_back(0);

    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    std::cout << BLUE "*** List Test - Iterator ***" RESET << std::endl;
    int i = 0;
    while (it != ite)
    {
        std::cout << MAGENTA "Index " << i << ": " << *it << RESET << std::endl;
        ++it;
        i++;
    }

    std::list<int>::reverse_iterator rit = mlist.rbegin();
    std::list<int>::reverse_iterator rite = mlist.rend();
    ++rit;
    --rit;
    std::cout << BLUE "*** List - Reverse Iterator ***" RESET << std::endl;
    i--;
    while (rit != rite){
        std::cout << MAGENTA "index " << i << ":  " <<  *rit << RESET << std::endl;
        ++rit;
        i--;
    }
}

int main()
{
    mutantStackTest();
    std::cout << std::endl;
    listTest();
    return 0;
}
