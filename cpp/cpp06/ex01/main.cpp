/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 10:41:42 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/09 10:41:43 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main() {
    Data *original = new Data;
    original->name = "Hz Lin";
    original->age = 30;

    uintptr_t serialized = serialize(original);
    Data *deserialized = deserialize(serialized);

    std::cout << BLUE << "*** DATA INFO ***" << std::endl;
    std::cout << "Original:     " << "I'm " << original->name << ", and my age is " << original->age << std::endl;
    std::cout << "Deserialized: " << "I'm " << deserialized->name << ", and my age is " << deserialized->age << std::endl;
    std::cout << RESET << std::endl;

    std::cout << YELLOW << "*** ADDRESSES ***" << std::endl;
    std::cout << "Original:     " << original << std::endl;
    std::cout << "Serialized:   " << serialized << std::endl;
    std::cout << "Deserialized: " << deserialized  << RESET << std::endl;

    delete original;
    return 0;
}
