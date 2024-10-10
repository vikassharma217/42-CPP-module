# include "Animal.hpp"
# include <string>
# include <iostream>

/*copy constructor*/
Animal::Animal()
{
    std::cout << "Animal constructor called." << std::endl;
    type = "default_animal";
}

/*copy construcotr*/
Animal::Animal (const Animal& rhs)
{
    std::cout << "Animal copy constructor called." << std::endl;
    type = rhs.type;
}

/*copy assignment operator*/
Animal& Animal::operator=(const Animal& rhs)
{
    std::cout << "Animal assignment operator called." << std::endl;
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "🔔 ANIMAL MAKES SOUND 🔔" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

