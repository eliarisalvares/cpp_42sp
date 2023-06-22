/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:53:06 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 22:01:10 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    Base *inst = generate();

    std::cout << std::endl << "<POINTER> :" << std::endl;
    identify(inst);
    std::cout << std::endl << "<REFERENCE> :" << std::endl;
    identify(*inst);
    delete inst;
    return (0);
}
