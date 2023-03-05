/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:50:55 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/05 14:01:49 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_02_EX00_FIXED_HPP_
#define MODULE_02_EX00_FIXED_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */

/* FIXED CLASS */
/* Orthodox Canonical Form states that a class should have:
 * 1. A default constructor
 * 2. A copy constructor
 * 3. An assignment operator
 * 4. A destructor
 */
class Fixed {
 public:
    Fixed(); /* default constructor */
    Fixed(Fixed const& src); /* copy constructor */
    ~Fixed(); /* destructor */

    Fixed& operator=(Fixed const& rhs); /* assignment operator, which assign
    values between two instances of the same class */
    int getRawBits(void) const;
    void setRawBits(int const raw);

 private:
    int _value; /* the value of the fixed point number */
    static const int _fractionalBits = 8; /* the number of fractional bits. It
    will always be 8 */
};

#endif  /* MODULE_02_EX00_FIXED_HPP_ */
