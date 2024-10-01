/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:53:55 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/19 12:57:09 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedV2.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./SedV2 <filename> <to_find> <replace>." << std::endl;
        return (EXIT_FAILURE);
    }
    else
    {
        SedV2   sed2(argv[1]);
        sed2.replace(argv[2], argv[3]);
    }
    return (EXIT_SUCCESS);
}