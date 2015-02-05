#include "Point.hpp"

Point::Point(int x, int y)
	: x(x), y(y);
{
}

Point::Point(const Point& point)
{
	*this = point;
}

bool Point::operator==(const Point& p1, const Point& p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}
	
Point& Point::operator=(const Point& point)
{
	if(this != &point) {
		x = point.x;
		y = point.y;
	}
	
	return *this;
}

Point Point::operator+(const Point& p1, const Point& p2)
{
	return Point(p1.x + p2.x, p1.y + p2.y);
}

Point Point::operator-(const Point& p1, const Point& p2)
{
	return Point(p1.x - p2.x, p1.y - p2.y);
}

Point& Point::operator+=(const Point& point)
{
	this->x += point.x;
	this->y += point.y;
	
	return *this;
}

Point& Point::operator-=(const Point& point)
{
	this->x -= point.x;
	this->y -= point.y;
	
	return *this;
}

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

int Point::quadrant(const Point& point) {
	int ret;
	
	if(point.x == 0 || point.y == 0) {
		ret = -1;
	} else {
		if(point.x > 0 && point.y > 0)
			ret = 1;
		else if(point.x > 0 && point.y < 0)
			ret = 2;
		else if(point.x < 0 && point.y < 0)
			ret = 3;
		else if(point.x < 0 && point.y > 0)
			ret = 4;
	}
	
	return ret;
}
