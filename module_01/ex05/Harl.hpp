/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:06:24 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:17:10 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_01_EX05_HARL_HPP
# define MODULE_01_EX05_HARL_HPP

# include <iostream> /* cout, endl */
# include <string> /* string */

/* COLORS */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

class Harl {
 public:
    Harl();
    ~Harl();
    void complain(std::string level);

 private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
};

#endif  // MODULE_01_EX05_HARL_HPP
