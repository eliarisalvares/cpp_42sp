/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:09:33 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 22:24:20 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_05_EX02_PRESIDENTIALPARDONFORM_HPP
#define MODULE_05_EX02_PRESIDENTIALPARDONFORM_HPP

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

class AForm; /* Forward declaration to avoid circular dependency */

/* PRESIDENTIALPARDONFORM CLASS */
class PresidentialPardonForm : public AForm {
 public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const& src);

    PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

    /* Virtual functions */
    void execute(Bureaucrat const& executor) const;
    virtual ~PresidentialPardonForm();

    /* Accessors */
    std::string getTarget(void) const;

    private:
    std::string _target;
};

#endif //MODULE_05_EX02_PRESIDENTIALPARDONFORM_HPP
