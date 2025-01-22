/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:00:15 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/11/07 11:02:47 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	protected:
		IMateriaSource();
		IMateriaSource(IMateriaSource const &copy);

		IMateriaSource const	&operator=(IMateriaSource const &copy);
	public:
		virtual ~IMateriaSource() {}

		virtual void		learnMateria(AMateria *materia) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};
