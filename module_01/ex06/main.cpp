/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:44:19 by elraira-          #+#    #+#             */
/*   Updated: 2023/05/17 21:47:34 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
        std::cout << PURPLE << "Usage: ./harl <level> (levels are: " <<
            "DEBUG, INFO, WARNING, ERROR)" << RESET << std::endl;
        return 1;
    }
    std::cout << "===================" << std::endl;
    std::cout << "Harl is complaining:" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << std::endl;
    harl.complain(argv[1]);
    return 0;
}
