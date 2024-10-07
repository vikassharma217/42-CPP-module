/* This class manages an array of Contact objects.
   It provides methods to add new contacts and search existing contacts.
   The class uses an array of size 8 to store up to 8 contacts. If a new contact
   is added after reaching the limit, it replaces the oldest contact.*/

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"


class PhoneBook 
{
    private:
        Contact contacts[8];
        int index;
        int totalContacts;

    public:
        PhoneBook();

    // Method (function in C) prototype
        void addContact();
        void searchContacts() const;
        std::string trim(const std::string& str) const;

    private:
    // util functions
        int stringToInt(const std::string& str) const;
        void displayContactBrief(int i) const;
        void displayContactFull(int idx) const;
        std::string truncateString(const std::string& str, size_t length) const;
        void addReplaceContact(const Contact& newContact);
        bool isAlpha(const std::string& str) const;
        bool isNumber(const std::string& str) const;
};

#endif
