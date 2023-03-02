/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presentation.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:09 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 22:41:07 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Displays a welcome message to the user.
 */
void PhoneBook::welcomeMessage(void) {
    std::cout << std::endl;
    std::cout << CYAN << "Welcome to the PhoneBook!" << RESET << std::endl;
    std::cout << BOLD_WHITE << "You can use the following"
        << "commands to navigate your phonebook:" << std::endl;
    std::cout << PURPLE << "ADD - add a new contact" << std::endl;
    std::cout << "SEARCH - search for a contact" << std::endl;
    std::cout << "EXIT - exit the program" << RESET << std::endl;
}

/**
 * @brief prints the table displayed when user searches for a contact.
 * The table contains the first 10 characters of the contact's first name,
 * last name and nickname.
 * @param index The index of the contact in the phonebook.
 * @param contact The contact to be displayed.
 */
void PhoneBook::_printSearchTableInfo(int index, Contact contact) {
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10)
        << _truncateString(contact.getValue("firstName")) << "|";
    std::cout << std::setw(10)
        << _truncateString(contact.getValue("lastName")) << "|";
    std::cout << std::setw(10)
        << _truncateString(contact.getValue("nickname")) << "|";
    std::cout << std::endl;
}

/**
 * @brief prints the contact info of the contact chosen by the user to the
 * console.
 *
 * @param info The contact to be displayed.
 */
void PhoneBook::printContactInfo(Contact info) {
    std::cout << std::endl;
    std::cout << "\033[36;1m" << "Contact info:" << std::endl;
    std::cout << CYAN << "First name: " << RESET
        << info.getValue("firstName") << std::endl;
    std::cout << CYAN << "Last name: " << RESET
        << info.getValue("lastName") << std::endl;
    std::cout << CYAN << "Nickname: " << RESET
        << info.getValue("nickname") << std::endl;
    std::cout << CYAN << "Phone number: " << RESET
        << info.getValue("phoneNumber") << std::endl;
    std::cout << CYAN << "Darkest secret: " << RESET
        << info.getValue("darkestSecret") << std::endl;
}

/**
 * @brief Gets the contact's info from the user and sets it to the contact by
 * calling the setValue method.
 *
 * @param field The field of the contact to be set.
 * @param info The contact in which the field will be set.
 */
void PhoneBook::_getInfo(std::string field, Contact& info) {
    std::string str;
    while (!str.length()) {
        std::cout << PURPLE << "Please, enter the contact's " + field + ":"
            << RESET << std::endl;
        std::getline(std::cin, str);
        if (str.length() == 0)
            std::cout << RED << "Ops! You must enter the contact's "
                << field + "!" << RESET << std::endl;
    }
    info.setValue(field, str);
}

/**
 * @brief Gets the index of the contact to be displayed from the user.
 */
void PhoneBook::getIndex() {
    int index;
    std::string buffer;

    while (1) {
        std::cout << PURPLE << "Enter the id of the contact you want to see!"
           << RESET << std::endl;
        std::getline(std::cin, buffer);
        if (buffer.empty()) {
            std::cout << RED << "Index cannot be empty" << RESET << std::endl;
            continue;
        }
        index = atoi(buffer.c_str());
        if (index < 0 || index >= PhoneBook::_totalContacts) {
            std::cout << RED << "Invalid index" << RESET << std::endl;
            continue;
        }
        break;
    }
    printContactInfo(this->_contacts[index]);
}
