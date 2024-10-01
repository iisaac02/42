/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedV2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:59:55 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/19 13:08:48 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDV2_HPP
#define SEDV2_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

class SedV2
{
	private:
		std::string _inFile;
		std::string _outFile;

	public:
		SedV2( std::string filename);
		~SedV2();

		void	replace( std::string s1, std::string s2);
};

#endif