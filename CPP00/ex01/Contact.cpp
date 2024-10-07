/* Implement the setter and getter methods defined in Contact.hpp.
   Each setter assigns a value to the corresponding private member variable.
   Each getter returns the value of the corresponding private member variable. */

#include "Contact.hpp"

// Setters
void Contact::setFirstName(const std::string& fn) 
{
    firstName = fn;
}
void Contact::setLastName(const std::string& ln) 
{
    lastName = ln;
}
void Contact::setNickname(const std::string& nn) 
{
    nickName = nn;
}
void Contact::setPhoneNumber(const std::string& pn) 
{
    phoneNumber = pn;
}
void Contact::setDarkestSecret(const std::string& ds) 
{
    darkestSecret = ds;
}

// Getters
std::string Contact::getFirstName() const 
{
    return (firstName);
}

std::string Contact::getLastName() const 
{
    return (lastName);
}

std::string Contact::getNickname() const 
{
    return (nickName);
}

std::string Contact::getPhoneNumber() const 
{
    return (phoneNumber);
}

std::string Contact::getDarkestSecret() const 
{
    return (darkestSecret);
}