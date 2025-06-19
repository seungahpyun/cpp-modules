/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FileProcessor.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 14:36:19 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/19 08:58:00 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

FileProcessor::FileProcessor(const std::string &filename, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2)
{
	_inputFile.open(_filename);
	if (!_inputFile.is_open())
		printError("Cannot open input file.");

	_outputFile.open(_filename + ".replace");
	if (!_outputFile.is_open())
		printError("Cannot create output file.");
}

FileProcessor::~FileProcessor()
{
	if (_inputFile.is_open())
		_inputFile.close();
	if (_outputFile.is_open())
		_outputFile.close();
}

std::string FileProcessor::replaceLine(const std::string &line)
{
	std::string result = "";
	size_t pos = 0;
	size_t found = 0;

	while ((found = line.find(_s1, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos);
		result += _s2;
		pos = found + _s1.length();
	}
	result += line.substr(pos);
	return result;
}

bool FileProcessor::validateInputs()
{
	if (_s1.empty())
	{
		printError("s1 cannot be empty.");
		return (false);
	}
	if (!_inputFile.is_open())
	{
		printError("Input file is not open.");
		return (false);
	}
	if (!_outputFile.is_open())
	{
		printError("Output file is not open.");
		return (false);
	}
	return (true);
}

void FileProcessor::printError(const std::string &message) const
{
	std::cout << "Error: " << message << std::endl;
}

bool FileProcessor::processFile()
{
	if (!validateInputs())
		return (false);

	std::string line;
	while (std::getline(_inputFile, line))
	{
		std::string replacedLine = replaceLine(line);
		_outputFile << replacedLine;
		if (!_inputFile.eof())
			_outputFile << std::endl;
	}
	return (true);
}

