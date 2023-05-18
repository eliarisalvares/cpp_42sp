/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFromFile.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:36:57 by elraira-          #+#    #+#             */
/*   Updated: 2023/05/17 21:21:26 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

/**
 * @brief Read the content of the file using ifstream, which is a class to read
 * from files. The method c_str() is used to convert the string to a const char*
 * while the method rdbuf() is used to read the content of the buffer and str()
 * is used to convert the buffer to a string.
 *
 * @return 0 if the file was read successfully, 1 if the file could not be
 * opened, 2 if the file is empty. The string is stored in the private
 * attribute _content.
 */
int Sed::_readFromFile(void) {
    std::ifstream file(this->_fileName.c_str());
    std::string content;
    std::stringstream ss;

    if (!file.is_open())
        return (1);
    ss << file.rdbuf();
    if (ss.str().empty())
        return (2);
    this->_content = ss.str();
    file.close();
    return (0);
}
