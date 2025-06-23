/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 15:59:24 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/23 22:27:31 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x_val, const float y_val) : _x(x_val), _y(y_val) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        // x and y are const, so we cannot assign them
        // This operator is intentionally left empty
    }
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const
{
    return _x;
}

Fixed Point::getY() const
{
    return _y;
}

std::ostream& operator<<(std::ostream& os, const Point& point) 
{
    os << "Point(" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")";
    return os;
}