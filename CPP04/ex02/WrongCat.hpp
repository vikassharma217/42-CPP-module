#ifndef WrongCat_HPP
#define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat (const WrongCat& rhs);
        WrongCat& operator=(const WrongCat& rhs);
        ~WrongCat();

        void makeSound() const; 
};

#endif