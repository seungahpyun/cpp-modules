/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 12:28:10 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/23 22:16:49 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	setRawBits(0);
}

Fixed::Fixed(const int value)
{
	_fixedPointValue = value * 256;
}

Fixed::Fixed(const float value)
{
	_fixedPointValue = roundf(value * 256);
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		setRawBits(other.getRawBits());
	}
	return (*this);
}

Fixed::~Fixed(){}

int Fixed::getRawBits() const
{
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_fixedPointValue) / 256.0f);
}

int Fixed::toInt() const
{
	return (_fixedPointValue / 256);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_fixedPointValue != other._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	this->_fixedPointValue++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	this->_fixedPointValue--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a,  const Fixed& b)
{
	return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	return (out << fixed.toFloat());
}
