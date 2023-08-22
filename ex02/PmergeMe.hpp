#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>

class PmergeMe
{ 
    private:
        std::vector<int> v;
        std::list<int> l;
        size_t size;
    public:
        PmergeMe();
        PmergeMe(char **args);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        void Ford_JohnsonV(std::vector<int> &v);
        void Ford_JohnsonL();
};