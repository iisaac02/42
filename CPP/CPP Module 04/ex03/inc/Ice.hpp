/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:00:25 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/11/07 11:01:56 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(Ice const &copy);
		~Ice();

		Ice const	&operator=(Ice const &copy);

		virtual AMateria	*clone() const;
		void				use(ICharacter &target);
};
