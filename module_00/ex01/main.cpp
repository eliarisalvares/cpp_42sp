/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:09 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 21:12:30 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief The main function. Will create a PhoneBook object and call its start method.
 *
 * @return int 0 if program ends successfully
 */
int main(void) {
    PhoneBook phoneBook;

    phoneBook.start();
    return (0);
}
