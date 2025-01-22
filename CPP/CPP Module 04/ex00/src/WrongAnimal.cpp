/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:31:49 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/28 11:38:16 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default Constructor of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type)
{
	std::cout << "Type constructor of WrongAnimal" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy-Constructor of WrongAnimal" << std::endl;
	*this = other; 
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal" << std::endl;
}

WrongAnimal&				WrongAnimal::operator=(const WrongAnimal& other)
{
	this->type = other.getType();

	return *this;
}

const std::string&	WrongAnimal::getType() const
{
	return this->type;
}

void				WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}

void				WrongAnimal::makeSound() const
{
	std::cout << "* WrongAnimal Sound!!! *" << std::endl;
}
                                                        
