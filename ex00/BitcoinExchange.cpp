#include "BitcoinExchange.hpp"

bool BitcoinExchange::getDb()
{
    std::ifstream file("data.csv");
    std::string line;
    if(!file.is_open())
    {
        std::cout<<"Error: Data not found"<<std::endl;
        return false;
    }
    std::getline(file, line);
    while(std::getline(file, line))
    {
        std::string key = line.substr(0, 10);
        std::string value = line.substr(11);
        input[key] = std::stof(value);
    }
    return true ;
}


BitcoinExchange::BitcoinExchange()
{

}



BitcoinExchange::BitcoinExchange(std::string filename)
{
    std::ifstream file(filename);
    std::string line;
    if(!getDb()) return;
    if(!file.is_open() )
    {
        std::cout<<"Error: file not found"<<std::endl;
        return;
    }
    if(!std::getline(file, line) || trim(line) != "date | value")
    {
        std::cout<<"Error: file is not valid"<<std::endl;
        return;
    }
    while(std::getline(file, line))
    {
        line = trim(line);
        std::string date = parseDate(line);
        if(date == "")
        {
            std::cout<<"Error: bad input => "<< line.substr(0, 10)<<std::endl;
            continue;
        }
        line = trim(line.substr(10));
        float value = parseValue(line);
        if(value == 1001) continue;
        std::map<std::string, float>::iterator it = input.lower_bound(date);
        if(it == input.begin() && it->first != date)
        {
            std::cout <<"bad input"<< std::endl;
        }
        if(it->first != date)
            it--;
        
        std::cout << date << " => " << value << " = "<< it->second * value << std::endl;
    }

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
    {
        input = other.input;
    }
    return *this;
}

std::string BitcoinExchange::trim(std::string line)
{
    std::string ws = " \t\n\r\f\v";
    size_t i = 0;
    while(ws.find(line[i]) != std::string::npos)
     {
        line.erase(i, 1);
     }
    i = line.size() - 1;
    while(ws.find(line[i]) != std::string::npos)
    {
        line.erase(i, 1);
        i--;
    }
    return line;
}

std::string BitcoinExchange::parseDate(std::string line)
{
    int year, month, day;
    if(line.size() > 10)
    {
        std::string date = line.substr(0, 10);
        if(std::count(date.begin(), date.end(), '-') != 2)
            return "";
        year =(int)std::stof(date.substr(0, 4));
        month =(int)std::stof(date.substr(5, 2));
        day =(int)std::stof(date.substr(8, 2));
        if(!isDateValide(year, month, day))
            return "";  
        return line.substr(0, 10);
    }
    return "";

}

float BitcoinExchange::parseValue(std::string line)
{
    if(line.size() >= 3)
    {
       if(line[0] != '|' && line[1] != ' ')
        {
            std::cout << "Error: bad input => "<< line<<std::endl;
            return 1001;
        }
        std::string value = trim(line.substr(1));
        if(std::count(value.begin(), value.end(), '.') > 1 || value[0] == '.' || value[value.size() - 1] == '.')
        {
            std::cout << "Error: bad input => "<< line<<std::endl;
            return 1001;
        }
        if(value[0] == '-')
        {
            std::cout << "Error: not a positive number."<< std::endl;
            return 1001;
        }
        for(size_t i = 0; i < value.size(); i++)
        {
            if(value[i] == '.' || value[0] == '-')
                continue;
            if(value[i] < '0' || value[i] > '9')
            {
                std::cout << "Error: bad input => "<< line<<std::endl;
                return 1001;
            }
        }
        float tmp = std::stof(value);
        if((value.find('.') != std::string::npos && value.find('.') > 4)|| tmp > 1000 )
        {
            std::cout << "Error: too long number."<< std::endl;
            return 1001;
        }
        return tmp;
    }
    return 1001;
}


bool BitcoinExchange::isDateValide(int year, int month, int day)
{
  
    if(year < 2009 || month <= 0 || month > 12 || day <= 0)
        return false;
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        daysInMonth[1] = 29;
    return day <= daysInMonth[month - 1];
}