/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:14:56 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/28 11:17:38 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	type;
		Animal(const std::string& type);
	public:
		Animal(void);
		Animal(const Animal& other);
		virtual ~Animal(void);

		Animal&				operator=(const Animal& other);
		const std::string&	getType() const;
		void				setType(const std::string& type);
		virtual void		makeSound() const;
};
