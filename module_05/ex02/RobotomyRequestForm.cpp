/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:31:20 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/18 15:01:17 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* Canonical Functions */
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
        std::cout << WHITE << "RobotomyRequestForm created."
            << RESET << std::endl;
        std::cout << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
    : AForm(src), _target(src._target) {
        *this = src;
        std::cout << WHITE << "RobotomyRequestForm copied."
            << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << WHITE << "RobotomyRequestForm destroyed."
        << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=
    (RobotomyRequestForm const& rhs) {
    if (this != &rhs) {
        this->_target = rhs._target;
    }
    return (*this);
}

/* Accessors */
std::string RobotomyRequestForm::getTarget(void) const {
    return (this->_target);
}

/* Other Functions */
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    std::cout << PURPLE << "* drilling noises *" << std::endl;
    /* Success rate of 50% */
    /* Use time(0) to generate a random seed */
    std::srand(time(0));
    if (std::rand() % 2) {
        std::cout << WHITE << this->_target
            << " has been robotomized successfully by "
            << executor.getName() << "."
            << RESET << std::endl;
    } else {
        std::cout << PURPLE << this->_target << " robotomization failed."
            << RESET << std::endl;
    }
}
