/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:06:47 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 11:41:03 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat()  :   Animal("Cat")
{
    std::cout << "Default constructor of " << this->type << std::endl;
    this->brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal("Cat")
{
    std::cout << "Copy-Constructor of " << this->type << std::endl;
    *this = other;
}

Cat::~Cat()
{
    std::cout << this->type << " has been destroyed" << std::endl;
    delete this->brain;
}

Animal&     Cat::operator=(const Animal& other)
{
    const Cat   *p0ther;
    
    p0ther = dynamic_cast<const Cat *>(&other);
    if (p0ther)
    {
        this->type = p0ther->type;
        *this->brain = *p0ther->brain;
    }
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "* Meow! *" << std::endl;
}

Brain*  Cat::getBrain() const
{
    return this->brain;
}