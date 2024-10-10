# include "Cat.hpp"
# include <iostream>

Cat::Cat()
{
    std::cout << "Cat constructor called." << std::endl;
    type = "Cat";
}
Cat::Cat(const Cat& rhs) : Animal(rhs)
{
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "🐱 MEOW MEOW 🐱" << std::endl;
}