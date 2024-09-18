#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <string>
#include <cstdlib>

class PhoneBook
{
private:
	Contact _contacts[8];
	static int _index;

public:
	void addContact();
	void searchContact();
};

#endif