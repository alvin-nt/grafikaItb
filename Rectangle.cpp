#include "Rectangle.hpp"

#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4, float weight)
	: p1(p1), p2(p2), p3(p3), p4(p4), weight(weight)
{
}

Rectangle::Rectangle(int x1, int y1, const Color& c1,
			int x2, int y2, const Color& c2,
			int x3, int y3, const Color& c3,
			int x4, int y4, const Color& c4, float weight)
	: p1(x1, y1, c1), p2(x2, y2, c2), p3(x3, y3, c3), p4(x4, y4, c4), weight(weight)
{
}

Rectangle::Rectangle(const Rectangle &Rectangle) {
	*this = Rectangle;
}

Rectangle::~Rectangle() {

}

Rectangle& Rectangle::operator=(const Rectangle &rhs) {
	if(this != &rhs) {
		p1 = rhs.p1;
		p2 = rhs.p2;
		p3 = rhs.p3;
		p4 = rhs.p4;
		weight = rhs.weight;
	}
	return *this;
}

bool Graphics::operator!=(const Rectangle &lhs, const Rectangle &rhs) {
	return !(lhs == rhs);
}

bool Graphics::operator==(const Rectangle &lhs, const Rectangle &rhs) {
	return (lhs.p1 == rhs.p1 &&
			lhs.p2 == rhs.p2 &&
			lhs.p3 == rhs.p3 &&
			lhs.p4 == rhs.p4 &&
			lhs.weight == rhs.weight);
}

const Point &Rectangle::getPoint1() const {
	return p1;
}

void Rectangle::setPoint1(const Point& p1) {
	this->p1 = p1;
}

const Point &Rectangle::getPoint2() const {
	return p2;
}

void Rectangle::setPoint2(const Point& p2) {
	this->p2 = p2;
}

const Point &Rectangle::getPoint3() const {
	return p3;
}

void Rectangle::setPoint3(const Point& p3) {
	this->p3 = p3;
}

const Point &Rectangle::getPoint4() const {
	return p4;
}

void Rectangle::setPoint4(const Point& p4) {
	this->p4 = p4;
}

float Rectangle::getWeight() const {
	return weight;
}

void Rectangle::setWeight(float weight) {
	this->weight = weight;
}

double Rectangle::getLength() const {
	return 0;
}

float Rectangle::getLengthFloat() const {
	return 0.0;
}

void Rectangle::rotate(int degree) {
	
}

void Rectangle::drawOutline() const {
	//panggil edge aja disini
	Edge drawer1(p1,p2);
	Edge drawer2(p2,p3);
	Edge drawer3(p3,p4);
	Edge drawer4(p4,p1);
	drawer1.draw();
	drawer2.draw();
	drawer3.draw();
	drawer4.draw();
	/*
	Rasterizer *raster = Screen::instance();
	
	// uses the xiaolin wu's algorithm
	// source: http://members.chello.at/~easyfilter/bresenham.html
	
	int dx = abs(getDeltaX()), signX = p1.getX() < p2.getX() ? 1 : -1;
	int dy = abs(getDeltaY()), signY = p1.getY() < p2.getY() ? 1 : -1;
	int err = dx - dy, err2;
	
	int x0 = p1.getX(), x1 = p2.getX();
	int y0 = p1.getY(), y1 = p2.getY();
	
	// check for flat line
	float ed = dx + dy == 0 ? 1 : getLengthFloat();
	
	for(auto weightDraw = ((weight+1) * 2); ;) {
		// initialization: draw the first pixel
		// NOTE: 255 is the 'intensity bit, a.k.a. the color in 256 palette
		// TODO: map the float to this bit
		raster->setPixel(x0, y0, 
						std::max(.0f, 255 *
									(abs(err - dx + dy)/ed - weightDraw + 1)));
									
		err2 = err;
		auto x2 = x0;
		int y2;
		
		if(err2 << 1 >= -dx) { // x steps
			for(err2 += dy, y2 = y0; 
				err2 < ed * weightDraw && (y1 != y2 || dx > dy);
				err2 += dx) 
			{
				raster->setPixel(x0, y2 += signY, 
								(Pixel)std::max(.0f, 255 * (abs(err2)/ed - weightDraw + 1)));
			}
			
			if(x0 == x1)
				break;
			
			err2 = err;
			err -= dy;
			x0 += signX;
		}
		
		if(err2 << 1 <= dy) {
			for(err2 = dx - err2;
				err2 < ed * weightDraw && (x1 != x2 || dx < dy);
				err2 += dy)
			{
				raster->setPixel(x2 += signX, y0, 
								(Pixel)std::max(.0f, 255 * (abs(err2)/ed - weightDraw + 1)));
			}
			
			if(y0 == y1)
				break;
			err += dx;
			y0 += signY;
		}
	}
	*/
}

void Rectangle::drawFill() const {
	//TBD

}

void Rectangle::move(int dx, int dy) {
	int resultX1 = p1.getX() + dx;
	int resultY1 = p1.getY() + dy;
	int resultX2 = p2.getX() + dx;
	int resultY2 = p2.getY() + dy;
	
	bool move =(resultX1 >= SCREEN_X_MIN && resultX1 <= SCREEN_X_MAX &&
				resultY1 >= SCREEN_Y_MIN && resultY1 <= SCREEN_Y_MAX &&
				resultX2 >= SCREEN_X_MIN && resultX2 <= SCREEN_X_MAX &&
				resultY2 >= SCREEN_Y_MIN && resultY2 <= SCREEN_Y_MAX);
	
	if(move) {
		p1.move(dx, dy);
		p2.move(dx, dy);
	}
}
