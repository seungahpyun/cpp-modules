/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 08:55:28 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/18 11:14:04 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

bool		loadDatabase(const std::string& filename, std::map<std::string, double>& database);
void		processInputFile(const std::string& filename, const std::map<std::string, double>& database);

double		getExchangeRate(const std::string& date, const std::map<std::string, double>& database);
bool		isValidDate(const std::string& date);
bool		isValidValue(double value);
std::string	trim(const std::string& str);

#endif
