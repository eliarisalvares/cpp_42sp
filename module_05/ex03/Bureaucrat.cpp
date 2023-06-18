/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:55:51 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 23:09:58 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Canonical Functions */
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < MAX_GRADE) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > MIN_GRADE) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->_grade = grade;
        std::cout << WHITE << "Bureaucrat " << this->_name << " is born."
            << RESET << std::endl;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : _name(src._name) {
    *this = src;
}

Bureaucrat::~Bureaucrat() {
    std::cout << WHITE << "Bureaucrat " << this->_name << " is dead."
        << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
    if (this != &rhs)
        this->_grade = rhs._grade;
    return (*this);
}

/* Accessors */
std::string Bureaucrat::getName(void) const {
    return (this->_name);
}

int Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

/* incrementGrade() and decrementGrade() */
int Bureaucrat::incrementGrade(void) {
    if (this->_grade - 1 < MAX_GRADE) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        this->_grade--;
        std::cout << RED << "Bureaucrat " << this->_name
            << " has been demoted to grade "
            << this->_grade << "." << RESET << std::endl;
    }
    return (this->_grade);
}

int Bureaucrat::decrementGrade(void) {
    if (this->_grade + 1 > MIN_GRADE) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->_grade++;
        std::cout << GREEN << "Bureaucrat " << this->_name
            << " has been promoted to grade "
            << this->_grade << "." << RESET << std::endl;
    }
    return (this->_grade);
}

/* Exception Classes */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return (RED "Grade too high." RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return (RED "Grade too low." RESET);
}

/* operator<< overload */
std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat) {
    os << BLUE << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getGrade() << "." << RESET << std::endl;
    return (os);
}

/* signForm() */
void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << GREEN << this->_name << " signs " << form.getName()
            << "." << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << this->_name << " cannot sign " << form.getName()
            << " because " << e.what() << "." << RESET << std::endl;
    }
}

/* executeForm() */
void Bureaucrat::executeForm(AForm const& form) {
    try {
        form.execute(*this);
        std::cout << GREEN << this->_name << " executes " << form.getName()
            << "." << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << this->_name << " cannot execute " << form.getName()
            << " because " << e.what() << "." << RESET << std::endl;
    }
}
