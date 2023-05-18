/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:19:06 by elraira-          #+#    #+#             */
/*   Updated: 2023/05/17 21:51:48 by elraira-         ###   ########.fr       */
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
 * @brief Get the level from user's input.
 *
 * @param level The level from user's input.
 * @return int Integer representing the level.
 */
static int getLevel(std::string level) {
    if (level == "DEBUG") {
        return 0;
    } else if (level == "INFO") {
        return 1;
    } else if (level == "WARNING") {
        return 2;
    } else if (level == "ERROR") {
        return 3;
    }
    return 4;
}

/**
 * @brief Print messages according to the level. Switch case is used to
 * determine which method to call.
 */
int Harl::complain(std::string level) {
    void (Harl::*debug)() = &Harl::_debug;
    void (Harl::*info)() = &Harl::_info;
    void (Harl::*warning)() = &Harl::_warning;
    void (Harl::*error)() = &Harl::_error;

    void (Harl::*complain[4])() = {debug, info, warning, error};

    switch (getLevel(level)) {
        case 0:
            (this->*complain[0])();
            break;
        case 1:
            (this->*complain[1])();
            break;
        case 2:
            (this->*complain[2])();
            break;
        case 3:
            (this->*complain[3])();
            break;
        default:
            std::cout << "Probably complaining about insignificant problem"
                << std::endl;
            break;
    }
    return 0;
}

void Harl::_debug() {
    std::cout << BLUE << "DEBUG MESSAGE:" << RESET << std::endl;
        std::cout << "I love to get extra bacon for my "
        << "7XL-double-cheese-triple-pickle-special-ketchup burger."
        << " I really do!" << std::endl;
}

void Harl::_info() {
    std::cout << GREEN << "INFO MESSAGE:" << RESET << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money."
        << "You didn’t put enough bacon in my burguer. If you did, I wouldn't"
        << " be asking for more" << std::endl;
}

void Harl::_warning() {
    std::cout << YELLOW << "WARNING" << RESET << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free."
        << "I’ve been coming here for years and you just started working here"
        << " last month." << std::endl;
}

void Harl::_error() {
    std::cout << RED << "ERROR" << RESET << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now."
        << std::endl;
}



