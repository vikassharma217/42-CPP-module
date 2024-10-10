# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

/*copy constructor*/
WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called." << std::endl;
    type = "default_WrongAnimal";
}

/*copy construcotr*/
WrongAnimal::WrongAnimal (const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    type = rhs.type;
}

/*copy assignment operator*/
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal assignment operator called." << std::endl;
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "🔔 WrongAnimal MAKES SOUND 🔔" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

