/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:57:16 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/18 15:00:33 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_05_EX02_AFORM_HPP
#define MODULE_05_EX02_AFORM_HPP

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

/* FORM ABSTRACT CLASS */
class AForm {
 public:
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(AForm const& src);

    AForm& operator=(AForm const& rhs);

    /* Accessors */
    std::string getName(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    bool getIsSigned(void) const;

    void beSigned(Bureaucrat const& bureaucrat);

    /* Virtual functions */
    virtual void execute(Bureaucrat const& executor) const = 0;
    virtual ~AForm();

    class GradeTooHighException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

 private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExecute;
    bool _isSigned;
};

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif //MODULE_05_EX02_AFORM_HPP
