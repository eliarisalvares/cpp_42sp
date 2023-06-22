/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:32:47 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 20:39:41 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include "Serializer.hpp"

int main()
{
    Data *ptr = new Data;
    uintptr_t tmp;
    Data *ptr2;

    ptr->s1 = "hello";
    ptr->s2 = "world";
    ptr->n = 2024;

    tmp = Serializer::serialize(ptr);

    ptr2 = Serializer::deserialize(tmp);

    std::cout << ptr2->s1 << std::endl;
    std::cout << ptr2->s2 << std::endl;
    std::cout << ptr2->n << std::endl;

    // print types
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "ptr2: " << ptr2 << std::endl;
    std::cout << "tmp: " << tmp << std::endl;

    delete ptr;
}
