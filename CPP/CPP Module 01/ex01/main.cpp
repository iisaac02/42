/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:52:33 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/19 10:55:21 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *Zombie1 = zombieHorde(5, "Zombiee");
    Zombie1[0].announce();
    Zombie1[1].announce();
    Zombie1[2].announce();
    Zombie1[3].announce();
    Zombie1[4].announce();

    delete[]    Zombie1;
}