#include"PmergeMe.hpp"

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        PmergeMe pmm(&argv[1]);
        pmm.Ford_JohnsonV();
    }
    return (0);
}