/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 10:40:12 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/09 10:40:13 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Conversion.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << RED "One argument is expected." RESET << std::endl;
        return 1;
    }
    Conversion conversion(argv[1]);
    if (!conversion.checkInputType()) {
        std::cerr << RED "Invalid argument, only accept: char, int, float, double." RESET << std::endl;
        return 1;
    }
    else {
            conversion.outputConversion();
    }
    return 0;
}
