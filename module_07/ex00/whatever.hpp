/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:32:22 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/23 23:35:33 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_07_EX00_WHATEVER_HPP_
#define MODULE_07_EX00_WHATEVER_HPP_

#include <iostream> /* std::cout, std::endl */
#include <string> /* std::string */

/* templates are used to define functions and classes generically, so that
    they can be used in a wide range of situations. */

/* TEMPLATE FUNCTIONS */

/* typename is used to declare a type in a template. */
/* swap() function that swaps the values of two variables. */
template <typename A, typename B>
void swap(A& a, B& b)
{
    A tmp = a;
    a = b;
    b = tmp;
}

/* min() function that returns the smallest of two values. */
template <typename A, typename B>
A& min(A& a, B& b)
{
    return (a < b ? a : b);
}

/* max() function that returns the largest of two values. */
template <typename A, typename B>
A& max(A& a, B& b)
{
    return (a > b ? a : b);
}

#endif // MODULE_07_EX00_WHATEVER_HPP_
