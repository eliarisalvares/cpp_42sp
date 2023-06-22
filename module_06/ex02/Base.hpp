/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:50:04 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 21:12:27 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MODULE_06_EX02_BASE_HPP
# define MODULE_06_EX02_BASE_HPP

#include <iostream> /* cout, endl */
#include <cstdlib> /* srand, rand */

class Base {
 public:
    virtual ~Base();
};

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

Base* generate(void);
void identify(Base *p);
void identify(Base &p);


# endif //MODULE_06_EX02_BASE_HPP
