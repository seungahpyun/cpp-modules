/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 15:59:20 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/23 22:31:20 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed crossProduct(const Point& a, const Point& b, const Point& p)
{
    Fixed ab_x = b.getX() - a.getX();
    Fixed ab_y = b.getY() - a.getY();
    Fixed ap_x = p.getX() - a.getX();
    Fixed ap_y = p.getY() - a.getY();
    
    return ab_x * ap_y - ab_y * ap_x;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = crossProduct(a, b, point);
    Fixed cross2 = crossProduct(b, c, point);
    Fixed cross3 = crossProduct(c, a, point);
    
    bool positive = cross1 > 0 && cross2 > 0 && cross3 > 0;
    bool negative = cross1 < 0 && cross2 < 0 && cross3 < 0;
    
    return positive || negative;
}