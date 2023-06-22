/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:32:47 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/22 13:11:17 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data *ptr = new Data;
    uintptr_t n;
    Data *ptr2;

    ptr->s1 = "hello";
    ptr->s2 = "world";
    ptr->n = 42;

    std::cout << BLUE << "Values:" << RESET << std::endl;
    std::cout << "s1: " << ptr->s1 << std::endl;
    std::cout << "s2: " << ptr->s2 << std::endl;
    std::cout << "n: " << ptr->n << std::endl;

    std::cout << std::endl << BLUE << "Serialize (convert to uintptr_t):"
        << RESET << std::endl;
    n = Serializer::serialize(ptr);
    std::cout << "uintptr_t: " << n << std::endl;

    std::cout << std::endl << BLUE << "Deserialize (convert to Data*):"
        << RESET << std::endl;
    ptr2 = Serializer::deserialize(n);
    std::cout << "s1: " << ptr2->s1 << std::endl;
    std::cout << "s2: " << ptr2->s2 << std::endl;
    std::cout << "n: " << ptr2->n << std::endl;

    std::cout << std::endl << BLUE << "Compare:" << RESET << std::endl;
    std::cout << "s1: " << (ptr->s1 == ptr2->s1 ? GREEN : RED)
        << "If I'm green, it's because I'm the same string."
		<< RESET << std::endl;
    std::cout << "s2: " << (ptr->s2 == ptr2->s2 ? GREEN : RED)
        << "If I'm green, it's because I'm the same string."
		<< RESET << std::endl;
    std::cout << "n: " << (ptr->n == ptr2->n ? GREEN : RED) <<
        "If I'm green, it's because I'm the same number."
		<< RESET << std::endl;

    std::cout << std::endl << BLUE << "End of serialization." << RESET
        << std::endl;
    delete ptr;
    return (0);
}
