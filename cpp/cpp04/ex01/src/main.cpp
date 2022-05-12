/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 17:53:57 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/11 17:53:58 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void	subjectTest() {
    std::cout << "\nMain provided by subject:" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
}

void	animalArray(){
    std::cout << "\nAnimal array:" << std::endl;
    Animal *animals [6];
    // create an array of animals
    for (int i = 0; i < 6; i++) {
        if (i % 2 == 1) {
            animals[i] = new Dog();
        }
        else {
            animals[i] = new Cat();
        }
    }
    // print animal types
    for (int i = 0; i < 6; i++) {
        std::cout << "Type of animal: " << animals[i]->getType() << std::endl;
    }
    // clean the array
    for (int i = 0; i < 6; i++) {
        delete animals[i];
    }
}

void	deepcopyTest(){
    std::cout << "\nDeepcopy Test (with new):" << std::endl;
    const Dog* hond = new Dog();
    const Cat* kat = new Cat();
    const Dog* copyHond = new Dog(*hond);
    const Cat* copyKat = new Cat(*kat);

    std::cout << "hond's brain: " << hond->getBrain() << std::endl;
    std::cout << "copyHond's brain: " << copyHond->getBrain() << std::endl;
    std::cout << "kat's brain: " << kat->getBrain() << std::endl;
    std::cout << "copyKat's brain: " << copyKat->getBrain() << std::endl;

    delete hond;
    delete kat;
    delete copyHond;
    delete copyKat;

    std::cout	<< "\nMore deepcopy Test" << std::endl;
    Dog ken;
    Cat neko;
    Dog copyKen(ken);
    Cat copyNeko(neko);

    std::cout << "ken's brain: " << ken.getBrain() << std::endl;
    std::cout << "copyKen's brain: " << copyKen.getBrain() << std::endl;
    std::cout << "neko's brain: " << neko.getBrain() << std::endl;
    std::cout << "copyNeko's brain: " << copyNeko.getBrain() << std::endl;
}

int	main(){
    subjectTest();
    animalArray();
    deepcopyTest();
    std::cout << "\ncheck for leaks:" << std::endl;
    system("leaks brain");
    return 0;
}
