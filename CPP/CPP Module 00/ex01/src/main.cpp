/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:55:52 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/17 12:50:26 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

int main()
{
	std::string option;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "\nType an option:\n\n➔ADD\n\n➔SEARCH\n\n➔EXIT\n"
			<< std::endl;
		std::cout << "Option: ";
		if (!getline(std::cin, option))
		{
			std::cout << std::endl;
			break;
		}
		if (option == "ADD" || option == "add")
		{
			phonebook.addContact();
			continue;
		}
		if (option == "SEARCH" || option == "search")
		{
			phonebook.searchContact();
			continue;
		}
		if (option == "EXIT" || option == "exit")
			break;
		if (std::cin.eof()) { std::cout << std::endl; return (1);}
		std::cout << RED "\nInvalid command" DF << std::endl;
	}
	return (0);
}
