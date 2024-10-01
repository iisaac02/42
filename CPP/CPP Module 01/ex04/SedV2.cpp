/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedV2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:58:24 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/19 13:08:27 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedV2.hpp"

SedV2::SedV2(std::string filename) : _inFile(filename)
{
    this->_outFile = this->_inFile + ".replace";
}

SedV2::~SedV2 (void)
{
}

void SedV2::replace(std::string toFind, std::string replace)
{
    std::ifstream ifs(this->_inFile.c_str());
    if (ifs.is_open())
    {
        std::string content;
        if (std::getline(ifs, content, '\0'))
        {
            std::ofstream ofs(this->_outFile.c_str());
            if (!ofs)
            {
                std::cerr << "Unable to open the output file." << std::endl;
                return;
            }
            size_t pos = content.find(toFind);
            while (pos != std::string::npos)
            {
                content.erase(pos, toFind.length());
                content.insert(pos, replace);
                pos = content.find(toFind);
            }
            ofs << content;
        }
        else
            std::cerr << "Empty file found." << std::endl;
        ifs.close();
    }
    else
    {
        std::cerr << "Unable to open the input file." << std::endl;
        exit(EXIT_FAILURE);
    }
}
