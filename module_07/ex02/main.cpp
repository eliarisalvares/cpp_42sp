/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:44:31 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/25 14:32:24 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    std::cout << BLUE << "Creating arrays:" << RESET << std::endl;
    Array<int> empty_array;
    Array<int> int_array(5);
    Array<std::string> string_array(5);

    std::cout << std::endl;
    std::cout << BLUE << "Empty array:" << RESET << std::endl;
    std::cout << "Size: " << empty_array.size() << std::endl;
    std::cout << "Empty? " << (empty_array.size() == 0 ? GREEN : RED)
        << "If I'm green, it's because I'm empty." << RESET << std::endl;

    std::cout << std::endl;
    std::cout << BLUE << "Int array:" << RESET << std::endl;
    for (unsigned int i = 0; i < int_array.size(); i++)
        int_array[i] = i;
    for (unsigned int i = 0; i < int_array.size(); i++)
        std::cout << int_array[i] << std::endl ;

    std::cout << std::endl << BLUE << "String array:" << RESET << std::endl;
    for (unsigned int i = 0; i < string_array.size(); i++)
        string_array[i] = "string " + std::to_string(i);
    for (unsigned int i = 0; i < string_array.size(); i++)
        std::cout << string_array[i] << std::endl;

    std::cout << std::endl << BLUE << "Copy constructor:" << RESET << std::endl;
    Array<int> copy_int_array(int_array);
    for (unsigned int i = 0; i < copy_int_array.size(); i++)
        std::cout << copy_int_array[i] << std::endl;

    std::cout << std::endl << BLUE << "Not out of limits:"
        << RESET << std::endl;
    try {
        std::cout << int_array[4] << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BLUE << "Out of limits:" << RESET << std::endl;
    try {
        int_array[5] = 42;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BLUE << "End of scope:" << RESET << std::endl;
    return (0);
}
