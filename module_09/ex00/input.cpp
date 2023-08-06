/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:30:42 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/06 14:59:49 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief Function to parse the date components from the given line and convert
 * them to integers by extracting year, month, and day substrings from the line.
 * Then, the substrings are validated and converted using stringstream.
 *
 * @param line Line to be parsed.
 * @param year Year component of the date.
 * @param month Month component of the date.
 * @param day Day component of the date.
 * @return true If the date components are valid.
 * @return false If the date components are invalid.
 */
bool parseDate(const std::string& line, int& year, int& month, int& day) {
    std::string yearStr = line.substr(0, 4);
    std::string monthStr = line.substr(5, 2);
    std::string dayStr = line.substr(8, 2);

    std::stringstream y(yearStr), m(monthStr), d(dayStr);
    y >> year;
    m >> month;
    d >> day;

    return (year >= 2009 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

/**
 * @brief Function to extract the rate from the given line and convert it to a
 * floating-point number and validate it.
 *
 * @param line Line to be parsed.
 * @param rate Rate to be extracted.
 * @return true If the rate is valid.
 * @return false If the rate is invalid.
 */
int extractRate(const std::string& line, float& rate) {
    std::string rateStr = line.substr(13, line.find('\0'));
    std::stringstream rateStream(rateStr);
    rateStream >> rate;

    if (rate < 0.00)
        return 1;
    else if (rate > 1000.00)
        return 2;
    return 0;
}

/**
 * @brief Function to generate the full date string from the date components
 * (year, month, day).
 *
 * @param year Year component of the date.
 * @param month Month component of the date.
 * @param day Day component of the date.
 * @return std::string Full date string.
 */
std::string generateFullDate(int year, int month, int day) {
    std::stringstream ss;
    if (month < 10 && day < 10) {
        ss << year * 10 << month * 10 << day;
    } else if (day < 10) {
        ss << year << month * 10 << day;
    } else if (month < 10) {
        ss << year * 10 << month << day;
    } else {
        ss << year << month << day;
    }
    return ss.str();
}

/**
 * @brief Function to process a single line from the input file. It parses the
 * date components from the line, extracts the rate, generates the full date
 * string, and processes the line using the parser. If the parser returns a
 * valid value, the output is printed.
 *
 * @param line Line to be processed.
 */
void BitcoinExchange::processLine(const std::string& line) {
    int year, month, day;
    float rate;
    std::string fullDate;

    if (!parseDate(line, year, month, day)) {
        std::cerr << "Error: invalid date\n";
        return;
    }
    if (extractRate(line, rate) == 1) {
        std::cerr << "Error: not a positive number\n";
        return;
    } else if (extractRate(line, rate) == 2) {
        std::cerr << "Error: too large a number\n";
        return;
    }

    fullDate = generateFullDate(year, month, day);

    if (parser(year, month, day, line, rate) != -1) {
        printOutput(fullDate, rate);
    }
}

/**
 * @brief Function to read input from the specified file and process each line.
 *
 * @param filename Name of the file to be read.
 */
void BitcoinExchange::readInputFile(const std::string& filename) {
    std::ifstream input;
    std::string line;

    input.open(filename.c_str());

    if (input.fail()) {
        std::cerr << "Error: could not open file\n";
        input.close();
        exit(0);
    }

    while (std::getline(input, line)) {
        if (line.length() < 14) {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }
        processLine(line);
    }

    input.close();
}
