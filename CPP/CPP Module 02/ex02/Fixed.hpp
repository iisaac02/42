/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:10:05 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/02 09:58:15 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int _fixed_point_value;
		static const int _fractional_bits = 8;

	public:
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &copy);
	~Fixed();

	Fixed &operator=(const Fixed &assign);

	bool operator>(const Fixed operation) const;
	bool operator<(const Fixed operation) const;
	bool operator>=(const Fixed operation) const;
	bool operator<=(const Fixed operation) const;
	bool operator==(const Fixed operation) const;
	bool operator!=(const Fixed operation) const;

	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &x, Fixed &y);
	static const Fixed &min(const Fixed &x, const Fixed &y);
	static Fixed &max(Fixed &x, Fixed &y);
	static const Fixed &max(const Fixed &x, const Fixed &y);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif