/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:42:24 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/18 14:58:05 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    {
        std::cout << YELLOW << "Creating bureaucrats: " << RESET << std::endl;
        Bureaucrat* b1 = new Bureaucrat("Bureaucrat with grade 1", 1);
        Bureaucrat* b2 = new Bureaucrat("Bureaucrat with grade 150", 150);

        std::cout << std::endl;
        std::cout << YELLOW << "Bureaucrat with grade 1: "
            << RESET << std::endl;
        std::cout << *b1 << std::endl;

        std::cout << YELLOW << "Bureaucrat with grade 150: "
            << RESET << std::endl;
        std::cout << *b2 << std::endl;

        std::cout << YELLOW << "Trying to increment bureaucrat with grade 1: "
            << RESET << std::endl;
        try {
            b1->incrementGrade();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << YELLOW << "Trying to decrement bureaucrat with grade 150: "
            << RESET << std::endl;
        try {
            b2->decrementGrade();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << YELLOW << "Deleting bureaucrats: " << RESET
            << std::endl;
        delete b1;
        delete b2;
    }
    {
        std::cout << std::endl;
        std::cout << YELLOW << "Creating new bureaucrats: " << RESET
            << std::endl;
        Bureaucrat* b1 = new Bureaucrat("Bureaucrat with grade 2", 2);
        Bureaucrat* b2 = new Bureaucrat("Bureaucrat with grade 149", 149);

        std::cout << std::endl;
        std::cout << YELLOW << "Bureaucrat with grade 2: "
            << RESET << std::endl;
        std::cout << *b1 << std::endl;

        std::cout << YELLOW << "Bureaucrat with grade 149: "
            << RESET << std::endl;
        std::cout << *b2 << std::endl;

        std::cout << YELLOW << "Trying to increment bureaucrat with grade 2: "
            << RESET << std::endl;
        try {
            b1->incrementGrade();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << YELLOW << "Trying to decrement bureaucrat with grade 149: "
            << RESET << std::endl;
        try {
            b2->decrementGrade();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << YELLOW << "Deleting bureaucrats: " << RESET
            << std::endl;
        delete b1;
        delete b2;
    }
    return (0);
}
