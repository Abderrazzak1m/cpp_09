#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>

class PmergeMe
{ 
    private:
        std::vector<int> v;
        std::list<int> l;
    public:
        PmergeMe();
        PmergeMe(char **args);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        void Ford_JohnsonV();
        void Ford_JohnsonL();
};