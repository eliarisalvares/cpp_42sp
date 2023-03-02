/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:57:41 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:13:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_01_EX04_SED_HPP_
# define MODULE_01_EX04_SED_HPP_

# include <stdlib.h> /* exit */
# include <iostream> /* cout, endl */
# include <fstream> /* ifstream, ofstream */
# include <string> /* string */
# include <sstream> /* stringstream */

class Sed {
 public:
    Sed(std::string fileName, std::string s1, std::string s2);
    ~Sed(void);
    void replace(void);

 private:
    std::string _fileName;
    std::string _s1;
    std::string _s2;
    std::string _content;
    int _writeToFile(std::string content);
    int _readFromFile();
    std::string _replaceContent(std::string s1, std::string s2,
    std::string content);
    std::string _addExtension(std::string fileName);
};

#endif  // MODULE_01_EX04_SED_HPP_
