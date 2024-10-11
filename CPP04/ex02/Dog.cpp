# include "Dog.hpp"
# include <iostream>

/*requirments: constuctor: creat Brain using new brain
                destrcutor: destruct brain using delete 
                assignment: modify to make deep copy */
Dog::Dog() : brain(new Brain())
{
    std::cout << "Dog constructor called." << std::endl;
    type = "Dog";
}
Dog::Dog(const Dog& rhs) : Animal(rhs), brain(new Brain(*rhs.brain))
{
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << " >>>WOOF WOOF<<< " << std::endl;
}

void Dog::setIdeaBrain(int i, const std::string& idea)
{
    brain->setIdeas(i, idea);
}

std::string Dog::getIdeaBrain(int i) const
{
    return (brain->getIdeas(i));
}