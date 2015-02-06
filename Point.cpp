#include "Point.hpp"

#include "Rasterizer.hpp"

using namespace Graphics;

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

const Color &Point::getColor() {
	return color;
}

void Point::setColor(const Color& color) {
	this->color = color;
}

const Color& getColor() const {
	return color;
}

void Point::draw() const {
	Rasterizer *raster = Screen::instance();
	
	if(raster->getVarInfo().bytes_per_pixel == 32) {
		byte *ptrFramebuffer = raster->getFramebuffer();
		long location = raster->getLocation(x, y);
		
		Pixel pixel = color.toPixel();
		
		((Pixel*)ptrFrameBuffer)[location] = pixel;
	} else {
		// do something for other color mode
	}
}

void Point::move(int dx, int dy) {
	x += dx;
	y += dy;
}
