/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/20 12:09:14 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/20 12:13:50 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<int> _stack;

        bool isOperator(const std::string& token);
        bool isNumber(const std::string& token);
        int performOperation(int a, int b, char op);
        void validateExpression(const std::string& expression);
        
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        
        int calculate(const std::string& expression);
};

#endif