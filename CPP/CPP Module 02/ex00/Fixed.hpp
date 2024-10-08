/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:16:00 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/30 10:19:29 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int			_fixedPointValue;
		static const int	_fractionalBits = 0;
	public:
		Fixed();
		Fixed(const Fixed &rhs);
		Fixed& operator=(const Fixed &rhs);
		~Fixed();

	int     getRawBits(void) const;
	void    setRawBits(int const raw);
};

#endif