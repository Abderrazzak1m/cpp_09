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
    this->size = v.size();
    Ford_JohnsonV(v);   
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

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

void PmergeMe::Ford_JohnsonV(std::vector<int> &v)
{
    std::map<int, int> m;
    std::vector<int> sortedV;
    std::vector<int> unsortedV;

    
    if(v.size() <= 3)
    {
        std::sort(v.begin(), v.end());
        return;
    }
    size_t size = v.size() % 2 == 0 ? v.size() : v.size() - 1;

    for (size_t i = 0; i < size; i+=2)
    {
        if (v[i] >= v[i + 1])
        {
            sortedV.push_back(v[i]);
            unsortedV.push_back(v[i+ 1]);
            m[v[i]] = v[i+1];
        }
        else
        {
            sortedV.push_back(v[i + 1]);
            unsortedV.push_back(v[i]);
            m[v[i +1]] = v[i];
        }
    }

    if (v.size() % 2 != 0)
    {
        unsortedV.push_back(v.back());
    }
        
    Ford_JohnsonV(sortedV);
   

    // for (size_t i = 0; i < unsortedV.size() ; i++)
    // {
    
    //    std::vector<int>::iterator it = std::upper_bound(sortedV.begin(), sortedV.end(), unsortedV[i]);
    //    sortedV.insert(it, unsortedV[i]);
       
    // }
    v.clear();
    v.assign(sortedV.begin(), sortedV.end());

    for(size_t i = 0; i < sortedV.size(); i++)
    {
        std::cout << "----------------------------------"<< sortedV.size() << std::endl;
        std::map<int, int>::iterator itt = m.find(sortedV[i]);
        if(itt != m.end())
        {
            std::vector<int>::iterator it = std::upper_bound(v.begin(), v.begin() + i, itt->second);
            v.insert(it, itt->second);
        }
    }
    if(v.size() % 2 != 0)
    {
       std::vector<int>::iterator it = std::upper_bound(v.begin(), v.end(), unsortedV.back());
         v.insert(it, unsortedV.back());
    }

   
//     if(v.size() == sortedV.size())
//     {   v.clear();
//         v = sortedV;
//     }
}
void PmergeMe::Ford_JohnsonL()
{
}
