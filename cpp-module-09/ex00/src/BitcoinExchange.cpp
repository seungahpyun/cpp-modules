/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 08:55:37 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/20 11:59:31 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool loadDatabase(const std::string& filename, std::map<std::string, double>& database)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string date;
        double value;
        if (parseCSVLine(line, date, value))
        {
            database[date] = value;
        }
    }
    return true;
}

void processInputFile(const std::string& filename, const std::map<std::string, double>& database)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string date;
        double value;
        if (parseInputLine(line, date, value)) 
        {
            if (!isValidDate(date))
            {
                std::cerr << "Error: bad date => " << date << std::endl;
            }
            else if (!isValidValue(value))
            {
                std::cerr << "Error: bad value => " << value << std::endl;
            }
            else
            {
                double exchangeRate = getExchangeRate(date, database);
                if (exchangeRate < 0.0)
                {
                    std::cerr << "Error: no exchange rate found for date => " << date << std::endl;
                    continue;
                }
                double result = exchangeRate * value;
                std::cout << date << " => " << value << " * " << exchangeRate << " = " << result << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}

bool parseCSVLine(const std::string& line, std::string& date, double& value)
{
    if (line == "date,exchange_rate")
        return false;

    std::istringstream ss(line);
    std::string token;

    if (!std::getline(ss, date, ',') || !std::getline(ss, token))
        return false;

    date = trim(date);
    token = trim(token);

    try
    {
        value = std::stod(token);
    }
    catch (const std::exception&)
    {
        return false;
    }

    return true;
}

bool parseInputLine(const std::string& line, std::string& date, double& value)
{
    if (line == "date | value")
        return false;

    std::istringstream ss(line);
    std::string pipe, token;

    if (!(ss >> date >> pipe >> token) || pipe != "|")
        return false;
        
    try {
        value = std::stod(token);
    } catch (const std::exception&) {
        return false;
    }

    return true;
}

double getExchangeRate(const std::string& date, const std::map<std::string, double>& database)
{
    auto it = database.lower_bound(date);
    if (it != database.begin())
    {
        --it;
        return it->second;
    }
    return -1.0;
}

bool isValidDate(const std::string& date)
{
	std::regex datePattern(R"(\d{4}-\d{2}-\d{2})");
	return std::regex_match(date, datePattern);
}

bool isValidValue(double value)
{
	return value >= 0.0 && value <= 1000.0;
}

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	if (first == std::string::npos || last == std::string::npos)
		return "";
	return str.substr(first, last - first + 1);
}
