/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:35:05 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 10:39:29 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class   Animal
{
    protected:
        std::string type;
        Animal(const std::string& type);
    public:
        Animal();
        Animal(const Animal& other);
        virtual ~Animal();
        
        virtual Animal&     operator=(const Animal& other);
        const std::string&  getType() const;
        void                setType(const std::string& type);
        virtual void        makeSound() const;
        virtual Brain       *getBrain() const = 0;
};