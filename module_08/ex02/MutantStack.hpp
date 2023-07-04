/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:38:09 by eliarisalva       #+#    #+#             */
/*   Updated: 2023/07/04 20:46:12 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_08_EX02_MUTANTSTACK_HPP_
#define MODULE_08_EX02_MUTANTSTACK_HPP_

#include <algorithm> /* find */
#include <iostream>  /* cout, endl */
#include <iterator>  /* begin, end */
#include <string>    /* string */
#include <vector>    /* vector */
#include <stack>     /* stack */
#include <list>      /* list */

/* COLORS */
# define RESET "\033[0m"
# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define PURPLE "\033[1;35m"

template <typename T>
class MutantStack : public std::stack<T> {
 private:
    std::deque<T> c;

 public:

    /* CANONICAL FORM */
    MutantStack() : std::stack<T>(), c(std::deque<T>()) {
        this->c = std::deque<T>();
        std::cout << BLUE "MutantStack created" RESET << std::endl;
    }

    MutantStack(const MutantStack &other) : std::stack<T>(other) {
        std::cout << BLUE "MutantStack created by copy" RESET << std::endl;
    }

    virtual ~MutantStack() {
        std::cout << BLUE "MutantStack destroyed" RESET << std::endl;
    }

    MutantStack &operator=(const MutantStack &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }

    /* ITERATORS */
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return std::stack<T>::c.begin();
    }

    iterator end() {
        return std::stack<T>::c.end();
    }

    /* REVERSE ITERATORS */
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

    reverse_iterator rbegin() {
        return std::stack<T>::c.rbegin();
    }

    reverse_iterator rend() {
        return std::stack<T>::c.rend();
    }
};

#endif  // MODULE_08_EX02_MUTANTSTACK_HPP_
