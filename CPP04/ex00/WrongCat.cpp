# include "WrongCat.hpp"
# include <iostream>

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called." << std::endl;
    type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &rhs)
    {
        WrongAnimal::operator=(rhs);
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "🐱 MEOW MEOW 🐱" << std::endl;
}