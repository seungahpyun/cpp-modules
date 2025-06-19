/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FileProcessor.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 14:31:32 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/19 15:39:41 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEPROCESSOR_HPP
# define FILEPROCESSOR_HPP

#include <string>
#include <iostream>
#include <fstream>

class FileProcessor
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
		std::ifstream _inputFile;
		std::ofstream _outputFile;

		std::string replaceLine(const std::string& line);
	public:
		FileProcessor(const std::string& filename, const std::string & s1, const std::string& s2);
		~FileProcessor();

		bool validateInputs();
		void printError(const std::string& message) const;
		bool processFile();
};

#endif
