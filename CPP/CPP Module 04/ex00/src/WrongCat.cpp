/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:31:55 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/28 11:38:20 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default constructor of " << this->type << std::endl;
}

WrongCat::WrongCat(const WrongCat&) : WrongAnimal("WrongCat")
{
	std::cout << "Copy-Constructor of " << this->type << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->type << " has been destroyed" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "* WrongCat Meow *" << std::endl;
}
