/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 15:49:22 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/23 22:29:31 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed&				operator=(const Fixed& other);
		~Fixed();

		int					getRawBits() const;
		void				setRawBits(int const raw);
		float				toFloat() const;
		int					toInt() const;

		bool				operator>(const Fixed& other) const;
		bool				operator<(const Fixed& other) const;
		bool				operator>=(const Fixed& other) const;
		bool				operator<=(const Fixed& other) const;
		bool				operator==(const Fixed& other) const;
		bool				operator!=(const Fixed& other) const;

		Fixed				operator+(const Fixed& other) const;
		Fixed				operator-(const Fixed& other) const;
		Fixed				operator*(const Fixed& other) const;
		Fixed				operator/(const Fixed& other) const;

		Fixed&				operator++();
		Fixed&				operator--();
		Fixed				operator++(int);
		Fixed				operator--(int);

		static Fixed&		min(Fixed& a, Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
