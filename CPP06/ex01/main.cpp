# include "Serializer.hpp"
# include <stdint.h>
# include <iostream>

int main() 
{
    // Create a Data object
    Data d;
    d.myInt = 42;
    d.myString = "Vienna";
    d.myChar = 'C';
    d.myBool = true;


    // Serialize the Data object
    std::cout << "Mem add of d              : " << &d << std::endl;
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized uintptr_t value: " << raw << std::endl;

    // Deserialize back to a Data pointer
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized : " << deserializedData << std::endl;

    // Verify if the deserialized data is the same as the original
    if (deserializedData == &d) 
    {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "myInt: " << deserializedData->myInt << std::endl;
        std::cout << "myString: " << deserializedData->myString << std::endl;
        std::cout << "myChar: " << deserializedData->myChar << std::endl;
        std::cout << "myBool: " << deserializedData->myBool << std::endl;
    } 
    else 
    {
        std::cout << "Deserialization failed!" << std::endl;
    }

    return 0;
}