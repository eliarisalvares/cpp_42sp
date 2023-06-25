/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:37:34 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/25 13:23:10 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_07_EX01_ITER_HPP_
#define MODULE_07_EX01_ITER_HPP_

#include <iostream> /* std::cout, std::endl */
#include <string> /* std::string */

/* COLORS */
#define RESET "\033[0m"
#define BLUE  "\033[34m"

/* iter() function that iterates through an array and applies a function on
    each element. */
template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif // MODULE_07_EX01_ITER_HPP_
