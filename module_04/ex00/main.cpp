/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:19:16 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 21:28:53 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    {
        std::cout << RED << "-----------------------------------------"
            << "Testing Generic Animals" << RESET << std::endl;
        std::cout << BLUE_BACKGROUND << "Creating Animal, Dog and Cat"
            << RESET << std::endl;
        const Animal* animal = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << std::endl;
        std::cout << BLUE << "getType()" << RESET << std::endl;
        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;

        std::cout << std::endl;
        std::cout << BLUE << "makeSound()" << RESET << std::endl;
        cat->makeSound(); // will output the cat sound!
        dog->makeSound();
        animal->makeSound();

        std::cout << std::endl;
        std::cout << BLUE << "Delete Animal, Dog and Cat" << RESET << std::endl;
        delete animal;
        delete dog;
        delete cat;
    }
    {
        std::cout << std::endl;
        std::cout << RED << "-----------------------------------------"
            << "Testing Wrong Animals" << RESET << std::endl;
        std::cout << BLUE_BACKGROUND << "Creating WrongAnimal and WrongCat"
            << RESET << std::endl;
        const WrongAnimal* animal = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();

        std::cout << std::endl;
        std::cout << BLUE << "getType()" << RESET << std::endl;
        std::cout << cat->getType() << std::endl;

        std::cout << std::endl;
        std::cout << BLUE << "makeSound()" << RESET << std::endl;
        cat->makeSound();
        animal->makeSound();

        std::cout << std::endl;
        std::cout << BLUE << "Delete WrongAnimal and WrongCat" << RESET
            << std::endl;
        delete animal;
        delete cat;
    }
    {
        std::cout << std::endl;
        std::cout << RED << "-----------------------------------------"
            << "Testing subtypes" << RESET << std::endl;
        std::cout << BLUE_BACKGROUND << "Creating a lot of Animals"
            << RESET << std::endl;
        const Animal* animal = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        const WrongAnimal* wrongAnimal = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();
        const WrongCat* notCat = new WrongCat();

        std::cout << std::endl;
        std::cout << BLUE << "getType()" << RESET << std::endl;
        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;
        std::cout << wrongCat->getType() << std::endl;

        std::cout << std::endl;
        std::cout << BLUE << "makeSound()" << RESET << std::endl;
        animal->makeSound();
        dog->makeSound();
        cat->makeSound();
        wrongAnimal->makeSound();
        wrongCat->makeSound();
        notCat->makeSound();

        std::cout << std::endl;
        std::cout << BLUE << "Delete all" << RESET << std::endl;
        delete animal;
        delete dog;
        delete cat;
        delete wrongAnimal;
        delete wrongCat;
        delete notCat;
    }
    return 0;
}
