/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:31:28 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/28 11:37:50 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Constructor of Animal" << std::endl;
}

Animal::Animal(const std::string& type)
{
	std::cout << "Type constructor of Animal" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy-Constructor of Animal" << std::endl;
	*this = other; 
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal" << std::endl;
}

Animal&				Animal::operator=(const Animal& other)
{
	this->type = other.getType();

	return *this;
}

const std::string&	Animal::getType() const
{
	return this->type;
}

void				Animal::setType(const std::string& type)
{
	this->type = type;
}

void				Animal::makeSound() const
{
	std::cout << "* Animal Sound!!! *" << std::endl;
}
