/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 15:49:22 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/23 09:28:50 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed& other);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
