/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:14:56 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/18 15:00:14 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << YELLOW << "Creating bureaucrats: " << RESET << std::endl;
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);

    std::cout << std::endl;
    std::cout << YELLOW << "Creating forms: " << RESET << std::endl;
    Form f1("f1", 1, 1);
    Form f2("f2", 150, 150);

    std::cout << std::endl;
    std::cout << YELLOW << "Bureaucrats: " << RESET << std::endl;
    std::cout << "b1: " << std::endl;
    std::cout << b1 << std::endl;
    std::cout << "b2: " << std::endl;
    std::cout << b2 << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "Forms: " << RESET << std::endl;
    std::cout << "f1: " << std::endl;
    std::cout << f1 << std::endl;
    std::cout << "f2: " << std::endl;
    std::cout << f2 << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "Trying to sign forms: " << RESET << std::endl;
    std::cout << "b1 tries to sign f1: " << std::endl;
    b1.signForm(f1);

    std::cout << std::endl;
    std::cout << "b1 tries to sign f2: " << std::endl;
    b1.signForm(f2);

    std::cout << std::endl;
    std::cout << "b2 tries to sign f1: " << std::endl;
    b2.signForm(f1);

    std::cout << std::endl;
    std::cout << "b2 tries to sign f2: " << std::endl;
    b2.signForm(f2);

    std::cout << std::endl;
    std::cout << YELLOW << "End of scope: " << RESET << std::endl;
    return 0;
}
