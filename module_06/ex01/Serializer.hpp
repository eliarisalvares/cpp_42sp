/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:44:41 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 22:15:46 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_06_EX01_SERIALIZER_HPP_
#define MODULE_06_EX01_SERIALIZER_HPP_

#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* atof */
#include <iostream> /* cout, endl */
#include <string> /* string */
#include <iomanip> /* setprecision */

/* COLORS */
# define RESET "\033[0m"
# define BLUE "\033[0;34m"

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

/* SERIALIZER CLASS */
class Serializer {
 private:
    /* Canonical Functions */
    Serializer();
    Serializer(Serializer const &src);
    ~Serializer();
    Serializer &operator=(Serializer const &rhs);

 public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif  // MODULE_06_EX01_SERIALIZER_HPP_
