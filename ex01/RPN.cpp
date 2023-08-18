#include "RPN.hpp"

RPN::RPN() 
{
}
RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->stack = other.stack;
    }
    return *this;
}

RPN::RPN(std::string args) 
{
    for (size_t i = 0;i< args.size(); i++)
    {
        if (args[i] == ' ')
            continue;
        if (args[i] >= '0' && args[i] <= '9')
            this->stack.push(args[i] - '0');
        else if ((args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/') && this->stack.size() >= 2)
        {
            int a = this->stack.top();
            this->stack.pop();
            int b = this->stack.top();
            this->stack.pop();

            if (args[i] == '+')
                this->stack.push(a + b);
            else if (args[i] == '-')
                this->stack.push(b - a);
            else if (args[i] == '*')
                this->stack.push(b * a);
            else if (args[i] == '/')
            {
                if(a == 0)
                {
                    std::cout << "Error: cannot divide by zero" << std::endl;
                    return;
                }
                else
                    this->stack.push(b / a);
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
            return;
        }
    }
    if (this->stack.size() == 1)
        std::cout << this->stack.top() << std::endl;
    else
        std::cout << "Error" << std::endl;
}
