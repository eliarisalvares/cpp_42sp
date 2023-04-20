/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:09 by elraira-          #+#    #+#             */
/*   Updated: 2023/04/20 11:09:38 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::_totalContacts = 0;

/* CONSTRUCTOR AND DESTRUCTOR */
PhoneBook::PhoneBook() {
    return;
}

PhoneBook::~PhoneBook() {
    return;
}

/**
 * @brief add a new contact to the phonebook.
 *
 * @param contact The contact to be added.
 */
void PhoneBook::_add(Contact* contact) {
    if (PhoneBook::_totalContacts < 8) {
        this->_contacts[PhoneBook::_totalContacts] = *contact;
        _totalContacts++;
    } else {
        std::cout << RED << "Phonebook is full, first contact will be replaced"
            << RESET << std::endl;
        this->_contacts[0] = *contact;
    }
}

/**
 * @brief Gets the contact info from the user and adds it to the phonebook by
 * calling the _add method.
 */
void PhoneBook::addContactInfo() {
    Contact contact;

    _getInfo("First name", contact);
    _getInfo("Last name", contact);
    _getInfo("Nickname", contact);
    _getInfo("Phone number", contact);
    _getInfo("Darkest secret", contact);
    this->_add(&contact);
}

/**
 * @brief Gets the index of the contact to be displayed and prints it.
 */
void PhoneBook::searchContact() {
    int i = 0;
    if (PhoneBook::_totalContacts == 0) {
        std::cout << RED << "Still no contacts to search" << RESET << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|";
    std::cout << std::endl;

    while (i < PhoneBook::_totalContacts) {
        _printSearchTableInfo(i, this->_contacts[i]);
        i++;
    }
    getIndex();
}


void PhoneBook::start(void) {
    std::string command;

    welcomeMessage();
    while (1) {
        std::cout << std::endl;
        std::cout << BOLD_WHITE << "Please, enter a command: ";
        std::getline(std::cin, command);
        std::cout << RESET;
        if (command == "EXIT")
            break;
        else if (command == "ADD")
            addContactInfo();
        else if (command == "SEARCH")
            searchContact();
        else
            std::cout << PURPLE << "I'm sorry, I don't understand this command"
                << RESET << std::endl;
    }
}
