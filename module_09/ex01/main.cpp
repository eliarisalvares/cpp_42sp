/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:42:52 by elraira-          #+#    #+#             */
/*   Updated: 2023/07/21 19:04:58 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *av[])
{
    RPN input;
    if (ac != 2) {
        std::cerr << "Error! Invalid number of arguments." << std::endl;
        exit(0);
    } else {
        try {
            input.processLine(av[1]);
        } catch(const std::exception& e) {
            std::cerr << e.what();
        }
    }
}

