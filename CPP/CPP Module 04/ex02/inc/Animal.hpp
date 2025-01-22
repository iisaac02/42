/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:35:05 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 12:02:11 by ide-la-f         ###   ########.fr       */
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
    public:
        virtual ~Animal();
        
        virtual Animal&     operator=(const Animal& other) = 0;
        const std::string&  getType() const;
        void                setType(const std::string& type);
        virtual void        makeSound() const = 0;
        virtual Brain       *getBrain() const = 0;
};