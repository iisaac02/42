/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:14:18 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 12:19:27 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Default constructor of " << this->type << std::endl;
    this->brain = new Brain;
}

Dog::Dog(const Dog& other)
{
    this->type = other.type;
    std::cout << "Copy-Constructor of " << this->type << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog::~Dog()
{
    std::cout << this->type << " has been destroyed" << std::endl;
    delete this->brain;
}

Dog&     Dog::operator=(const Dog& other)
{
    this->type = other.type;
    *(this->brain) = *(other.brain);
    return *this;
}

Animal&     Dog::operator=(const Animal& other)
{
    const Dog   *p0ther;
    
    p0ther = dynamic_cast<const Dog*>(&other);
    if (p0ther)
    {
        this->type = p0ther->type;
        *this->brain = *p0ther->brain;
    }
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "* Barking! *" << std::endl;
}

Brain*  Dog::getBrain() const
{
    return this->brain;
}