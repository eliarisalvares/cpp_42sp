/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:09 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:21:39 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_00_EX01_PHONEBOOK_HPP_
#define MODULE_00_EX01_PHONEBOOK_HPP_

/* C++ LIBRARIES */
#include <stdlib.h> /* atoi */
#include <iomanip> /* std::setw (for table) */
#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "Contact.hpp"

/* ANSI COLOR CODES */
#define RESET "\033[0m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define PURPLE "\e[0;35m"
#define CYAN "\033[36;1m"
#define BOLD_WHITE "\e[1;37m"

/* PHONEBOOK CLASS */
class PhoneBook {
 public:
    PhoneBook();
    ~PhoneBook();
    void addContactInfo();
    void searchContact();
    void welcomeMessage();
    void start();
    void printContactInfo(Contact info);
    void getIndex();

 private:
    Contact _contacts[8];
    static int _totalContacts;
    void _add(Contact* contact);
    void _getInfo(std::string field, Contact& info);
    std::string _truncateString(std::string str);
    void _printSearchTableInfo(int index, Contact contact);
};

#endif  /* MODULE_00_EX01_PHONEBOOK_HPP_ */
