/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:28:43 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/22 13:04:00 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Attributes */
std::string ScalarConverter::_literal = "";

/* Canonical Functions */
/**
 * @brief Default constructor.
 */
ScalarConverter::ScalarConverter() {
    std::cout << "Default Constructor Called" << std::endl;
}

/**
 * @brief Copy constructor.
 *
 * @param src ScalarConverter object to be copied.
 */
ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = src;
}

/**
 * @brief Destructor.
 */
ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor Called" << std::endl;
}

/**
 * @brief Assignation operator overload.
 *
 * @param rhs ScalarConverter object to be copied.
 * @return ScalarConverter& reference to the copied object.
 */
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
    std::cout << "Assignation Operator Called" << std::endl;
    (void) rhs;
    return (*this);
}

/* Auxiliary Methods */

/**
 * @brief Checks whether _literal is a character literal.
 *
 * @param lit literal: string to be checked.
 * @return bool true if _literal is a character literal, false otherwise.
 * A character literal is a string with length 3 and the first and last
 * characters are single quotes. A character literal can also be a string
 * with length 1 and the character is not a digit.
 */
bool isCharacterLiteral(const std::string& lit) {
    return (lit.length() == 3 && lit[0] == '\'' && lit[2] == '\'')
        || (lit.length() == 1 && !isdigit(lit[0]) && !lit.empty());
}

/**
 * @brief Checks whether _literal == "inf", "+inf", "-inf", "nan"
 * @param literal literal: string to be checked.
 * @return bool true if _literal == "inf", "+inf", "-inf", "nan", false
 * otherwise.
 */
bool isDoubleLiteral(const std::string& literal) {
    if (!literal.compare("nan") || !literal.compare("+inf")
        || !literal.compare("-inf") || !literal.compare("inf")) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Checks whether _literal == "inff", "+inff", "-inff", "nanf"
 *
 * @param literal literal: string to be checked.
 * @return bool true if _literal == "inff", "+inff", "-inff", "nanf", false
 * otherwise.
 */
bool isFloatLiteral(const std::string& literal) {
    if (!literal.compare("nanf") || !literal.compare("+inff")
        || !literal.compare("-inff") || !literal.compare("inff")) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief This method goes through each character of the string and checks
 * whether it is a digit, a decimal point or a 'f' suffix. If the character
 * is not a digit, a decimal point or a 'f' suffix, then the string is not
 * a numeric literal.
 *
 * @param c character to be checked.
 * @param isNumericCharacter array of bools to store the result of the
 * check.
 * @param hasDecimalPoint bool to check whether the string has a decimal
 * point.
 * @param hasFSuffix bool to check whether the string has a 'f' suffix.
 */
void checkCharacters(char c, bool* isNumericCharacter,
    bool& hasDecimalPoint, bool& hasFSuffix) {
    if (!isdigit(c) && !(hasDecimalPoint == false && (c == '-' || c == '+'))) {
        isNumericCharacter[0] = false;
        return;
    }

    if (c == '.' || c == 'f') {
        if (c == '.' && hasDecimalPoint == false) {
            hasDecimalPoint = true;
        } else if (c == 'f' && hasDecimalPoint == true
            && (hasFSuffix == false && c != '.')) {
            isNumericCharacter[1] = true;
            hasFSuffix = true;
        } else {
            isNumericCharacter[1] = false;
            isNumericCharacter[2] = false;
            return;
        }
    }
}

/**
 * @brief Returns the type of the string _literal. The method checks whether
 * _literal is a character literal, an integer literal, a float literal or
 * a double literal.
 *
 * @param literal literal: string to be checked.
 * @return e_type type of the string _literal.
 */
e_type ScalarConverter::getType(std::string literal) {
    bool isNumericCharacter[3] = {true, true, true};
    bool hasDecimalPoint = false;
    bool hasFSuffix = false;

    if (literal.length() == 0) {
        return INVALID;
    } else if (isDoubleLiteral(literal)) {
        return DOUBLE;
    } else if (isFloatLiteral(literal)) {
        return FLOAT;
    } else if (isCharacterLiteral(literal)) {
        return CHAR;
    }

    for (int a = 0; a < (int)literal.length(); a++) {
        checkCharacters(literal[a], isNumericCharacter,
            hasDecimalPoint, hasFSuffix);
    }

    if (isNumericCharacter[0])
        return INT;
    if (isNumericCharacter[1])
        return DOUBLE;
    if (isNumericCharacter[2])
        return FLOAT;
    return INVALID;
}

/**
 * @brief This method converts the string _literal to different types:
 * char, int, float, and double. The method determines the type of _literal
 * and performs the conversion accordingly.
 *
 * @param literal literal: string to be converted.
 */
void ScalarConverter::convert(std::string literal) {
    _literal = literal;
    e_type type = getType(literal);
    if (type == CHAR) {
        try {
            char c = literal.length() == 3 ? literal[1] : literal[0];
            printChar(c);
            printInt(static_cast<int>(c));
            printFloat(static_cast<float>(c));
            printDouble(static_cast<double>(c));
        } catch (std::exception &e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    } else if (type == INT) {
        try {
            printInt(atoi(literal.c_str()));
            printChar(static_cast<char>(atoi(literal.c_str())));
            printFloat(static_cast<float>(atoi(literal.c_str())));
            printDouble(static_cast<double>(atoi(literal.c_str())));
        } catch (std::exception &e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    } else if (type == FLOAT) {
        try {
            printFloat(strtof(literal.c_str(), NULL));
            printDouble(static_cast<double>(strtof(literal.c_str(), NULL)));
            printInt(static_cast<int>(strtof(literal.c_str(), NULL)));
            printChar(static_cast<char>(strtof(literal.c_str(), NULL)));
        } catch (std::exception &e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    } else if (type == DOUBLE) {
        try {
            printDouble(strtod(literal.c_str(), NULL));
            printFloat(static_cast<float>(strtod(literal.c_str(), NULL)));
            printInt(static_cast<int>(strtod(literal.c_str(), NULL)));
            printChar(static_cast<char>(strtod(literal.c_str(), NULL)));
        } catch (std::exception &e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    } else {
        std::cout << RED << "Invalid input. Acceptable inputs: "
            << "char, int, float, double" << RESET << std::endl;
    }
}

