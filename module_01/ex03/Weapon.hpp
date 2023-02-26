/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:33:51 by elraira-          #+#    #+#             */
/*   Updated: 2023/02/26 17:34:09 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream> /* cout, endl */
# include <string> /* string */

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string& getType(void);
		void setType(std::string type);
	private:
		std::string	_type;
};

#endif
