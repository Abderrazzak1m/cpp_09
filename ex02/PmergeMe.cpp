#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **args)
{
    std::cout << "Before: ";
    for (int i = 0; args[i] != NULL; i++)
    {
        v.push_back(atoi(args[i]));
        l.push_back(atoi(args[i]));
        std::cout << v.back() << " ";
    }
    std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if(this != &other)
    {
        this->v = other.v;
        this->l = other.l;
    }
    return (*this);
}

void PmergeMe::Ford_JohnsonV()
{
    std::vector<int> v1;
    std::vector<int> v2;
    for(size_t i = 0; i < v.size() - 1; i+=2)
    {
        if(v[i] > v[i + 1])
        {
            v1.push_back(v[i]);
            v2.push_back(v[i + 1]);
        }
        else
        {
            v1.push_back(v[i + 1]);
            v2.push_back(v[i]);
        }

    }
        if(v.size() % 2 != 0)
            v2.push_back(v[v.size() - 1]);
        for(size_t j = 0; j < v1.size(); j++)
        {
            std::cout << v1[j] << " ";
        }
        std::cout << std::endl;
        for(size_t j = 0; j < v2.size(); j++)
        {
            std::cout << v2[j] << " ";
        }
        std::cout << std::endl;
}

void PmergeMe::Ford_JohnsonL()
{
}
