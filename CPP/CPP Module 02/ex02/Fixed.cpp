/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:10:10 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/10/02 10:13:26 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixed_point_value = 0;
}

Fixed::Fixed(const int num)
{
	_fixed_point_value = num << _fractional_bits;
}

Fixed::Fixed(const float num)
{
	_fixed_point_value = roundf(num * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &assign)
{
	if (this != &assign)
		_fixed_point_value = assign.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	return _fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	_fixed_point_value = raw;
}

float Fixed::toFloat() const
{
	return static_cast<float>(this->getRawBits()) / (1 << _fractional_bits);
}

int Fixed::toInt() const
{
	return _fixed_point_value >> _fractional_bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	return o << i.toFloat();
}

bool Fixed::operator>(const Fixed other) const
{
	return getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed other) const
{
	return getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed other) const
{
	return getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed other) const
{
	return getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed other) const
{
	return getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed other) const
{
	return getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	_fixed_point_value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_fixed_point_value += 1;
	return temp;
}

Fixed &Fixed::operator--()
{
	_fixed_point_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_fixed_point_value -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
	return x.getRawBits() < y.getRawBits() ? x : y;
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y)
{
	return x.getRawBits() < y.getRawBits() ? x : y;
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
	return x.getRawBits() > y.getRawBits() ? x : y;
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
	return x.getRawBits() > y.getRawBits() ? x : y;
}
