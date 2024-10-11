# include "Cat.hpp"
# include <iostream>


/*requirments: constuctor: creat Brain using new brain
                destrcutor: destruct brain using delete 
                assignment: modify to make deep copy */
Cat::Cat() : brain (new Brain())
{
    std::cout << "Cat constructor called." << std::endl;
    type = "Cat";
}
Cat::Cat(const Cat& rhs) : Animal(rhs), brain (new Brain(*rhs.brain))
{
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete brain;
        brain = new Brain(*rhs.brain); // makes a deep copy
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << " >>>MEOW MEOW<<< " << std::endl;
}

void Cat::setIdeaBrain(int i, const std::string& idea)
{
    //std::cout << "DEBUG: setter from Cat" << std::endl;
    brain->setIdeas(i, idea);
}

std::string Cat::getIDeaBrain(int i) const
{
    //std::cout << "DEBUG: setter from Cat" << std::endl;
    return (brain->getIdeas(i));
}