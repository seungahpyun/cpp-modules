/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 08:55:37 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/18 12:22:35 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool parseLine(const std::string& line, std::string& date, double& value)
{
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
	catch (const std::invalid_argument&)
	{
		return false;
	}

	return true;
}

double getExchangeRate(const std::string& date, const std::map<std::string, double>& database)
{
	auto it = database.find(date);
	if (it != database.end())
	{
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
