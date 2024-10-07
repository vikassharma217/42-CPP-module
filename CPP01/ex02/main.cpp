# include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "Memory add of string variable: " << &brain << std::endl;
    std::cout << "Memory add of stringPTR:       " << stringPTR << std::endl;
    std::cout << "Memory add of stringREF:       " << &stringREF << std::endl;

    std::cout << "Value of string:    " << brain << std::endl;
    std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "VAlue of stringREF: " << stringREF << std::endl;
    return (0);
}