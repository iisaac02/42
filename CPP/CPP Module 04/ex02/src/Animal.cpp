/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:51:32 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 12:05:43 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::~Animal()
{
    std::cout << "Destructor of Animal" << std::endl;
}

const   std::string&    Animal::getType() const
{
    return this->type;
}

void    Animal::setType(const std::string& type)
{
    this->type = type;
}