/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:44:31 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/18 15:01:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* Canonical Functions */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
        std::cout << WHITE << "ShrubberyCreationForm created."
            << RESET << std::endl;
        std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
    : AForm(src), _target(src._target) {
        *this = src;
        std::cout << WHITE << "ShrubberyCreationForm copied."
            << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << WHITE << "ShrubberyCreationForm destroyed."
        << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=
    (ShrubberyCreationForm const& rhs) {
    if (this != &rhs) {
        this->_target = rhs._target;
    }
    return (*this);
}

/* Accessors */
std::string ShrubberyCreationForm::getTarget(void) const {
    return (this->_target);
}

/* Exceptions */
const char* ShrubberyCreationForm::FileNotOpenException::what() const throw() {
    return ("File could not be opened.");
}

const char* ShrubberyCreationForm::FileNotWriteException::what() const throw() {
    return ("File could not be written.");
}


/* Other Functions */
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    std::ofstream file;
    std::stringstream ss;

    ss << this->_target << "_shrubbery";
    file.open(ss.str().c_str());
    if (!file.is_open()) {
        throw ShrubberyCreationForm::FileNotOpenException();
    }
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "    \\====/    " << std::endl;
    file << "     \\__/     " << std::endl;

    if (file.bad()) {
        throw ShrubberyCreationForm::FileNotWriteException();
    } else {
        std::cout << PURPLE << "ShrubberyCreationForm executed by "
            << executor.getName() << "." << RESET << std::endl;
    }
    file.close();
}
