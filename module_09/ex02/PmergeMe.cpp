/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:21:25 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/20 01:54:33 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* CANONICAL FORM */

/**
 * @brief Construct a new PmergeMe:: PmergeMe object
 *
 */
PmergeMe::PmergeMe(void) {
}

/**
 * @brief Construct a new PmergeMe:: PmergeMe object by copy
 *
 * @param rhs the object to be copied, right hand side
 */
PmergeMe::PmergeMe(const PmergeMe &rhs) {
  (void)rhs;
}

/**
 * @brief Destroy the Pmerge Me:: Pmerge Me object
 *
 */
PmergeMe::~PmergeMe(void) {
}

/**
 * @brief assignment operator overload
 *
 * @param rhs the object to be copied, right hand side
 * @return PmergeMe& the new object
 */
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  (void)rhs;
  return (*this);
}

/**
 * @brief recursive function that gets the nth jacobsthal term.
 * n = 0 and n = 1 are the base cases. The nth term is calculated
 * by using the relation of the jacobsthal sequence. which is the sum
 * of the previous two terms.
 *
 * @param n the term to be calculated.
 * @return int the nth jacobsthal term.
 */
int PmergeMe::getJacobsthalTerm(int n) {
  if (n == 0) {
    return (0);
  }
  if (n == 1) {
    return (1);
  }
  return (getJacobsthalTerm(n - 1) + 2 * getJacobsthalTerm(n - 2));
}
