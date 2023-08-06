/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:40:29 by elraira-          #+#    #+#             */
/*   Updated: 2023/07/21 19:05:06 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
    std::cout << "RPN object created." << std::endl;
}

RPN::~RPN() {
    std::cout << "RPN object destroyed." << std::endl;
}

RPN::RPN(const RPN &other) {
    std::cout << "RPN object copied." << std::endl;
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

/**
 * Check if the given character is a valid digit.
 *
 * @param c The character to be checked.
 * @return true if the character is a valid digit, false otherwise.
 */
bool isValidDigit(char c) {
    return (c >= '0' && c <= '9');
}

/**
 * Process a line containing RPN expressions and evaluate the result.
 *
 * @param line The line containing RPN expressions. The line should contain
 * space-separated tokens, where each token is either a number or an arithmetic
 * operator (+, -, *, /, %). The function will evaluate the RPN expression and
 * print the result if it's valid. If there are not enough numbers in the stack
 * for an operator or if an invalid token is encountered, appropriate error
 * messages are printed. If there are too many numbers in the stack after
 * evaluation, an error message is displayed.
 */
void RPN::processLine(const std::string& line) {
    std::stringstream ss(line);
    std::string token;
    int a, b;
    char c;

    while (ss >> token) {
        if (isValidDigit(token[0])) {
            this->_stack.push(std::stoi(token));
        } else if (token.length() == 1 && !isValidDigit(token[0])) {
            if (this->_stack.size() < 2) {
                std::cout << "Error: Not enough numbers in stack." << std::endl;
                return;
            }
            a = this->_stack.top();
            this->_stack.pop();
            b = this->_stack.top();
            this->_stack.pop();
            c = token[0];
            this->_stack.push(getRpnResult(a, b, c));
        } else {
            std::cout << "Error: Invalid token." << std::endl;
            return;
        }
    }
    if (this->_stack.size() > 1) {
        std::cout << "Error: Too many numbers in stack." << std::endl;
        return;
    }
    std::cout << "Result: " << this->_stack.top() << std::endl;
}

/**
 * Evaluate the RPN expression for the given arithmetic operation.
 *
 * @param a The first operand of the arithmetic operation.
 * @param b The second operand of the arithmetic operation.
 * @param c The arithmetic operator (+, -, *, /, %) to apply on the operands.
 * @return The result of the arithmetic operation.
 *
 * The function takes two integer operands and an arithmetic operator and
 * performs the corresponding arithmetic operation. If the operator is '/',
 * it checks for division by zero and throws a runtime_error if the divisor is
 * zero. If the operator is not one of the valid arithmetic operators, it
 * returns zero.
 */
int RPN::getRpnResult(int a, int b, char c) {
    switch (c) {
        case '+':
            return b + a;
        case '-':
            return b - a;
        case '*':
            return b * a;
        case '/':
        {
            if (a == 0) {
                throw std::runtime_error("Error: Division by zero.");
            }
            return b / a;
        }
        case '%':
            return b % a;
        default:
            return 0;
    }

}
