/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:01:09 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/18 15:01:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Canonical Functions */
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE) {
        throw AForm::GradeTooHighException();
    } else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE) {
        throw AForm::GradeTooLowException();
    } else {
        std::cout << WHITE << "AForm " << this->_name << " is born."
            << RESET << std::endl;
    }
}

AForm::AForm(AForm const& src) : _name(src._name),
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
    *this = src;
}

AForm::~AForm() {
    std::cout << WHITE << "AForm " << this->_name << " is dead."
        << RESET << std::endl;
    std::cout << std::endl;
}

AForm& AForm::operator=(AForm const& rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return (*this);
}

/* Accessors */
std::string AForm::getName(void) const {
    return (this->_name);
}

bool AForm::getIsSigned(void) const {
    return (this->_isSigned);
}

int AForm::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const {
    return (this->_gradeToExecute);
}

/* Exceptions */
const char* AForm::GradeTooHighException::what() const throw() {
    return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
    return ("form is not signed");
}

/* new execute() */
void AForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->_gradeToExecute) {
        throw AForm::GradeTooLowException();
    }
    if (!this->_isSigned) {
        throw AForm::FormNotSignedException();
    }
}

/* beSigned() */
void AForm::beSigned(Bureaucrat const& bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw AForm::GradeTooLowException();
    } else {
        this->_isSigned = true;
    }
}

/* Operator << */
std::ostream& operator<<(std::ostream& os, AForm const& src) {
    os << "Form " << src.getName() << " is ";
    if (!src.getIsSigned()) {
        os << "not ";
    }
    os << "signed. Grade to sign: " << src.getGradeToSign()
        << ". Grade to execute: " << src.getGradeToExecute() << ".";
    return (os);
}
