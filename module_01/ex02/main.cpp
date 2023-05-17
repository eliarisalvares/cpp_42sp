/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:02:48 by elraira-          #+#    #+#             */
/*   Updated: 2023/05/17 20:26:39 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> /* cout, endl */
#include <string> /* string */
/* ANSI COLOR CODES */
#define RESET "\033[0m"
#define GREEN "\033[32m"

/**
 * @brief This exercise is about references and pointers. A stringPTR and a
 * stringREF are created.
 * Both pointers and references are are used to have one variable point to
 * another variable. A pointer is a variable that holds the address of another
 * variable. A reference is a variable that is an alias for another variable.
 * The difference between a pointer and a reference is that a pointer can be
 * reassigned to point to another variable, while a reference cannot be
 * reassigned to refer to another variable. A reference must be initialized
 * when it is created. A pointer can be initialized at any time. A reference
 * cannot be NULL while a pointer can be NULL.
 * A pointer also has its own address, while a reference does not. A reference
 * shares the same address as the variable it refers to but still takes up
 * storage space.
 *
 */
int	main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << GREEN << "Addresses:" << RESET << std::endl;
    std::cout << "The address of strPTR is: " << &stringPTR << std::endl;
    std::cout << "The address of str is: " << &str << std::endl;
    std::cout << "The address of stringREF is: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << GREEN << "Address held:" << RESET << std::endl;
    std::cout << "The address held by stringPTR: " << stringPTR << std::endl;
    std::cout << std::endl;
    std::cout << GREEN << "Values:" << RESET << std::endl;
    std::cout << "The value of stringPTR is: " << stringPTR << std::endl;
    std::cout << "The value of stringREF is: " << stringREF << std::endl;
    std::cout << std::endl;
    std::cout << GREEN << "Values pointed to/referenced:" << RESET << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value referenced by stringREF: " << stringREF << std::endl;
    return (0);
}
