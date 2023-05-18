/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:19:24 by elraira-          #+#    #+#             */
/*   Updated: 2023/05/17 21:41:27 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_01_EX06_HARL_HPP_
# define MODULE_01_EX06_HARL_HPP_

# include <iostream> /* cout, endl */
# include <string> /* string */

/* COLORS */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define WHITE "\e[1;37m"
# define PURPLE "\033[0;35m"
# define RESET "\033[0m"

class Harl {
 public:
    Harl();
    ~Harl();
    int complain(std::string level);

 private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
};

#endif  /* MODULE_01_EX06_HARL_HPP_ */
