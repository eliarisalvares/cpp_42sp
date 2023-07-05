/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:16:34 by eliarisalva       #+#    #+#             */
/*   Updated: 2023/07/04 21:57:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/* A vector is a sequence container that encapsulates dynamic size arrays. */
/* The push_back() function is used to push elements into a vector from the back. */

int main() {
    {
        std::cout << PURPLE << "----------------------------------------" << RESET << std::endl;
        std::cout << PURPLE << "Using easyfind on a vector of ints" << RESET << std::endl;
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        std::cout << BLUE <<  "Vector: " << RESET;
            for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl << std::endl;

        try {
            std::cout << BLUE << "Using easyfind to find element 3 on my vector: "
                << RESET << std::endl;
            std::cout << *easyfind(v, 3) << std::endl;

            std::cout << BLUE << "Using easyfind to find element 42 on my vector: "
                << RESET << std::endl;
            std::cout << *easyfind(v, 42) << std::endl;
        } catch (std::string &e) {
            std::cout << RED << e << RESET << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << PURPLE << "----------------------------------------" << RESET << std::endl;
        std::cout << PURPLE << "Using easyfind on a list of ints" << RESET << std::endl;
        std::list<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        l.push_back(4);
        l.push_back(5);

        std::cout << BLUE << "List: " << RESET;
        for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl << std::endl;

        try {
            std::cout << BLUE << "Using easyfind to find element 3 on my list: "
                << RESET << std::endl;
            std::cout << *easyfind(l, 3) << std::endl;

            std::cout << BLUE << "Using easyfind to find element 42 on my list: "
                << RESET << std::endl;
            std::cout << *easyfind(l, 42) << std::endl;
        } catch (std::string &e) {
            std::cout << RED << e << RESET << std::endl;
        }
    }
  return 0;
}
