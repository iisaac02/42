/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:51:25 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/16 13:04:06 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    
    std::cout << "| FragTrap | - " << this->_name << " constructed." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "| FragTrap | - " << this->_name << " destructed." << std::endl;
}

void    FragTrap::highFiveGuys()
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "| FragTrap | - " << this->_name << " is out of energy" << std::endl;
        return ;
    }
    std::cout << "| FragTrap | - " << this->_name << " high fives everybody" << std::endl;
    this->_energyPoints -= 1;
}