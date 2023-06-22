/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:53:53 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 21:13:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

A::~A() {
    std::cout << "A destructor called" << std::endl;
}

B::~B() {
    std::cout << "B destructor called" << std::endl;
}

C::~C() {
    std::cout << "C destructor called" << std::endl;
}

Base* generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0) {
        std::cout << "A generated" << std::endl;
        return new A();
    } else if (random == 1) {
        std::cout << "B generated" << std::endl;
        return new B();
    } else {
        std::cout << "C generated" << std::endl;
        return new C();
    }
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    Base tmp;
    try {
        std::cout << "A" << std::endl;
        tmp = dynamic_cast<A&>(p);
        std::cout << "Success" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Fail" << std::endl;
    }
    try {
        std::cout << "B" << std::endl;
        tmp = dynamic_cast<B&>(p);
        std::cout << "Success" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Fail" << std::endl;
    }
    try {
        std::cout << "C" << std::endl;
        tmp = dynamic_cast<C&>(p);
        std::cout << "Success" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Fail" << std::endl;
    }
}
