/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 10:06:00 by spyun         #+#    #+#                 */
/*   Updated: 2025/05/30 14:41:40 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


void addContact(PhoneBook &phoneBook)
{
	Contact contact;

	std::string firstName = getValidInput("Enter first name: ", isValidName);
	contact.setFirstName(firstName);

	std::string lastName = getValidInput("Enter last name: ", isValidName);
	contact.setLastName(lastName);

	std::string nickname = getValidInput("Enter nickname: ", isValidName);
	contact.setNickname(nickname);

	std::string mobileNumber = getValidInput("Enter mobile number: ", isValidNumber);
	contact.setMobileNumber(mobileNumber);

	std::string darkest = getValidInput("Enter darkest secret: ", [](const std::string &str) { return !str.empty(); });
	contact.setDarkestSecret(darkest);

	phoneBook.addContact(contact);
	std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;
}

void searchContact(PhoneBook &phoneBook)
{
	phoneBook.displayContacts();
	std::string strIndex;
	std::cout << "Enter index: ";
	std::getline(std::cin, strIndex);
	try
	{
		int index = std::stoi(strIndex);
		phoneBook.displayContact(index);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Invalid index" << RESET << std::endl;
	}
}

int main ()
{
	PhoneBook phoneBook;
	std::string command;
	std::cout << BLUE <<
	"╔══════════════════════════════════════════════════════╗" << std::endl <<
	"║.---. .-..-. .--. .-..-. .--. .---.  .--.  .--. .-..-.║" << std::endl <<
	"║: .; :: :; :: ,. :: `: :: .--': .; :: ,. :: ,. :: :' ;║" << std::endl <<
	"║:  _.':    :: :: :: .` :: `;  :   .': :: :: :: ::   ' ║" << std::endl <<
	"║: :   : :: :: :; :: :. :: :__ : .; :: :; :: :; :: :.`.║" << std::endl <<
	"║:_;   :_;:_;`.__.':_;:_;`.__.':___.'`.__.'`.__.':_;:_;║" << std::endl <<
	"╚══════════════════════════════════════════════════════╝" << std::endl <<
	"              Commands : ADD, SEARCH, EXIT              " << RESET << std::endl;
	while (true && !std::cin.eof())
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		
		if (std::cin.eof())
		{
			std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
			break;
		}
		
		command = toUpper(command);
		if (command == "ADD")
		{
			addContact(phoneBook);
		}
		else if (command == "SEARCH")
		{
			searchContact(phoneBook);
		}
		else if (command == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << RED << "Invalid command, try again"
				<< RESET << std::endl;
		}
	}
	return 0;
	return 0;
}