#pragma once
#include<stack>
#include<iostream>


class RPN
{
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(std::string args);
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);


};