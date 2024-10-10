#ifndef Cat_HPP
#define Cat_HPP

# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat (const Cat& rhs);
        Cat& operator=(const Cat& rhs);
        ~Cat();

        void makeSound() const; 
};

#endif