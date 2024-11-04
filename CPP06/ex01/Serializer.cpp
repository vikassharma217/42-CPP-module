#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>
#include <string>

/*default constructor , destructor requirments*/
Serializer::Serializer()
{
}
Serializer::Serializer(const Serializer &rhs)
{
	(void)rhs;
}
Serializer &Serializer::operator=(const Serializer &rhs)
{
	(void)rhs;
	return (*this);
}
Serializer::~Serializer()
{
}

/*Static serialize method to cast th pointer to an unsigned int type*/
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/*static desrialize method to cast the raw integer back to a pointer of txpe Data*/
Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}