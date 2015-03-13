#include "Point.hpp"

#include "Rasterizer.hpp"
#include <cmath>

using namespace Graphics;

Point::Point(int x, int y, const Color& color)
	: x(x), y(y), color(color)
{
}

Point::Point(const Point& point)
{
	*this = point;
}

Point::~Point() {
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

bool Graphics::operator!=(const Point& p1, const Point& p2)
{
	return !(p1 == p2);
}

bool Graphics::operator==(const Point& p1, const Point& p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
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
	if(isMovable(*this, dx, dy)) {
		move(*this, dx, dy);
	}
}

void Point::rotate(const Point& base, float degree) {
	if(isRotateable(base, *this, degree)) {
		rotate(base, *this, degree);
	}
}
		
void Point::scale(const Point& base, float ds) {
	if(isScaleable(base, *this, ds, ds)) {
		scale(base, *this, ds, ds);
	}
}

void Point::scale(const Point& base, float sx, float sy) {
	if(isScaleable(base, *this, sx, sy)) {
		scale(base, *this, sx, sy);
	}
}

void Point::move(Point& point, int dx, int dy) {
	point.x += dx;
	point.y += dy;
}

void Point::rotate(const Point& base, Point& target, float degree) {
	// move by base	
	target.x -= base.x;
	target.y -= base.y;
	
	// calculate cos and sin
	float dCos = cosf(degree);
	float dSin = sinf(degree);
	
	// rotate
	target.x = (int)(((float)target.x * dCos) - ((float)target.y * dSin));
	target.y = (int)(((float)target.x * dSin) + ((float)target.y * dCos));
	
	// unmove by base
	target.x += base.x;
	target.y += base.y;
}
		
void Point::scale(const Point& base, Point& target, float sx, float sy) {
	// move by base
	target.x -= base.x;
	target.y -= base.y;
	
	// calculate the new point
	target.x *= sx;
	target.y *= sy;
	
	// unmove by base
	target.x += base.x;
	target.y += base.y;
}

bool Point::isMovable(const Point& point, int dx, int dy) {
	Point resPoint = point;
	move(resPoint, dx, dy);
	
	return (resPoint.x >= SCREEN_X_MIN && resPoint.x <= SCREEN_X_MAX &&
			resPoint.y >= SCREEN_Y_MIN && resPoint.y <= SCREEN_Y_MAX);
}
		
bool Point::isRotateable(const Point& base, const Point& target, float degree) {
	Point resPoint = target;
	rotate(base, resPoint, degree);
	
	return (resPoint.x >= SCREEN_X_MIN && resPoint.x <= SCREEN_X_MAX &&
			resPoint.y >= SCREEN_Y_MIN && resPoint.y <= SCREEN_Y_MAX);
}
		
bool Point::isScaleable(const Point& base, const Point& target, float sx, float sy) {
	Point resPoint = target;
	scale(base, resPoint, sx, sy);
	
	return (resPoint.x >= SCREEN_X_MIN && resPoint.x <= SCREEN_X_MAX &&
			resPoint.y >= SCREEN_Y_MIN && resPoint.y <= SCREEN_Y_MAX);
}
