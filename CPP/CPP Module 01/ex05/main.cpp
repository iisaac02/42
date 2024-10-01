/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:29:36 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/20 11:53:23 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    std::string input;
    Harl        harl;

    while (true)
    {
        std::cout << "Enter a level: ";
        if (!(std::cin >> input))
        {
            std::cout << std::endl;
            break;
        }
        harl.complain(input);
        if (input == "exit")
            break;
    }
    return (EXIT_SUCCESS);
}