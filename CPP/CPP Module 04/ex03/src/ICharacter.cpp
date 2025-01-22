/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:59:40 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/11/07 11:04:02 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "ICharacter object created with default constructor" << std::endl;
}

ICharacter::ICharacter(ICharacter const &copy)
{
	*this = copy;
	std::cout << "ICharacter object copied" << std::endl;
}

ICharacter const	&ICharacter::operator=(ICharacter const &copy)
{
	(void)copy;
	std::cout << "ICharacter Assignment Operator Called" << std::endl;
	return (*this);
}
