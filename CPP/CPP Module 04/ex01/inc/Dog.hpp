/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:47:04 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 10:51:07 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain   *brain;
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();
        
        Animal&     operator=(const Animal& other);
        void        makeSound() const;
        Brain       *getBrain() const;
};