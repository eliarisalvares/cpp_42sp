#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

/* C++ LIBRARIES */
#include <iomanip> // std::setw (for table)
#include <iostream> // std::cout
#include <stdlib.h> // atoi
#include <string> // std::string

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
    PhoneBook(); // constructor
    ~PhoneBook(); // destructor
    void addContactInfo(); // add contact to phonebook
    void searchContact(); // search contact in phonebook
    void welcomeMessage(); // displays welcome message to user
    void start(); // starts program
    void printContactInfo(Contact info); // prints contact info to console
    void getIndex();

private:
    Contact _contacts[8]; // array of contacts: accepts 8 contacts according to subject
    static int _totalContacts; // total contacts in phonebook at the moment
    void _add(Contact* contact); // adds contact to phonebook
    void _getInfo(std::string field, Contact& info); // gets info from user
    std::string _truncateString(std::string str); // truncates string to 10 characters
    void _printSearchTableInfo(int index, Contact contact); // prints contact info to console
};

#endif