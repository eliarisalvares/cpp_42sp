/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:04:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 23:16:42 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << YELLOW << "Creating bureaucrats: " << RESET << std::endl;
    Bureaucrat b1("b1", 100);
    Bureaucrat b2("b2", 50);
    Bureaucrat b3("b3", 5);

    std::cout << std::endl;
    std::cout << YELLOW << "Creating forms: " << RESET << std::endl;
    ShrubberyCreationForm f1("f1");
    RobotomyRequestForm r1("r1");
    PresidentialPardonForm p1("p1");

    std::cout << std::endl;
    std::cout << YELLOW << "Bureaucrats: " << RESET << std::endl;
    std::cout << "b1: " << std::endl;
    std::cout << b1;
    std::cout << "b2: " << std::endl;
    std::cout << b2;
    std::cout << "b3: " << std::endl;
    std::cout << b3;

    std::cout << std::endl;
    std::cout << YELLOW << "Forms: " << RESET << std::endl;
    std::cout << "f1: " << std::endl;
    std::cout << f1 << std::endl;
    std::cout << "r1: " << std::endl;
    std::cout << r1 << std::endl;
    std::cout << "p1: " << std::endl;
    std::cout << p1 << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "Trying to sign forms: " << RESET << std::endl;
    std::cout << "b1 tries to sign f1: " << std::endl;
    b1.signForm(f1);
    std::cout << "b1 tries to sign r1: " << std::endl;
    b1.signForm(r1);
    std::cout << "b1 tries to sign p1: " << std::endl;
    b1.signForm(p1);

    std::cout << std::endl;
    std::cout << "b2 tries to sign f1: " << std::endl;
    b2.signForm(f1);
    std::cout << "b2 tries to sign r1: " << std::endl;
    b2.signForm(r1);
    std::cout << "b2 tries to sign p1: " << std::endl;
    b2.signForm(p1);

    std::cout << std::endl;
    std::cout << "b3 tries to sign f1: " << std::endl;
    b3.signForm(f1);
    std::cout << "b3 tries to sign r1: " << std::endl;
    b3.signForm(r1);
    std::cout << "b3 tries to sign p1: " << std::endl;
    b3.signForm(p1);

    std::cout << std::endl;
    std::cout << YELLOW << "Trying to execute forms: " << RESET << std::endl;
    std::cout << "b1 tries to execute f1: " << std::endl;
    b1.executeForm(f1);
    std::cout << "b1 tries to execute r1: " << std::endl;
    b1.executeForm(r1);
    std::cout << "b1 tries to execute p1: " << std::endl;
    b1.executeForm(p1);

    std::cout << std::endl;
    std::cout << "b2 tries to execute f1: " << std::endl;
    b2.executeForm(f1);
    std::cout << "b2 tries to execute r1: " << std::endl;
    b2.executeForm(r1);
    std::cout << "b2 tries to execute p1: " << std::endl;
    b2.executeForm(p1);

    std::cout << std::endl;
    std::cout << "b3 tries to execute f1: " << std::endl;
    b3.executeForm(f1);
    std::cout << "b3 tries to execute r1: " << std::endl;
    b3.executeForm(r1);
    std::cout << "b3 tries to execute p1: " << std::endl;
    b3.executeForm(p1);

    std::cout << std::endl;
    std::cout << YELLOW << "End of scope: " << RESET << std::endl;
}
