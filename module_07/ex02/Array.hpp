/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:42:44 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/25 14:33:22 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_07_ARRAY_HPP_
#define MODULE_07_ARRAY_HPP_

#include <iostream> /* std::cout, std::endl */
#include <string> /* std::string */
#include <exception> /* std::exception */

/* COLORS */
# define RESET "\033[0m"
# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"

template <typename T>
class Array {
 public:
    /* Construction with no params */
    Array<T>(void) : _array(NULL), _size(0) {
        std::cout << "Default array created." << std::endl;
    };


    /* Construction with an unsigned int n as a param: create an array of n
    elements */
    Array<T>(unsigned int n) : _array(new T[n]), _size(n) {
        std::cout << "Array of type " << typeid(T).name() << " and size "
            << _size << " created." << std::endl;
    }

    /* Construction by copy */
    Array<T>(const Array<T> &src) : _array(NULL), _size(0) {
        std::cout << "Array copied." << std::endl;
        *this = src;
    }

    /* Destruction */
    ~Array<T>(void) {
        delete[] _array;
        std::cout << "Array destroyed." << std::endl;
    }

    /* Operator overloads */
    Array &operator=(const Array &rhs) {
        if (this != &rhs) {
            delete[] _array;
            _size = rhs._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = rhs._array[i];
        }
        return (*this);
    }

    T &operator[](unsigned int i) {
        if (i >= _size)
            throw Array::OutOfLimitsException();
        return (_array[i]);
    }

    unsigned int size(void) const {
        return (_size);
    }

    class OutOfLimitsException : public std::exception {
     public:
        virtual const char *what() const throw() {
            return ("Error: Out of limits.");
        }
    };

 private:
    T *_array;
    unsigned int _size;
};

#endif  // MODULE_07_ARRAY_HPP_
