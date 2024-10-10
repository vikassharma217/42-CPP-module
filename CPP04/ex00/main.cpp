# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include <iostream>

int main ()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    WrongAnimal* xCat = new WrongCat();
    std::cout << xCat->getType() << std::endl;
    xCat->makeSound();

    delete meta;
    delete i;
    delete j;
    delete xCat;
    
    return (0);
}




/*int main ()
{
    Animal animal1;

    std::cout << animal1.getType() << std::endl;
    animal1.makeSound();

    std::cout<<std::endl; 

    Dog dog1;
    std::cout << dog1.getType() << std::endl;
    dog1.makeSound();

    std::cout<<std::endl;
    
    Cat cat1;
    std::cout << cat1.getType() << std::endl;
    cat1.makeSound();
 
    return (0);
}*/