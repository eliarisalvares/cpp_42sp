/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:04:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 23:55:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << YELLOW << "Creating bureaucrats: " << RESET << std::endl;
    Bureaucrat b1("b1", 100);
    Bureaucrat b2("b2", 50);
    Bureaucrat b3("b3", 5);

    std::cout << std::endl;
    std::cout << YELLOW << "Calling Intern: " << RESET << std::endl;
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    delete rrf;
}
