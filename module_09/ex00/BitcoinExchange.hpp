/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:29:50 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/06 13:01:23 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_09_EX00_BITCOINEXCHANGE_HPP_
#define MODULE_09_EX00_BITCOINEXCHANGE_HPP_

#include <iostream>    // std::cout, std::endl
#include <fstream>     // std::ifstream
#include <sstream>     // std::stringstream
#include <map>         // std::map
#include <string>      // std::strin
#include <cstdlib>     // exit
#include <iomanip>     // setprecision

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void readBaseFile();
    void readInputFile(const std::string& filename);
    void processLine(const std::string& line);
    void printOutput(std::string& inputDate, float bitcoins);
    int  parser(int year, int month, int day, std::string line, float &value);

private:
    std::map<std::string, float> _base;

};

bool isValidDigit(char c);
bool isValidDate(int year, int month, int day);
int isValidRate(float rate);
bool parseDate(const std::string& line, int& year, int& month, int& day);


#endif //MODULE_09_EX00_BITCOINEXCHANGE_HPP_
