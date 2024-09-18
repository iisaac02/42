/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:55:44 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/05 10:25:47 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/contact.hpp"

void Contact::setFirstName(std::string first_name)
{
	_first_name = first_name;
}
void Contact::setLastName(std::string last_name)
{
	_last_name = last_name;
}
void Contact::setNickname(std::string nickname)
{
	_nickname = nickname;
}
void Contact::setPhoneNumber(std::string phone_number)
{
	_phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	_darkest_secret = darkest_secret;
}

std::string Contact::getFirstName()
{
	return _first_name;
}

std::string Contact::getLastName()
{
	return _last_name;
}

std::string Contact::getNickname()
{
	return _nickname;
}

std::string Contact::getPhoneNumber()
{
	return _phone_number;
}

std::string Contact::getDarkestSecret()
{
	return _darkest_secret;
}
