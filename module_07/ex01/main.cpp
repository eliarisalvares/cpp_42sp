/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:52:20 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/25 13:25:07 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T& element)
{
    std::cout << element << " ";
}

template <typename T>
void squareElement(T& element)
{
    element = element * element;
}

template <typename T>
void even(T& element)
{
    if (element % 2 == 0) {
        std::cout << element << ": even" << std::endl;
    } else {
        std::cout << element << ": odd" << std::endl;
    }
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << BLUE << "Printing original intArray using iter() and print(): "
        << RESET << std::endl;
    iter(intArray, intArrayLength, print<int>);
    std::cout << std::endl;

    iter(intArray, intArrayLength, squareElement<int>);

    std::cout << std::endl;
    std::cout << BLUE << "Printing modified intArray using iter() and print() "
        << "after squaring each element..." << RESET << std::endl;
    iter(intArray, intArrayLength, print<int>);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << BLUE << "Printing even/odd of the result of squaring each "
        << "element..." << RESET << std::endl;
    iter(intArray, intArrayLength, even<int>);

    return 0;
}

