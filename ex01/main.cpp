#include"RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "ERROR" << std::endl;
        return 1;
    }
    std::string args(argv[1]);
    RPN rpn(args);
    return 0;
}