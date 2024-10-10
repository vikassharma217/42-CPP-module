# include "Dog.hpp"
# include <iostream>

Dog::Dog()
{
    std::cout << "Dog constructor called." << std::endl;
    type = "Dog";
}
Dog::Dog(const Dog& rhs) : Animal(rhs)
{
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "🐶 WOOF WOOF 🐶" << std::endl;
}