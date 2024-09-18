/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:56:00 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/17 11:03:25 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

int PhoneBook::_index = 0;

std::string getInput(std::string message)
{
	std::string input;

	while (input.empty())
	{
		std::cout << message;
		if (!getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(0);
		}
	}
	return (input);
}

void displayTableField(std::string field)
{
	if (field.size() > 10)
		std::cout << std::setw(9) << std::right << field.substr(0, 9) << "." << '|';
	else
		std::cout << std::setw(10) << std::right << field << '|';
}

void PhoneBook::addContact()
{
	int i = 0;

	if (_index > 7)
	{
		while (i < 7)
		{
			_contacts[i] = _contacts[i + 1];
			i++;
		}
		_index -= 1;
	}
	_contacts[_index].setFirstName(getInput("\nFirst name: "));
	_contacts[_index].setLastName(getInput("Last name: "));
	_contacts[_index].setNickname(getInput("Nickname: "));
	_contacts[_index].setPhoneNumber(getInput("Phone number: "));
	_contacts[_index].setDarkestSecret(getInput("Darkest secret: "));
	PhoneBook::_index += 1;
}

void PhoneBook::searchContact()
{
	std::string search_index;
	std::stringstream ss;
	int index;

	if (PhoneBook::_index == 0)
	{
		std::cout << GREEN "\nAdd a contact first!" DF << std::endl;
		return;
	}
	std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl;
	int	currentIndex = 0;
	while (currentIndex < PhoneBook::_index)
	{
		std::cout << "|" << std::setw(10) << std::right << currentIndex << '|';
		displayTableField(_contacts[currentIndex].getFirstName());
		displayTableField(_contacts[currentIndex].getLastName());
		displayTableField(_contacts[currentIndex].getNickname());
		std::cout << std::endl;
		currentIndex++;
	}
	while (true)
	{
		search_index = getInput("Index to open: ");
		if (search_index.size() != 1 || !std::isdigit(search_index[0]))
		{
			std::cout << "Wrong input." << std::endl;
			continue;
		}
		ss << search_index;
		ss >> index;
		ss.clear();
		break;
	}
	if (index < 0 || index > PhoneBook::_index - 1)
		std::cout << "Input out of boundaries." << std::endl;
	else
	{
		std::cout << "\nFirst Name: " << _contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
	}
}