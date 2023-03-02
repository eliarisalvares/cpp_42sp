/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:12:49 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 20:50:11 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @brief Main function. Prints the arguments, if there are any, in uppercase
 * using std::cout (prints in the standard output);
 *
 * @param argc number of arguments
 * @param argv array of arguments
 * @return int 0 upon success
 */
int main(int argc, char **argv) {
    int i = 1;
    if (argc ==1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    } while (i < argc) {
        while (*argv[i]) {
            *argv[i] = toupper(*argv[i]);
            std::cout << *argv[i];
            argv[i]++;
        }
        i++;
    }
    std::cout << std::endl;
}
