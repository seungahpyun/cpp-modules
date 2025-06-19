/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 13:57:37 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/19 09:04:53 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];

		FileProcessor fileProcessor(filename, s1, s2);
		if (!fileProcessor.processFile())
		{
			fileProcessor.printError("File processing failed.");
			return (1);
		}
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	return (0);
}

/*
test :
echo "Hello world
Hello universe
Goodbye world" > test.txt

./ex04 test.txt "Hello" "Hi"

cat test.txt.replace
 */
