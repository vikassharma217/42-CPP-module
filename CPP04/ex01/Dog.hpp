#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"


/* requirments: private Brain* attribute*/
class Dog : public Animal
{
    public:
        Dog();
        Dog (const Dog& rhs);
        Dog& operator=(const Dog& rhs);
        ~Dog();

        void makeSound() const;

    private:
        Brain* brain;

    public:
    /*setter: set brain on particular index*/
        void setIdeaBrain(int i, const std::string& idea);
        std::string getIdeaBrain(int i) const;

};

#endif