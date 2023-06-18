/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:39:58 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 23:31:13 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_05_EX03_SHRUBBERYCREATIONFORM_HPP
#define MODULE_05_EX03_SHRUBBERYCREATIONFORM_HPP

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include <fstream> /* std::ofstream */
#include <sstream> /* std::stringstream */
#include "AForm.hpp"

/* COLORS */
# define WHITE "\e[1;37m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

class AForm; /* Forward declaration to avoid circular dependency */

/* SHRUBBERYCREATIONFORM CLASS */
class ShrubberyCreationForm : public AForm {
 public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const& src);

    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

    /* Virtual functions */
    void execute(Bureaucrat const& executor) const;
    virtual ~ShrubberyCreationForm();

    /* Accessors */
    std::string getTarget(void) const;

    /* Exceptions */
    class FileNotOpenException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

    class FileNotWriteException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

    private:
    std::string _target;
};

#endif //MODULE_05_EX03_SHRUBBERYCREATIONFORM_HPP
