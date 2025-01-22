/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:00:51 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 12:15:27 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor of Brain" << std::endl;
    size = 0;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy Constructor of Brain" << std::endl;
    *this = other;
}

Brain::~Brain()
{
    std::cout << "Destructor of Brain" << std::endl;
}

Brain&      Brain::operator=(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    this->size = other.size;
    return *this;
}

const   std::string&        Brain::getIdea(unsigned int i) const
{
   return this->ideas[i];
}

void        Brain::addIdea(std::string idea)
{
    if (size == 100)
        return;
    this->ideas[size++] = idea;
}