/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:54:32 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 23:59:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_05_EX01_FORM_HPP
#define MODULE_05_EX01_FORM_HPP

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "Bureaucrat.hpp"

/* COLORS */
# define WHITE "\e[1;37m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

/* GRADE */
# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat; /* Forward declaration to avoid circular dependency */

/* FORM CLASS */
class Form {
 public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(Form const& src);
    ~Form();

    Form& operator=(Form const& rhs);

    /* Accessors */
    std::string getName(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    bool getIsSigned(void) const;

    void beSigned(Bureaucrat const& bureaucrat);

    class GradeTooHighException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

 private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExecute;
    bool _isSigned;
};

std::ostream& operator<<(std::ostream& os, Form const& rhs);

#endif //MODULE_05_EX01_FORM_HPP
