/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliarisalvares <eliarisalvares@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:19:05 by eliarisalva       #+#    #+#             */
/*   Updated: 2023/06/28 22:42:53 by eliarisalva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_08_EX01_SPAN_HPP_
#define MODULE_08_EX01_SPAN_HPP_

#include <algorithm> /* find */
#include <iostream>  /* cout, endl */
#include <iterator>  /* begin, end */
#include <string>    /* string */
#include <vector>    /* vector */

/* COLORS */
# define RESET "\033[0m"
# define BLUE "\033[1;34m"
# define RED "\033[1;31m"

class Span {
 public:
  Span(unsigned int N);
  Span(const Span &other);
  virtual ~Span();
  Span &operator=(const Span &other);

  void addNumber(int number);
  void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

  int shortestSpan();
  int longestSpan();

  int getN() const;
  const std::vector<int> &getNumbers() const;

  class SpanException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return ("SpanException: " RED "Error" RESET);
    }
  };

 private:
  Span();
  unsigned int _n;
  std::vector<int> _numbers;
};

#endif  // MODULE_08_EX01_SPAN_HPP_