#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private:
    Contact contact[8];
public:
    void createContact(int i);
    void findContact(int index, int counter);
    void displayContact(int index);
};

#endif