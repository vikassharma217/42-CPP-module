#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

/*requirment: make animal class abstract , so we can not creat generic animal object*/

class Animal
{
    protected:
        std::string type;
        static int count;

    public:
        Animal(); // default constrcutor
        Animal(const Animal& rhs); //copy constructor
        Animal& operator=(const Animal& rhs); // copy assignment operator
        virtual ~Animal(); // default destrcutor

        virtual void makeSound() const = 0;

        /*getter function*/
        std::string getType() const;
};


#endif