/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:44:30 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/19 11:54:09 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack(void) const
{
    if (this->_weapon.getType() != "")
        std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
    else
        std::cout << _name << " doesn't have a weapon to attack." << std::endl;
}