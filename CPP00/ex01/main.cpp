/* entry point of the programme, create an instance of the PhoneBook class
	and enter a loop read user commands (ADD, SEARCH, EXIT) andcall the
	corresponding methods from the PhoneBook class */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;

	std::string command;
	while (std::cin)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		command = phonebook.trim(command);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break ;
		}
		else
			std::cout << "Please enter only ADD, SEARCH, or EXIT: " << std::endl;
	}
	return (0);
}
