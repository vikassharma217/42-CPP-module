/* Implement the methods defined in PhoneBook.hpp.
   The addContact method will prompt the user to enter details for a new contact.
   The searchContacts method will display a list of saved contacts and allow the user
   to view details of a selected contact. */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>

// Constructor to initialize the PhoneBook
PhoneBook::PhoneBook() : index(0), totalContacts(0) 
{
}

std::string PhoneBook::trim(const std::string& str) const
{
    std::string trimmedString;

    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)
        return "";

    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    trimmedString = str.substr(first, (last - first + 1));
    return (trimmedString);
}

void PhoneBook::addReplaceContact(const Contact& newContact)
{
    contacts[index] = newContact;
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

bool PhoneBook::isAlpha(const std::string& str) const
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isalpha(str[i]))
            return (false);
    }
    return (true);
}

bool PhoneBook::isNumber(const std::string& str) const
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

// Method to add a new contact
void PhoneBook::addContact() 
{
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (!isAlpha(input) || input.empty())
    {
        std::cout<<"Should have alphabets only & cannot be empty." << std::endl;
        return;
    }
    newContact.setFirstName(input);
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (!isAlpha(input) || input.empty())
    {
        std::cout<<"Should have alphabets only & cannot be empty." << std::endl;
        return;
    }
    newContact.setLastName(input);
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Cannot be empty." << std::endl;
        return;
    }
    newContact.setNickname(input);
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    if (!isNumber(input) || input.empty())
    {
        std::cout << "Should be digits only & cannot be empty." << std::endl;
        return;
    }
    newContact.setPhoneNumber(input);
    
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Cannot be emty." << std::endl;
        return;
    }
    newContact.setDarkestSecret(input);
    
    addReplaceContact(newContact);
    std::cout << "Contact added successfully!" << std::endl;
}


// Helper function to convert a string to an integer
int PhoneBook::stringToInt(const std::string& str) const 
{
    std::istringstream iss(str);
    int num;
    if (!(iss >> num)) 
        return (-1);
    return (num);
}

// truncate a string if it's longer than the specified length
std::string PhoneBook::truncateString(const std::string& str, size_t length) const 
{
    std::string truncated = str;
    if (str.length() > length)
    {
        truncated = str.substr(0, length -1);
        truncated += ".";
    } 
    return (truncated);
}

// display a single contact's brief information
void PhoneBook::displayContactBrief(int i) const 
{
    std::cout << std::setw(10) << i << "|"
              << std::setw(10) << truncateString(contacts[i].getFirstName(), 10) << "|"
              << std::setw(10) << truncateString(contacts[i].getLastName(), 10) << "|"
              << std::setw(10) << truncateString(contacts[i].getNickname(), 10) << std::endl;
}

// display a single contact's full information
void PhoneBook::displayContactFull(int i) const 
{
    std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[i].getDarkestSecret() << std::endl;
}

// Method to search and display contacts
void PhoneBook::searchContacts() const 
{
    int contactIndex;
    if (totalContacts == 0) 
    {
        std::cout << "PhoneBook is empty."<< std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < totalContacts; i++) 
    {
        displayContactBrief(i);
    }
    std::cout << "Enter the index of the contact: ";
    std::string indexStr;
    std::getline(std::cin, indexStr);

    contactIndex = stringToInt(indexStr);
    if (contactIndex >= 0 && contactIndex < totalContacts) 
        displayContactFull(contactIndex);
    else 
        std::cout << "Invalid index!" << std::endl;
}