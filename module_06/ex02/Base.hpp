/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:50:04 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 21:54:30 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MODULE_06_EX02_BASE_HPP_
# define MODULE_06_EX02_BASE_HPP_

#include <iostream> /* cout, endl */
#include <cstdlib> /* srand, rand */

/* BASE CLASS */
class Base {
 public:
    virtual ~Base();
};

/* DERIVED CLASSES */
class A : public Base {
 public:
    ~A();
};

class B : public Base {
 public:
    ~B();
};

class C : public Base {
 public:
    ~C();
};

/* FUNCTIONS */
Base* generate(void);
void identify(Base *p);
void identify(Base &p);


# endif  // MODULE_06_EX02_BASE_HPP_
