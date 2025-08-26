/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 08:55:37 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/26 10:49:02 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool loadDatabase(const std::string& filename, std::map<std::string, double>& database)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(file, line))
	{
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
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::string date;
		double value;

		if (parseInputLine(line, date, value))
		{
			if (!isValidDate(date))
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (value < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}

			double exchangeRate = getExchangeRate(date, database);
			if (exchangeRate < 0.0)
			{
				std::cerr << "Error: no exchange rate found for date => " << date << std::endl;
				continue;
			}
			double result = value * exchangeRate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		else
		{
			if (line != "date | value")
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

double getExchangeRate(const std::string& date, const std::map<std::string, double>& database)
{
	auto it = database.find(date);
	if (it != database.end())
		return it->second;

	it = database.lower_bound(date);
	if (it != database.begin())
	{
		--it;
		return it->second;
	}

	return -1.0;
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	try
	{
		int year = std::stoi(yearStr);
		int month = std::stoi(monthStr);
		int day = std::stoi(dayStr);

		if (year < 1000 || year > 9999)
			return false;
		if (month < 1 || month > 12)
			return false;
		if (day < 1 || day > 31)
			return false;

		if (month == 2)
		{
			if (isLeapYear(year) && day > 29) return false;
			if (!isLeapYear(year) && day > 28) return false;
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return false;

	}
	catch (const std::exception&)
	{
		return false;
	}

	return true;
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
