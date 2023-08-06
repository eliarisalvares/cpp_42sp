/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:18:16 by elraira-          #+#    #+#             */
/*   Updated: 2023/07/21 18:33:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    BitcoinExchange A;
    if (argc == 2) {
        try {
            A.readBaseFile();
            A.readInputFile(argv[1]);
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    } else {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
    }
}
