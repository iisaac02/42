/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:59:58 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/11/07 11:03:34 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(): _name("default"), _inventory()
{
	std::cout << "Character created with default constructor" << std::endl;
}

Character::Character(std::string const &name): _name(name), _inventory()
{
	std::cout << "Character created" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Character destroyed" << std::endl;
}

Character::Character(Character const &copy): ICharacter(copy), _inventory()
{
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i];
	}
	std::cout << "Character copied" << std::endl;
}

Character const	&Character::operator=(const Character &copy)
{
	this->_name = copy._name;
	return (*this);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m && this->_inventory[i] == NULL)
		{
			if (this->inInventory(m))
				this->_inventory[i] = m->clone();
			else
				this->_inventory[i] = m;
			std::cout << "Materia " << this->_inventory[i]->getType() << " equipped to " << this->_name << "'s inventory at index " << i << std::endl;
			return ;
		}
	}
	if (m)
		std::cout << "Cannot equip materia, " << this->_name << "'s inventory is full!" << std::endl;
	else
		std::cout << "Cannot equip invalid materia" << std::endl;
	if (!this->inInventory(m))
		delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		std::cout << "Unequipped " << this->_inventory[idx]->getType() << " from " << this->_name << "'s inventory at index " << idx << std::endl;
		this->_inventory[idx] = NULL;
	}
	else if (idx < 0 || idx >= 4)
		std::cout << "Cannot unequip materia, invalid index " << idx << std::endl;
	else
		std::cout << "Cannot unequip materia, index " << idx << " is empty!" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else if (idx < 0 || idx >= 4)
		std::cout << "Cannot use materia, invalid index " << idx << std::endl;
	else
		std::cout << "Cannot use materia, index " << idx << " is empty!" << std::endl;
}

int Character::inInventory(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == m)
			return (1);
	}
	return (0);
}

std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::setName(std::string const &name)
{
	this->_name = name;
}
