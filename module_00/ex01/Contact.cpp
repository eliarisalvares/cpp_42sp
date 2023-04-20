/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:09 by elraira-          #+#    #+#             */
/*   Updated: 2023/04/20 11:10:19 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* CONSTRUCTOR / DESTRUCTOR */
Contact::Contact() {
    return;
}

Contact::~Contact() {
    return;
}

/**
 * @brief The getter for the Contact class. Will return the value of each field
 * with the contact information.
 *
 * @param field The name of the field to get the value from.
 * @return std::string The value of the field. Empty string if the field does
 * not exist.
 */
std::string Contact::getValue(std::string field) const {
    if (field == "firstName")
        return this->_firstName;
    else if (field == "lastName")
        return this->_lastName;
    else if (field == "nickname")
        return this->_nickname;
    else if (field == "phoneNumber")
        return this->_phoneNumber;
    else if (field == "darkestSecret")
        return this->_darkestSecret;
    return "";
}

/**
 * @brief The setter for the Contact class. Will set the value of each field
 * with the contact information.
 *
 * @param field The name of the field to set the value to.
 * @param field The value to be set.
 */
void Contact::setValue(std::string field, const std::string& info) {
    if (field == "First name")
        this->_firstName = info;
    else if (field == "Last name")
        this->_lastName = info;
    else if (field == "Nickname")
        this->_nickname = info;
    else if (field == "Phone number")
        this->_phoneNumber = info;
    else if (field == "Darkest secret")
        this->_darkestSecret = info;
}
