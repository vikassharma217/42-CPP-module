# include "Brain.hpp"
# include <iostream>

/*default constructor*/
Brain::Brain()
{
    std::cout << "Brain consttructor called." << std::endl;
}

/*copy constructor */
Brain::Brain(const Brain& rhs)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = rhs.ideas[i];
    }
}

/*assignment operator*/
Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "Assignment operator called." << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

/*default destructor*/
Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}

/*setter: set idea on given index from array*/
void Brain::setIdeas(int i, const std::string& setIdea)
{
    //std::cout << "DEBUG: brain setter" << std::endl;
    if (i >= 0 && i < 100)
    {
        ideas[i] = setIdea;
    }
}

std::string Brain::getIdeas(int i) const
{
    //std::cout << "DEBUG: brain getter" << std::endl;
    if (i >= 0 && i < 100)
        return(ideas[i]);
    else
        return ("");
}