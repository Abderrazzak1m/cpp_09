#pragma once
#include <iostream>
#include <map>
#include <fstream>

class  BitcoinExchange
{
    private:
        std::map<std::string, float> input;
    public:
        BitcoinExchange();
        bool getDb();
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        std::string trim(std::string line);
        std::string parseDate(std::string line);
        float parseValue(std::string line);
        bool isDateValide(int year, int month, int day);
        bool isValueValide(std::string value);
        // void print();
};

