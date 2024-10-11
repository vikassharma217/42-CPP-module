#ifndef Cat_HPP
#define Cat_HPP

# include "Animal.hpp"
# include "Brain.hpp"

/*requirment: new private meber Brain* */
class Cat : public Animal
{
    public:
        Cat();
        Cat (const Cat& rhs);
        Cat& operator=(const Cat& rhs);
        ~Cat();

        void makeSound() const; 

    private:
        Brain* brain;

    public:
        void setIdeaBrain(int i, const std::string& idea);
        std::string getIDeaBrain(int i) const;
};

#endif