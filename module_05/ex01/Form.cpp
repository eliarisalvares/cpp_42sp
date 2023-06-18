/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:06:31 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 21:47:54 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Canonical Functions */
Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE) {
        throw Form::GradeTooHighException();
    } else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE) {
        throw Form::GradeTooLowException();
    } else {
        std::cout << WHITE << "Form " << this->_name << " is born."
            << RESET << std::endl;
    }
}

Form::Form(Form const& src) : _name(src._name),
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
    *this = src;
}

Form::~Form() {
    std::cout << WHITE << "Form " << this->_name << " is dead."
        << RESET << std::endl;
}

Form& Form::operator=(Form const& rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return (*this);
}

/* Accessors */
std::string Form::getName(void) const {
    return (this->_name);
}

int Form::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const {
    return (this->_gradeToExecute);
}

bool Form::getIsSigned(void) const {
    return (this->_isSigned);
}

void Form::beSigned(Bureaucrat const& bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw Form::GradeTooLowException();
    } else {
        this->_isSigned = true;
        std::cout << GREEN << "Bureaucrat " << bureaucrat.getName()
            << " signed the form " << this->_name << "." << RESET << std::endl;
    }
}

/* Exceptions */
const char* Form::GradeTooHighException::what() const throw() {
    return (RED "grade is too high." RESET);
}

const char* Form::GradeTooLowException::what() const throw() {
    return (RED "grade is too low." RESET);
}

/* Overloaders */
std::ostream& operator<<(std::ostream& os, Form const& form) {
    os << WHITE << "Form " << form.getName() << " is "
        << (form.getIsSigned() ? "signed" : "not signed")
        << " and requires grade " << form.getGradeToSign()
        << " to be signed and grade " << form.getGradeToExecute()
        << " to be executed." << RESET << std::endl;
    return (os);
}
