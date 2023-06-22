/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:53:53 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 22:29:45 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/* Base Destructor */
Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

/* A Destructor */
A::~A() {
    std::cout << "A destructor called" << std::endl;
}

/* B Destructor */
B::~B() {
    std::cout << "B destructor called" << std::endl;
}

/* C Destructor */
C::~C() {
    std::cout << "C destructor called" << std::endl;
}

/**
 * @brief Generate a random Base object. Rand_r() is a reentrant version of
 * rand() that takes a pointer to an unsigned int as a parameter. The seed
 * value is stored through this pointer. The rand_r() function returns a
 * pseudo-random integer in the range [0, RAND_MAX]. But in this case, the
 * range is [0, 2] because we want to generate a random number between 0 and 2
 * to choose which class to instantiate.
 *
 * @return Base* A pointer to a new Base object.
 */
Base* generate(void) {
    unsigned int seed = time(NULL);
    int random = rand_r(&seed) % 3;

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

/**
 * @brief This function identifies the type of the Base object passed as
 * parameter. If the object is an instance of A, the function prints "A" and
 * returns. If the object is an instance of B, the function prints "B" and
 * returns. If the object is an instance of C, the function prints "C" and
 * returns. Dynamic cast is a cast operator that safely converts pointers and
 * references to classes up, down, and sideways along the inheritance hierarchy.
 *
 * @param p A pointer to a Base object.
 */
void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

/**
 * @brief This function identifies the type of the Base object passed as
 * parameter. If the object is an instance of A, the function prints "A" and
 * returns. If the object is an instance of B, the function prints "B" and
 * returns. If the object is an instance of C, the function prints "C" and
 * returns. Dynamic cast is a cast operator that safely converts pointers and
 * references to classes up, down, and sideways along the inheritance hierarchy.
 *
 * @param p A reference to a Base object.
 */
void identify(Base& p) {
    Base tmp;

    try {
        std::cout << "A" << std::endl;
        tmp = dynamic_cast<A&>(p);
        std::cout << "It's an A" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Not an A" << std::endl;
    }
    try {
        std::cout << "B" << std::endl;
        tmp = dynamic_cast<B&>(p);
        std::cout << "It's a B" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Not a B" << std::endl;
    }
    try {
        std::cout << "C" << std::endl;
        tmp = dynamic_cast<C&>(p);
        std::cout << "It's a C" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Not a C" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "End of tmp scope:" << std::endl;
}
