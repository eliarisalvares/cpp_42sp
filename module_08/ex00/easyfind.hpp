/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliarisalvares <eliarisalvares@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:12:14 by eliarisalva       #+#    #+#             */
/*   Updated: 2023/06/28 22:11:27 by eliarisalva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_08_EX00_EASYFIND_HPP_
#define MODULE_08_EX00_EASYFIND_HPP_

#include <algorithm> /* find */
#include <iostream>  /* cout, endl */
#include <iterator>  /* begin, end */
#include <string>    /* string */
#include <vector>    /* vector */

/* COLORS */
# define RESET "\033[0m"
# define BLUE "\033[1;34m"
# define RED "\033[1;31m"

/**
 * @brief This function receives a container and a value to find in the container.
 * A container is a holder object that stores a collection of other objects (its elements).
 * They are implemented as class templates, which allows a great flexibility in the types
 * supported as elements. The container manages the storage space for its elements and
 * provides member functions to access them, either directly or through iterators, which
 * are references to elements of the container.
 * 
 * @tparam T template type
 * @param container the container to search
 * @param value the value to find
 * @return T::iterator the iterator to the value
 */
template <typename T>
typename T::iterator easyfind(T &container, int value) {
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end()) {
    throw std::string("Value not found");
  }
  return it;
}

#endif  // MODULE_08_EX00_EASYFIND_HPP_