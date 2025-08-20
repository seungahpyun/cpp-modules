/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/20 12:09:07 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/20 12:13:12 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other) 
{
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::calculate(const std::string& expression)
{
    if (expression.empty())
    {
        throw std::runtime_error("Error: empty expression");
    }

    while (!_stack.empty())
    {
        _stack.pop();
    }

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isNumber(token))
        {
            int num = std::atoi(token.c_str());
            _stack.push(num);
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
            {
                throw std::runtime_error("Error: insufficient operands");
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int result = performOperation(a, b, token[0]);
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error: invalid token");
        }
    }

    if (_stack.size() != 1)
    {
        throw std::runtime_error("Error: invalid expression");
    }

    return _stack.top();
}

bool RPN::isNumber(const std::string& token)
{
    if (token.empty()) return false;

    size_t start = 0;
    if (token[0] == '-' && token.length() > 1)
    {
        start = 1;
    }

    for (size_t i = start; i < token.length(); ++i)
    {
        if (!std::isdigit(token[i]))
        {
            return false;
        }
    }

    int num = std::atoi(token.c_str());
    return (num >= 0 && num < 10);
}

bool RPN::isOperator(const std::string& token)
{
    return (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

int RPN::performOperation(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
            {
                throw std::runtime_error("Error: division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Error: unknown operator");
    }
}