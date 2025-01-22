/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:00:30 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/11/07 11:01:25 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(Cure const &copy);
		~Cure();

		Cure const	&operator=(Cure const &copy);

		virtual AMateria	*clone() const;
		void				use(ICharacter &target);
};
