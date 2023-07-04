/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliarisalvares <eliarisalvares@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:22:50 by eliarisalva       #+#    #+#             */
/*   Updated: 2023/07/04 15:21:21 by eliarisalva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

    std::cout << std::endl;
    std::cout << PURPLE << "1" << RESET << std::endl;
    std::cout << PURPLE << "Pushing 5 and 17 to the stack: " << RESET << std::endl;
	mstack.push(5);
	mstack.push(17);

    std::cout << BLUE << "Top: " << RESET << mstack.top() << std::endl;
    std::cout << BLUE << "Stack size: " << RESET << mstack.size() << std::endl;

    std::cout << std::endl;
    std::cout << PURPLE << "Poping the top element: " << RESET << std::endl;
    mstack.pop();
    std::cout << BLUE << "New top: " << RESET << mstack.top() << std::endl;
    std::cout << BLUE << "Stack size: " << RESET << mstack.size() << std::endl;

    std::cout << std::endl;
    std::cout << PURPLE << "2" << RESET << std::endl;
    std::cout << PURPLE << "Pushing 21, 42 and 84 to the stack: " << RESET << std::endl;
    mstack.push(21);
    mstack.push(42);
    mstack.push(84);

    std::cout << BLUE << "Top: " << RESET << mstack.top() << std::endl;
    std::cout << BLUE << "Stack size: " << RESET << mstack.size() << std::endl;

    std::cout << std::endl;
    std::cout << PURPLE << "Poping the top element: " << RESET << std::endl;
    mstack.pop();
    std::cout << BLUE << "New top: " << RESET << mstack.top() << std::endl;
    std::cout << BLUE << "Stack size: " << RESET << mstack.size() << std::endl;

    std::cout << std::endl;
    std::cout << PURPLE << "4" << RESET << std::endl;
    std::cout << PURPLE << "Using iterators on the stack: " << RESET << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << BLUE << "Printing the stack: " << RESET;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    std::cout << "Begin of the stack: " << rit[0] << std::endl;
    std::cout << "End of the stack: " << rite[0] << std::endl;

    std::cout << BLUE << "Printing the stack: " << RESET;
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "End of scope" << std::endl;
    return 0;
}


    