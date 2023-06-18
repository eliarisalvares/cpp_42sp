/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:24:42 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/18 15:01:23 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_05_EX02_ROBOTOMYREQUESTFORM_HPP
#define MODULE_05_EX02_ROBOTOMYREQUESTFORM_HPP

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include <cstdlib> /* std::rand */
#include <ctime> /* std::time */
#include "AForm.hpp"

/* COLORS */
# define WHITE "\e[1;37m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

class AForm; /* Forward declaration to avoid circular dependency */

/* ROBOTOMYREQUESTFORM CLASS */
class RobotomyRequestForm : public AForm {
 public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const& src);

    RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

    /* Virtual functions */
    void execute(Bureaucrat const& executor) const;
    virtual ~RobotomyRequestForm();

    /* Accessors */
    std::string getTarget(void) const;

    private:
    std::string _target;
};

#endif //MODULE_05_EX02_ROBOTOMYREQUESTFORM_HPP
