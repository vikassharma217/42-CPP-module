#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal(); // default constrcutor
        WrongAnimal(const WrongAnimal& rhs); //copy constructor
        WrongAnimal& operator=(const WrongAnimal& rhs); // copy assignment operator
        ~WrongAnimal(); // default destrcutor

        void makeSound() const;

        /*getter function*/
        std::string getType() const;
};


#endif