/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:21:46 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/06 16:05:19 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* CANONICAL FORM */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->_base = other._base;
    }
    return *this;
}

/* METHODS */

/**
 * @brief This function reads data from a CSV file named "data.csv" and
 * populates the _base map with date-price pairs.
 *
 */
void BitcoinExchange::readBaseFile() {
    std::ifstream file;
    std::string date;
    std::string data;

    file.open("./data.csv");
    while (!file.eof())
    {
        float price = 0.0f;
        std::stringstream convert;
        file >> data;
        date = data.substr(0,10).erase(4,1).erase(6,1);
        convert << data.substr(11);
        convert >> price;
        _base.insert(std::make_pair(date, price));
    }
    file.close();
}

/**
 * @brief This function calculates the total value of bitcoins based on the
 * given exchange rate from the _base map and prints the result.
 *
 * @param inputDate The date for which the exchange rate is
 * used to calculate the value of bitcoins. The date should be in the format
 * "YYYYMMDD" (without hyphens).
 * @param bitcoins The number of bitcoins to calculate the total value.
 */
void    BitcoinExchange::printOutput(std::string& inputDate, float bitcoins)
{
    std::map<std::string, float>::iterator itb = this->_base.begin();
    std::map<std::string, float>::iterator ite = this->_base.end();
    bool    flag = false;

    for (; itb != ite; itb++) {
        if (itb->first == inputDate) {
            flag = true;
            break;
        }
    }

    // transform bitcoins to string using sstream
    std::stringstream ss;
    ss << bitcoins;
    std::string s = ss.str();

    // remove right trailing zeros
    s.erase(s.find_last_not_of('0') + 1, std::string::npos);


    if (flag == true) {
        std::cout << inputDate.insert(4,"-").insert(7,"-")
            << " => " << s << " = " << std::fixed << std::setprecision(2);

        // transform bitcoins to string using sstream
        std::stringstream ss;
        ss << bitcoins * itb->second;
        std::string s2 = ss.str();

        // remove right trailing zeros
        s2.erase(s2.find_last_not_of('0') + 1, std::string::npos);

        std::cout << s2 << "\n";
        flag = false;
    } else {
        ite = this->_base.lower_bound(inputDate);
        std::cout << "lower_bound: " << ite->first << " => " << ite->second << "\n";
        std::cout << "s: " << s << "\n";
        std::cout << inputDate.insert(4,"-").insert(7,"-") << " => "
            << s << " = " << std::fixed << std::setprecision(2);

        // transform bitcoins to string using sstream
        std::stringstream ss;
        ss << bitcoins * ite->second;
        std::string s2 = ss.str();

        // remove right trailing zeros
        s2.erase(s2.find_last_not_of('0') + 1, std::string::npos);

        std::cout << s2 << "\n";
    }
}

