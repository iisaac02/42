/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:14:18 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 11:57:30 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()  :   Animal("Dog")
{
    std::cout << "Default constructor of " << this->type << std::endl;
    this->brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal("Dog")
{
    std::cout << "Copy-Constructor of " << this->type << std::endl;
    *this = other;
}

Dog::~Dog()
{
    std::cout << this->type << " has been destroyed" << std::endl;
    delete this->brain;
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