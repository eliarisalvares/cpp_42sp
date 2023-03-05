/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:07:28 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/05 14:17:41 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_02_EX01_FIXED_HPP_
#define MODULE_02_EX01_FIXED_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */

/* FIXED CLASS */
class Fixed {
 public:
    Fixed(); /* default constructor */
    Fixed(int const value); /* constructor that takes an integer value and
    converts it to a fixed point value */
    Fixed(float const value); /* constructor that takes a floating point value
    and converts it to a fixed point value */
    Fixed(Fixed const& src); /* copy constructor */
    ~Fixed(); /* destructor */

    Fixed& operator=(Fixed const& rhs); /* assignment operator, which assign
    values between two instances of the same class */
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const; /* converts the fixed point value to a floating
    point value */
    int toInt(void) const; /* converts the fixed point value to an integer */

 private:
    int _value; /* the value of the fixed point number */
    static const int _fractionalBits = 8; /* the number of fractional bits. It
    will always be 8 */
};

std::ostream& operator<<(std::ostream& out, Fixed const& fixed); /* overload
the << operator to print the value of the fixed point number */

#endif  /* MODULE_02_EX01_FIXED_HPP_ */
