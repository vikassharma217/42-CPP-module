#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
    protected:
        std::string type;

    public:
        Animal(); // default constrcutor
        Animal(const Animal& rhs); //copy constructor
        Animal& operator=(const Animal& rhs); // copy assignment operator
        virtual ~Animal(); // default destrcutor

        virtual void makeSound() const;

        /*getter function*/
        std::string getType() const;
};


#endif