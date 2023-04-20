/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:09 by elraira-          #+#    #+#             */
/*   Updated: 2023/04/20 11:11:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_00_EX01_CONTACT_HPP_
#define MODULE_00_EX01_CONTACT_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */

/* according to the subject, the contact class must hav private attributes
firstName, _lastName, _nickname, _phoneNumber and _darkestSecret and the
anything that will be used must be used inside the class and not outside of
it. So, the class must have a public method to get the value of the private
attributes and a public method to set the value of the private attributes. */

/* CONTACT CLASS */
class Contact {
 public:
    Contact();
    ~Contact();
    std::string getValue(std::string fieldName) const;
    void setValue(std::string fieldName, const std::string& field);

 private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif  /* MODULE_00_EX01_CONTACT_HPP_ */
