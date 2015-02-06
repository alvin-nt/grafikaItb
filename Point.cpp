#include "Point.hpp"

#include "Rasterizer.hpp"

using namespace Graphics;

Point::Point(int x, int y, const Color& color)
	: x(x), y(y), color(color)
{
}

Point::Point(const Point& point)
{
	*this = point;
}

bool Graphics::operator!=(const Point& p1, const Point& p2)
{
	return !(p1 == p2);
}

bool Graphics::operator==(const Point& p1, const Point& p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}
	
Point& Point::operator=(const Point& point)
{
	if(this != &point) {
		x = point.x;
		y = point.y;
		color = point.color;
	}
	
	return *this;
}

Point Graphics::operator+(const Point& p1, const Point& p2)
{
	return Point(p1.x + p2.x, p1.y + p2.y);
}

Point Graphics::operator-(const Point& p1, const Point& p2)
{
	return Point(p1.x - p2.x, p1.y - p2.y);
}

Point& Graphics::operator+=(Point& p1, const Point& p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	
	return p1;
}

Point& Graphics::operator-=(Point& p1, const Point& p2)
{
	p1.x -= p2.x;
	p1.y -= p2.y;
	
	return p1;
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

void Point::setColor(const Color& color) {
	this->color = color;
}

const Color& Point::getColor() const {
	return color;
}

void Point::draw() const {
	Rasterizer *raster = Screen::instance();
	
	raster->setPixel(x, y, color);
}

void Point::move(int dx, int dy) {
	x += dx;
	y += dy;
}
