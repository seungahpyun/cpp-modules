/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/21 13:53:08 by spyun         #+#    #+#                 */
/*   Updated: 2025/05/30 14:32:07 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void printUpper(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
		{
			str[j] = std::toupper(str[j]);
		}
		std::cout << str;
		if (i < argc - 1)
			std::cout << " ";
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		printUpper(argc, argv);
	std::cout << std::endl;
	return 0;
}
