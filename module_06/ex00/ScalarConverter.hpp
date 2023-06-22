/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:28:43 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 00:56:50 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_06_EX00_SCALARCONVERTER_HPP
#define MODULE_06_EX00_SCALARCONVERTER_HPP

#include <iostream> /* cout, endl */
#include <string> /* string */
#include <iomanip> /* setprecision */
#include <stdlib.h> /* atof */

/* COLOR CODES */
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

/* TYPE ENUM */
typedef enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
} t_type;

/* SCALAR CONVERTER CLASS */
class ScalarConverter {
 public:
    /* Main Method */
    static void convert(std::string literals);

 private:

    /* Canonical Functions */
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ~ScalarConverter();

    ScalarConverter &operator=(ScalarConverter const &rhs);

    /* Attributes */
    static std::string _literal;
    static t_type _type;

    /* Print Methods */
    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

    static e_type getType(std::string literals);
    static int checkImpossible();
};

#endif //MODULE_06_EX00_SCALARCONVERTER_HPP
