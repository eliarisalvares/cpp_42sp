/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:07:33 by elraira-          #+#    #+#             */
/*   Updated: 2023/05/17 21:44:20 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    return;
}

Harl::~Harl() {
    return;
}

/**
 * @brief A public member functions that calls the four private member functions
 * depending on the level parameter. Levels are: "debug", "info", "warning" and
 * "error". If the level parameter is not one of these, the function prints
 * "Invalid level" and returns.
 * @subject Harl has to complain without using if/else or switch/case.
 *
 * @param level The level of the complaint.
 */
void Harl::complain(std::string level) {
    int i = 0;

    /* Each element of the complain array is a pointer to a member function
     * of the Harl class. */
    void (Harl::*complain[4])(void) = {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    std::string levels[4] = {
        "debug",
        "info",
        "warning",
        "error"
    };

    while (i < 4) {
        if (level == levels[i]) {
            (this->*complain[i])();
            return;
        }
        i++;
    }
    std::cout << "Invalid level" << std::endl;
}

void Harl::_debug(void) {
    std::cout << "I love having extra bacon for my "
        << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
        << "I really do." << std::endl;
}

void Harl::_info(void) {
    std::cout << "I cannot believe adding extra bacon cost more money. "
        << "You didn’t put enough! If you did I wouldn't be asking for it!"
        << std::endl;
}

void Harl::_warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. "
        << "I’ve been coming here for years and you just started working here "
        << "last month." << std::endl;
}

void Harl::_error(void) {
    std::cout << "This is unacceptable, I want to speak to the manager now."
        << std::endl;
}

