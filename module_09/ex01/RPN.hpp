/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:38:31 by elraira-          #+#    #+#             */
/*   Updated: 2023/07/21 18:54:39 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_09_EX01_RPN_HPP_
#define MODULE_09_EX01_RPN_HPP_

#include <iostream>    // std::cout, std::endl
#include <stack>       // std::stack
#include <sstream>     // std::stringstream
#include <iomanip>     // std::setprecision

class RPN {
 public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    void processLine(const std::string& line);
    int getRpnResult(int a, int b, char c);

 private:
    std::stack<float> _stack;
};

#endif  // MODULE_09_EX01_RPN_HPP_


