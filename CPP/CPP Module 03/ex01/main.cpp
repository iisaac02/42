/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:49:59 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/10 11:39:27 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap ash("Ash");
    ScavTrap ash2(ash);

    ash.attack("the air");
    ash.takeDamage(10);
    ash.beRepaired(10);
    ash.guardGate();

    return EXIT_SUCCESS;
}