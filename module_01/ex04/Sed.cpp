/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:53:26 by elraira-          #+#    #+#             */
/*   Updated: 2023/02/26 20:30:15 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

/**
 * @brief Construct a new Sed:: Sed object.
 *
 * @param filename The name of the file to be edited.
 * @param s1 The string to be replaced.
 * @param s2 The string to replace s1.
 */
Sed::Sed(std::string fileName, std::string s1, std::string s2)
{
	this->_fileName = fileName;
	this->_s1 = s1;
	this->_s2 = s2;
}

/**
 * @brief Destroy the Sed:: Sed object.
 *
 */
Sed::~Sed(void)
{
}

std::string Sed::_replaceContent(std::string s1, std::string s2, std::string content)
{
	std::string newContent = "";

	for (size_t i = 0; i < content.length(); i++)
	{
		if (content.substr(i, s1.length()) == s1)
		{
			newContent = newContent + s2;
			i += s1.length() - 1;
		}
		else
			newContent += content[i];
	}
	return (newContent);
}

void Sed::replace(void)
{
	if (this->_readFromFile() != 0)
	{
		std::cerr << "Error: Unable to open file" << std::endl;
		exit(1);
	}
	std::string newContent = this->_replaceContent(this->_s1, this->_s2,this->_content);
	if (this->_writeToFile(newContent) != 0)
	{
		std::cerr << "Error: Unable to write to file" << std::endl;
		exit(1);
	}
}
