/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:00:20 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/11/07 11:02:14 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class ICharacter
{
	protected:
		ICharacter();
		ICharacter(ICharacter const &copy);

		ICharacter const	&operator=(ICharacter const &copy);
	public:
		virtual	~ICharacter() {}

		virtual std::string const	&getName() const = 0;

		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};
