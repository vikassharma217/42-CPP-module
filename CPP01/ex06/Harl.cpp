#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup"
				<< "burger. I really do!" << std::endl;
	std::cout << std::endl;			
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more "
				<< "money. You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you "
				<< "started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to "
				<< "the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	// array of private member function pointer
	void (Harl::*functionPtr[])(void) = {	
				&Harl::debug, 
				&Harl::info,
				&Harl::warning, 
				&Harl::error
			};

	// array of string to match  level
	std::string levelsArr[] = 
		{
			"DEBUG", 
			"INFO", 
			"WARNING", 
			"ERROR"
		};
	int levelIndex = -1;
	for (int i = 0; i < 4; i++)
    {
        if (levelsArr[i] == level)
        {
            levelIndex = i;
            break;
        }
    }

	// Switch statement based on the level without using break
	switch (levelIndex)
    {
        case 0:
            (this->*functionPtr[0])();
        case 1:
            (this->*functionPtr[1])();
        case 2:
            (this->*functionPtr[2])();
        case 3:
            (this->*functionPtr[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
