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
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        bool getDb();
        std::string trim(std::string line);
        std::string parseDate(std::string line);
        float parseValue(std::string line);
        bool isDateValide(int year, int month, int day);
        bool isValueValide(std::string value);
        // void print();
};

