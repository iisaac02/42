/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:06:47 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 12:18:05 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Default constructor of " << this->type << std::endl;
    this->brain = new Brain;
}

Cat::Cat(const Cat& other)
{
    this->type = other.type;
    std::cout << "Copy-Constructor of " << this->type << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat::~Cat()
{
    std::cout << this->type << " has been destroyed" << std::endl;
    delete this->brain;
}

Cat&     Cat::operator=(const Cat& other)
{
    this->type = other.type;
    *(this->brain) = *(other.brain);
    return *this;
}

Animal&		Cat::operator=(const Animal& other)
{
	const Cat	*pOther;

	pOther= dynamic_cast<const Cat *>(&other);
	if (pOther)
	{
		this->type = pOther->type;
		*this->brain = *pOther->brain;
	}

	return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "* Meow! *" << std::endl;
}

Brain*  Cat::getBrain() const
{
    return this->brain;
}