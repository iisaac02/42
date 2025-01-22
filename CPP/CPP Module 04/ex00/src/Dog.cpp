/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:31:38 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/28 11:37:59 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default constructor of " << this->type << std::endl;
}

Dog::Dog(const Dog&) : Animal("Dog")
{
	std::cout << "Copy-Constructor of " << this->type << std::endl;
}

Dog::~Dog()
{
	std::cout << this->type << " has been destroyed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "* Barking! *" << std::endl;
}
