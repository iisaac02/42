/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:31:32 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/28 11:37:55 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
        std::cout << "Default constructor of " << this->type << std::endl;
}

Cat::Cat(const Cat&) : Animal("Cat")
{
        std::cout << "Copy-Constructor of " << this->type << std::endl;
}

Cat::~Cat()
{
        std::cout << this->type << " has been destroyed" << std::endl;
}

void    Cat::makeSound() const
{
        std::cout << "* Meow! *" << std::endl;
}

