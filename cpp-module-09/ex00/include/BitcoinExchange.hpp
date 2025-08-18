/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 08:55:28 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/18 09:23:09 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _database;

		bool isValidDate(const std::string& date);
		bool isValidValue(double value);
		std::string trim(const std::string& str);
		bool parseLine(const std::string& line, std::string& date, double& value, char delimiter);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool loadDatabase(const std::string& filename);
		void processInputFile(const std::string& filename);
		double getExchangeRate(const std::string& date);
};

#endif
