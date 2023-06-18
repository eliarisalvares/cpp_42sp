/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:18:26 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/18 15:03:25 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* Canonical Functions */
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
        std::cout << WHITE << "PresidentialPardonForm created."
            << RESET << std::endl;
        std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& s)
    : AForm(s), _target(s._target) {
        *this = s;
        std::cout << WHITE << "PresidentialPardonForm copied."
            << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << WHITE << "PresidentialPardonForm destroyed."
        << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=
    (PresidentialPardonForm const& rhs) {
    if (this != &rhs) {
        this->_target = rhs._target;
    }
    return (*this);
}

/* Accessors */
std::string PresidentialPardonForm::getTarget(void) const {
    return (this->_target);
}

/* Other Functions */
void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (this->getIsSigned() == false) {
        throw AForm::FormNotSignedException();
    } else if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    } else {
        std::cout << PURPLE << this->_target
            << " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
    }
}
