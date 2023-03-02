/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:08:18 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:11:04 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Usage: ./sed_is_for_losers <filename> <s1> <s2>"
            << std::endl;
        exit(1);
    }
    Sed newSed = Sed(argv[1], argv[2], argv[3]);
    newSed.replace();
    return (0);
}
