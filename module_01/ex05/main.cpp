/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:17:32 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:17:27 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * @brief A main function that creates a Harl object and calls the complain
 * function with the following parameters: "debug", "info", "warning" and
 * "error".
 *
 * @return int 0 if the program runs correctly.
 */
int main(void) {
    Harl harl;

    std::cout << "===================" << std::endl;
    std::cout << "Harl is complaining:" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << std::endl;
    std::cout << BLUE << "DEBUG:" << RESET << std::endl;
    harl.complain("debug");
    std::cout << std::endl;
    std::cout << GREEN << "INFO:" << RESET << std::endl;
    harl.complain("info");
    std::cout << std::endl;
    std::cout << YELLOW << "WARNING:" << RESET << std::endl;
    harl.complain("warning");
    std::cout << std::endl;
    std::cout << RED << "ERROR:" << RESET << std::endl;
    harl.complain("error");
    std::cout << std::endl;
    std::cout << WHITE << "INVALID:" << RESET << std::endl;
    harl.complain("invalid");
    return 0;
}
