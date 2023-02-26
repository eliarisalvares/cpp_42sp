/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:57:41 by elraira-          #+#    #+#             */
/*   Updated: 2023/02/26 20:30:47 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream> /* cout, endl */
# include <fstream> /* ifstream, ofstream */
# include <string> /* string */
# include <stdlib.h> /* exit */
# include <sstream> /* stringstream */

class Sed
{
	public:
		Sed(std::string fileName, std::string s1, std::string s2);
		~Sed(void);
		void	replace(void);

	private:
		std::string	_fileName;
		std::string	_s1;
		std::string	_s2;
		std::string	_content;
		int _writeToFile(std::string content);
		int _readFromFile();
		std::string _replaceContent(std::string s1, std::string s2,
			std::string content);
		std::string _addExtension(std::string fileName);
};

#endif
