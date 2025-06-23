/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 12:28:15 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/23 22:30:33 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(1.0f, 1.0f);
    Point b(5.0f, 1.0f);
    Point c(3.0f, 4.0f);
    
    Point inside(3.0f, 2.0f);
    Point outside(1.0f, 4.0f);
	
    std::cout << "Triangle: " << a << ", " << b << ", " << c << std::endl;
    std::cout << "Point " << inside << " is inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point " << outside << " is inside: " << bsp(a, b, c, outside) << std::endl;
    
    return 0;
}
