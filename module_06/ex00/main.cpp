/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:16:30 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 21:38:21 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << RED << "Error: Invalid number of arguments."
            << RESET << std::endl;
        return (1);
    }
    try {
        ScalarConverter::convert(argv[1]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
