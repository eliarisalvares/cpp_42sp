/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFromFile.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:36:57 by elraira-          #+#    #+#             */
/*   Updated: 2023/02/26 20:30:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

/**
 * @brief Read the content of the file.
 *
 * @return std::string The content of the file.
 */
int Sed::_readFromFile(void)
{
	std::ifstream file(this->_fileName.c_str());
	std::string content;

	if (!file.is_open())
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return (1);
	}
	std::stringstream ss;
	ss << file.rdbuf();
	this->_content = ss.str();
	file.close();
	return (0);
}
