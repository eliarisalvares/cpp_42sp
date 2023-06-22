/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:53:06 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 22:20:35 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    std::cout << PURPLE << "Generate a random class (A, B or C)"
        << RESET << std::endl;
    Base *inst = generate();

    std::cout << std::endl << PURPLE << "Identify from pointer:"
        << RESET << std::endl;
    identify(inst);

    std::cout << std::endl << PURPLE << "Identify from reference:"
        << RESET << std::endl;
    identify(*inst);

    std::cout << std::endl << PURPLE << "Delete instance:"
        << RESET << std::endl;
    delete inst;

    return (0);
}
