/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:22:50 by eliarisalva       #+#    #+#             */
/*   Updated: 2023/07/04 20:54:05 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int main()
{
    {
        std::cout << PURPLE << "Testing pushing and popping elements" << RESET << std::endl;
        MutantStack<int> mstack;

        std::cout << std::endl;
        std::cout << PURPLE << "1" << RESET << std::endl;
        std::cout << PURPLE << "Pushing 5 and 17 to the stack: " << RESET << std::endl;
        mstack.push(5);
        mstack.push(17);

        std::cout << BLUE << "Top: " << RESET << mstack.top() << std::endl;
        std::cout << BLUE << "Stack size: " << RESET << mstack.size() << std::endl;

        std::cout << std::endl;
        std::cout << PURPLE << "Popping the top element: " << RESET << std::endl;
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
        std::cout << PURPLE << "Popping the top element: " << RESET << std::endl;
        mstack.pop();
        std::cout << BLUE << "New top: " << RESET << mstack.top() << std::endl;
        std::cout << BLUE << "Stack size: " << RESET << mstack.size() << std::endl;

        std::cout << std::endl;
        std::cout << PURPLE << "End of scope" << RESET << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << PURPLE << "----------------------------------------" << RESET << std::endl;
        std::cout << PURPLE << "Testing iterators" << RESET << std::endl;

        MutantStack<int> nstack;

        std::cout << std::endl;
        std::cout << BLUE << "Creating a stack with 5, 17, 21, 42 and 84: " << RESET << std::endl;
        nstack.push(5);
        nstack.push(17);
        nstack.push(21);
        nstack.push(42);
        nstack.push(84);
        std::cout << BLUE << "Stack size: " << RESET << nstack.size() << std::endl;

        std::cout << std::endl;
        std::cout << PURPLE << "1" << RESET << std::endl;
        std::cout << PURPLE << "Iterating through the stack: " << RESET << std::endl;
        MutantStack<int>::iterator it = nstack.begin();
        MutantStack<int>::iterator ite = nstack.end();

        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }

        std::cout << std::endl;
        std::cout << PURPLE << "2" << RESET << std::endl;
        std::cout << PURPLE << "Reverse iterating through the stack: " << RESET << std::endl;

        std::reverse_iterator<MutantStack<int>::iterator> rit = nstack.rbegin();
        std::reverse_iterator<MutantStack<int>::iterator> rite = nstack.rend();

        while (rit != rite) {
            std::cout << *rit << std::endl;
            ++rit;
        }

        std::cout << std::endl;
        std::cout << PURPLE << "End of scope" << RESET << std::endl;
    }
    return 0;
}
