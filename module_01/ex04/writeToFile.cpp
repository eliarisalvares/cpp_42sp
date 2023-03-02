/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeToFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:25:00 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:15:52 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

/**
 * @brief Add the extension ".replace" to the filename as required by the
 * subject.
 *
 * @param fileName The name of the file to be edited.
 * @return std::string The name of the file with the extension ".replace".
 */
std::string Sed::_addExtension(std::string fileName) {
    std::string nameWithExtension;
    nameWithExtension = fileName.substr(0, fileName.find(".")) + ".replace";
    return (nameWithExtension);
}

/**
 * @brief Write the content to the file.
 *
 * @param content The content to be written to the file.
 * @return int 0 if the file was written successfully, 1 otherwise.
 */
int Sed::_writeToFile(std::string content) {
    std::ofstream file;
    std::string nameWithExtension = this->_addExtension(this->_fileName);
    file.open(nameWithExtension.c_str());
    if (file.is_open()) {
        file << content;
        file.close();
        return (0);
    } else {
        std::cout << "Error: Unable to open file" << std::endl;
        return (1);
    }
}
