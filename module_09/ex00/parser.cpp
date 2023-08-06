/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:20:56 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/06 14:57:45 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief Checks if the given character is a digit.
 * @param c Character to be checked.
 * @return true if the character is a digit, false otherwise.
 */
bool isValidDigit(char c) {
    return isdigit(c) != 0;
}

/**
 * @brief Function to check if the given date components (year, month, day)
 * form a valid date. Because bitcoin data is available from 2009-01-03, the
 * year should be greater than or equal to 2009. The month should be between 1
 * and 12 (inclusive). The day should be between 1 and 31 (inclusive).
 * @param year the year should be greater than or equal to 2009.
 * @param month The month should be between 1 and 12 (inclusive).
 * @param day The day should be between 1 and 31 (inclusive).
 * @return true If the date is valid.
 * @return false If the date is invalid.
 */
bool isValidDate(int year, int month, int day) {
    int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year < 2009 || month < 1 || month > 12)
        return false;

    if (day > month_limits[month - 1] || day < 1)
        return false;

    return true;
}

/**
 * @brief Function to check if the given rate is within a valid range.
 * The rate should be between 0 and 1000 (inclusive).
 *
 * @param rate Rate to be checked.
 * @return true If the rate is valid.
 * @return false If the rate is invalid.
 */
int isValidRate(float rate) {
    if (rate < 0.00)
        return 1;
    if (rate > 1000.00)
        return 2;
    return 0;
}

/**
 * @brief Function to parse a line of input and validate its components (date
 * and rate). The date should be in the format "YYYY-MM-DD" (with hyphens). The
 * rate should be a valid floating-point number. The date components should form
 * a valid date. The rate should be within a valid range.
 *
 * @param year Year component of the date.
 * @param month Month component of the date.
 * @param day Day component of the date.
 * @param line Line to be parsed.
 * @param key Date component of the line.
 * @param value Rate component of the line.
 * @return int 0 if the line is valid, -1 otherwise.
 */
int BitcoinExchange::parser(int year, int month, int day, std::string line,
    float &value) {

    size_t idx = line.find("|");
    if (line[idx + 1] != ' ' || line[idx - 1] != ' ') {
        std::cerr << "Error: bad input, invalid pipe character\n";
        return (-1);
    }
    if ((line.substr(4, 1) != "-" && line.substr(7, 1) != "-")
        || (!isValidDate(year, month, day))) {
        std::cerr << "Error: bad input, invalid date format\n";
        return (-1);
    }
    if (isValidRate(value) == 1) {
        std::cerr << "Error: not a positive number\n";
        return (-1);
    } else if (isValidRate(value) == 2) {
        std::cerr << "Error: too large a number\n";
        return (-1);
    }

    return (0);
}

