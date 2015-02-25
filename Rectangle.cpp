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
}

void Rectangle::drawFill() const {
	//TBD

}

void Rectangle::move(int dx, int dy) {
	int resultX1 = p1.getX() + dx;
	int resultY1 = p1.getY() + dy;
	int resultX2 = p2.getX() + dx;
	int resultY2 = p2.getY() + dy;
	int resultX3 = p3.getX() + dx;
	int resultY3 = p3.getY() + dy;
	int resultX4 = p4.getX() + dx;
	int resultY4 = p4.getY() + dy;
	
	bool move =(resultX1 >= SCREEN_X_MIN && resultX1 <= SCREEN_X_MAX &&
				resultY1 >= SCREEN_Y_MIN && resultY1 <= SCREEN_Y_MAX &&
				resultX2 >= SCREEN_X_MIN && resultX2 <= SCREEN_X_MAX &&
				resultY2 >= SCREEN_Y_MIN && resultY2 <= SCREEN_Y_MAX &&
				resultX3 >= SCREEN_X_MIN && resultX3 <= SCREEN_X_MAX &&
				resultY3 >= SCREEN_Y_MIN && resultY3 <= SCREEN_Y_MAX &&
				resultX4 >= SCREEN_X_MIN && resultX4 <= SCREEN_X_MAX &&
				resultY4 >= SCREEN_Y_MIN && resultY4 <= SCREEN_Y_MAX);
	
	if(move) {
		p1.move(dx, dy);
		p2.move(dx, dy);
		p3.move(dx, dy);
		p4.move(dx, dy);
	}
}

void Rectangle::scale(int scale) {
	//TBD
}
