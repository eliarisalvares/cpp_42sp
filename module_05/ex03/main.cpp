/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:04:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/18 15:02:37 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << BLUE << "Creating bureaucrats: " << RESET << std::endl;
    Bureaucrat b1("b1", 100);
    Bureaucrat b2("b2", 50);
    Bureaucrat b3("b3", 5);

    std::cout << std::endl;
    std::cout << BLUE << "Creating intern: " << RESET << std::endl;
    Intern someRandomIntern;

    std::cout << std::endl;
    std::cout << BLUE << "Intern makes a presidential pardon form: " << RESET << std::endl;
    AForm* form1 = someRandomIntern.makeForm("presidential pardon", "Bender");

    std::cout << std::endl;
    std::cout << BLUE << "Intern makes a shrubbery creation form: " << RESET << std::endl;
    AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "Bender");

    std::cout << std::endl;
    std::cout << BLUE << "Intern makes a robotomy request form: " << RESET << std::endl;
    AForm* form3 = someRandomIntern.makeForm("robotomy request", "Bender");

    std::cout << BLUE << "Bureaucrat b1 tries to sign the presidential pardon form: " << RESET << std::endl;
    b1.signForm(*form1);

    std::cout << std::endl;
    std::cout << BLUE << "Bureaucrat b2 tries to sign the shrubbery creation form: " << RESET << std::endl;
    b2.signForm(*form2);

    std::cout << std::endl;
    std::cout << BLUE << "Bureaucrat b3 tries to sign the robotomy request form: " << RESET << std::endl;
    b3.signForm(*form3);

    std::cout << std::endl;
    std::cout << BLUE << "Deleting forms: " << RESET << std::endl;
    delete form1;
    delete form2;
    delete form3;

    std::cout << BLUE << "End of scope: " << RESET << std::endl;
    return (0);
}
