# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include <iostream>

// int main ()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     delete j;
//     delete i;

//     return (0);
// }




int main() 
{
    //Animal anim2;
    Animal* anim1[10];

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            anim1[i] = new Dog();
        else
            anim1[i] = new Cat();
    }
    

    for (int i = 0; i < 10; i++)
    {
        if (Dog* dog = dynamic_cast<Dog*>(anim1[i]))
        {
            dog->setIdeaBrain(0, "=====DOG=========");
            std::cout << "Dog: " << i << " " << dog->getIdeaBrain(0) << std::endl;
        }
        else if (Cat* cat = dynamic_cast<Cat*>(anim1[i]))
        {
            cat->setIdeaBrain(0, "*******CAT********");
            std::cout << "Cat: " << i << " "  << cat->getIDeaBrain(0) << std::endl;
        }   
    }

    for (int i = 0; i < 10; i++)
    {
        delete anim1[i];
    }


    // //Set and print some ideas for demonstration
    // Dog* dog1= dynamic_cast<Dog*>(anim1[0]);
    // if (dog1) 
    // {
    //     dog1->setIdeaBrain(0, "======PLAYING==========");
    //     std::cout << "Dog is " << dog1->getIdeaBrain(0) << std::endl;
    // }
    // Cat* cat1 = dynamic_cast<Cat*>(anim1[1]);
    // if (cat1)
    // {
    //     cat1->setIdeaBrain(1, "******SLEEPING*******");
    //     std::cout << "Cat is " << cat1->getIDeaBrain(1) << std::endl;
    // }

    //Clean up

    return 0;
}