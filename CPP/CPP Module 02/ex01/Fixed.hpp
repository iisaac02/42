/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:35:57 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/04 10:23:12 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &rhs);
		Fixed& operator=(const Fixed &rhs);
		~Fixed();

	int     getRawBits(void) const;
	void    setRawBits(int const raw);

	float   toFloat(void) const;
	int     toInt(void) const;

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif