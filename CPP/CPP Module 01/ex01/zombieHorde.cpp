/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:55:46 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/19 10:59:00 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string Name)
{
    Zombie  *ZombieArray;
    int i = 0;

    ZombieArray = new Zombie[N];
    while (i < N)
    {
        ZombieArray[i].SetName(Name);
        i++;
    }
    return ZombieArray;
}