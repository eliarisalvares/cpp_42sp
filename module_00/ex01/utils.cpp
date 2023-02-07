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