/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:40:12 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/30 10:46:50 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class   Brain
{
    private:
        std::string     ideas[100];
        unsigned int    size;
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();

        Brain&              operator=(const Brain& other);
        void                addIdea(std::string idea);
        const std::string&  getIdea(unsigned int i) const;
};