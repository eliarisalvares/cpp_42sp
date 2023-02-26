/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:09 by elraira-          #+#    #+#             */
/*   Updated: 2023/02/16 11:58:34 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief An auxiliary function to truncate a string to 10 characters.
 *
 * @param str The string to be truncated.
 * @return std::string The truncated string.
 */
std::string PhoneBook::_truncateString(std::string str)
{
    std::string result = str;
    if (str.length() > 10)
        return result.substr(0, 9) + ".";
    return result;
}
