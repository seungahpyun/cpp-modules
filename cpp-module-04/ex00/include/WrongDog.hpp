/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongDog.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 09:04:56 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 09:10:46 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(const WrongDog& other);
		WrongDog& operator=(const WrongDog& other);
		virtual ~WrongDog();

		void makeSound() const override;
};

std::ostream& operator<<(std::ostream& os, const WrongDog& wrongDog);

#endif
