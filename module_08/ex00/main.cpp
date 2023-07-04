/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliarisalvares <eliarisalvares@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:16:34 by eliarisalva       #+#    #+#             */
/*   Updated: 2023/06/28 22:17:59 by eliarisalva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/* A vector is a sequence container that encapsulates dynamic size arrays. */
/* The push_back() function is used to push elements into a vector from the back. */

int main() {
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
  return 0;
}