/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 08:55:28 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/13 08:57:18 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        
        bool loadDatabase(const std::string& filename);
        void processInputFile(const std::string& filename);
        bool isValidDate(const std::string& date);
        bool isValidValue(double value);
        double findClosestPrice(const std::string& date);
};

#endif