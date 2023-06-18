/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:34:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 23:53:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << WHITE << "Intern is born." << RESET << std::endl;
}

Intern::Intern(Intern const& src) {
    *this = src;
}

Intern::~Intern() {
    std::cout << WHITE << "Intern is dead." << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& rhs) {
    (void)rhs;
    return *this;
}

/* Member Functions */
AForm* Intern::_makePresidentialPardonForm(std::string const& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::_makeRobotomyRequestForm(std::string const& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::_makeShrubberyCreationForm(std::string const& target)
{
    return new ShrubberyCreationForm(target);
}

/* makeForm() */
AForm* Intern::makeForm(std::string const& name, std::string const& target) {
    AForm* (Intern::*makeForm[3])(std::string const& target) = {
        &Intern::_makePresidentialPardonForm,
        &Intern::_makeRobotomyRequestForm,
        &Intern::_makeShrubberyCreationForm
    };
    std::string formNames[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << GREEN << "Intern creates " << formNames[i] << " form."
                << RESET << std::endl;
            return (this->*makeForm[i])(target);
        }
    }
    throw Intern::FormNotCreated();
}

/* Exceptions */
const char* Intern::FormNotCreated::what() const throw() {
    return ("form was not created.");
}




