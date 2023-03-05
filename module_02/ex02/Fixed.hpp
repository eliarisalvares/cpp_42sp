/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:42:01 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/05 14:55:05 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_02_EX02_FIXED_HPP_
#define MODULE_02_EX02_FIXED_HPP_

#include <iostream> /* cout, endl */
#include <cmath> /* roundf */
#include <algorithm> /* min, max */

class Fixed {
 public:
    Fixed(); /* default constructor */
    Fixed(const int n); /* constructor with int */
    Fixed(const float n); /* constructor with float */
    Fixed(const Fixed &src); /* copy constructor */
    ~Fixed(); /* destructor */

    Fixed &operator=(const Fixed &fixed); /* assignment operator */
    int getRawBits(void) const; /* returns the raw value of the fixed point
    value */
    void setRawBits(int const raw); /* sets the raw value of the fixed point
    value */
    float toFloat(void) const; /* converts the fixed point value to a floating
    point value */
    int toInt(void) const; /* converts the fixed point value to an integer */

    /* COMPARISON OPERATORS */
    bool operator>(const Fixed &fixed) const; /* overload the > operator.
    overload means that the operator is defined in a way that is different from
    the way it is defined in the language */
    bool operator<(const Fixed &fixed) const; /* overload the < operator */
    bool operator>=(const Fixed &fixed) const; /* overload the >= operator */
    bool operator<=(const Fixed &fixed) const; /* overload the <= operator */
    bool operator==(const Fixed &fixed) const; /* overload the == operator */
    bool operator!=(const Fixed &fixed) const; /* overload the != operator */

    /* ARITHMETIC OPERATORS */
    Fixed operator+(const Fixed &fixed) const; /* overload the + operator */
    Fixed operator-(const Fixed &fixed) const; /* overload the - operator */
    Fixed operator*(const Fixed &fixed) const; /* overload the * operator */
    Fixed operator/(const Fixed &fixed) const; /* overload the / operator */

    /* INCREMENT AND DECREMENT OPERATORS */
    Fixed &operator++(); /* overload the ++ operator */
    Fixed operator++(int); /* overload the ++ operator */
    Fixed &operator--(); /* overload the -- operator */
    Fixed operator--(int); /* overload the -- operator */

    /* MIN AND MAX FUNCTIONS */
    static Fixed &min(Fixed &a, Fixed &b); /* overload the min function */
    static Fixed &max(Fixed &a, Fixed &b); /* overload the max function */
    static const Fixed &min(const Fixed &a, const Fixed &b); /* overload the
    min function */
    static const Fixed &max(const Fixed &a, const Fixed &b); /* overload the
    max function */

 private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif  // MODULE_02_EX02_FIXED_HPP_
