/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:53:52 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 23:22:49 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_05_EX02_BUREAUCRAT_HPP
#define MODULE_05_EX02_BUREAUCRAT_HPP

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "AForm.hpp"

/* COLORS */
# define WHITE "\e[1;37m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define PURPLE "\033[0;35m"

/* GRADE */
# define MAX_GRADE 1
# define MIN_GRADE 150

class AForm; /* Forward declaration to avoid circular dependency */

/* BUREAUCRAT CLASS */
class Bureaucrat {
 public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const& src);
    ~Bureaucrat();

    Bureaucrat& operator=(Bureaucrat const& rhs);

    /* Accessors */
    std::string getName(void) const;
    int getGrade(void) const;

    int incrementGrade(void);
    int decrementGrade(void);

    void signForm(AForm& form);
    void executeForm(AForm const& form);

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
    int _grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif
