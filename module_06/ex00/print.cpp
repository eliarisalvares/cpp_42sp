/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:35:55 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 00:46:23 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * @brief Checks whether _literals == "inf", "inff", "+inf", "+inff", "-inf",
 * "-inff", "nan", "nanf". This method is used to check if the input is
 * impossible to convert. "Inf" is impossible to convert because it is
 * out of the range of the type double. "nan" is impossible to convert
 * because it is not a number.
 */
int ScalarConverter::checkImpossible() {
    if (_literal == "inf" || _literal == "inff" || _literal == "+inf" ||
        _literal == "+inff" || _literal == "-inf" || _literal == "-inff" ||
        _literal == "nan" || _literal == "nanf") {
            return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Prints the character literal. Converts the character literal to
 * a std::string and checks if it is impossible to convert (in case is a pseudo
 * literal). If it is impossible, prints "impossible". If it is possible,
 * checks if it is a printable character. If it is, prints the character
 * between single quotes. If it is not, prints "Non displayable".
 *
 * @param c character literal to be printed.
 */
void ScalarConverter::printChar(char c) {
    std::cout << "char: ";
    if (checkImpossible()) {
        std::cout << "impossible" << std::endl;
    } else if (!isprint(c)) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << c << "'" << std::endl;
    }
}

/**
 * @brief Prints the integer literal. Converts the integer literal to
 * a std::string and checks if it is impossible to convert (in case is a pseudo
 * literal). If it is impossible, prints "impossible". If it is possible,
 * prints the integer.
 *
 * @param i integer literal to be printed.
 */
void ScalarConverter::printInt(int i) {
    std::cout << "int: ";
    if (checkImpossible()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << i << std::endl;
    }
}

/**
 * @brief Prints the float literal. Sets the precision to 1 decimal place.
 *
 * @param f float literal to be printed.
 */
void ScalarConverter::printFloat(float f) {
    std::cout << "float: " <<
        std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

/**
 * @brief Prints the double literal. Sets the precision to 1 decimal place.
 *
 * @param d double literal to be printed.
 */
void ScalarConverter::printDouble(double d) {
    std::cout << "double: "
        << std::fixed << std::setprecision(1) << d << std::endl;
}
