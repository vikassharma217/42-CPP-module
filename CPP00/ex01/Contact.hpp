/* This class represents a single contact in the phonebook.
   It contains private members for storing contact details such as 
   first name, last name, nickname, phone number, and darkest secret. */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
    private:
    // Private data members to store contact information
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
    // Setters to assign values to the contact details
        void setFirstName(const std::string& fn);
        void setLastName(const std::string& ln);
        void setNickname(const std::string& nn);
        void setPhoneNumber(const std::string& pn);
        void setDarkestSecret(const std::string& ds);

    // Getters to retrieve the contact details
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif

