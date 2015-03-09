#include "Rectangle.hpp"

#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4, float weight)
	: weight(weight)
{	
	e1 = new Edge(p1, p2, weight);
	e2 = new Edge(p2, p3, weight);
	e3 = new Edge(p3, p4, weight);
	e4 = new Edge(p4, p1, weight);
}

Rectangle::Rectangle(int x1, int y1, const Color& c1,
			int x2, int y2, const Color& c2,
			int x3, int y3, const Color& c3,
			int x4, int y4, const Color& c4, float weight)
	: weight(weight)
{
	Point p1(x1, y1, c1), p2(x2, y2, c2), p3(x3, y3, c3), p4(x4, y4, c4);
	
	e1 = new Edge(p1, p2, weight);
	e2 = new Edge(p2, p3, weight);
	e3 = new Edge(p3, p4, weight);
	e4 = new Edge(p4, p1, weight);
}

Rectangle::Rectangle(const Rectangle &rectangle) {
	*this = rectangle;
}

Rectangle::~Rectangle() {
	delete e1;
	delete e2;
	delete e3;
	delete e4;
}

Rectangle& Rectangle::operator=(const Rectangle &rhs) {
	if(this != &rhs) {
		*e1 = *(rhs.e1);
		*e2 = *(rhs.e2);
		*e3 = *(rhs.e3);
		*e4 = *(rhs.e4);
		
		weight = rhs.weight;
	}
	return *this;
}

bool Graphics::operator!=(const Rectangle &lhs, const Rectangle &rhs) {
	return !(lhs == rhs);
}

bool Graphics::operator==(const Rectangle &lhs, const Rectangle &rhs) {
	return (*(lhs.e1) == *(rhs.e1) &&
			*(lhs.e2) == *(rhs.e2) &&
			*(lhs.e3) == *(rhs.e3) &&
			*(lhs.e4) == *(rhs.e4) &&
			lhs.weight == rhs.weight);
}

const Point &Rectangle::getPoint1() const {
	return e1->getPoint1();
}

void Rectangle::setPoint1(const Point& p1) {
	e1->setPoint1(p1);
	e4->setPoint2(p1);
}

void Rectangle::setPoint1(int x, int y) {
	e1->setPoint1(x, y);
	e4->setPoint2(x, y);
}

const Point &Rectangle::getPoint2() const {
	return e2->getPoint1();
}

void Rectangle::setPoint2(const Point& p2) {
	e1->setPoint2(p2);
	e2->setPoint1(p2);
}

void Rectangle::setPoint2(int x, int y) {
	e1->setPoint2(x, y);
	e2->setPoint1(x, y);
}

const Point &Rectangle::getPoint3() const {
	return e3->getPoint1();
}

void Rectangle::setPoint3(const Point& p3) {
	e2->setPoint2(p3);
	e3->setPoint1(p3);
}

void Rectangle::setPoint3(int x, int y) {
	e2->setPoint2(x, y);
	e3->setPoint1(x, y);
}

const Point &Rectangle::getPoint4() const {
	return e4->getPoint1();
}

void Rectangle::setPoint4(const Point& p4) {
	e3->setPoint2(p4);
	e4->setPoint1(p4);
}

void Rectangle::setPoint4(int x, int y) {
	e3->setPoint2(x, y);
	e4->setPoint1(x, y);
}

float Rectangle::getWeight() const {
	return weight;
}

void Rectangle::setWeight(float weight) {
	this->weight = weight;
}

double Rectangle::getLength() const {
	return (e1->getLength() + e2->getLength() + e3->getLength() + e4->getLength());
}

float Rectangle::getLengthFloat() const {
	return (e1->getLengthFloat() + e2->getLengthFloat() + e3->getLengthFloat() + e4->getLengthFloat());
}

void Rectangle::rotate(int degree) {
	
}

void Rectangle::drawOutline() const {
	e1->draw();
	e2->draw();
	e3->draw();
	e4->draw();
}

void Rectangle::drawFill() const {
	//TBD

}

void Rectangle::move(int dx, int dy) {
	int resultX1 = e1->getPoint1().getX() + dx;
	int resultY1 = e1->getPoint1().getY() + dy;
	int resultX2 = e2->getPoint1().getX() + dx;
	int resultY2 = e2->getPoint1().getY() + dy;
	int resultX3 = e3->getPoint1().getX() + dx;
	int resultY3 = e3->getPoint1().getY() + dy;
	int resultX4 = e4->getPoint1().getX() + dx;
	int resultY4 = e4->getPoint1().getY() + dy;
	
	bool move =(resultX1 >= SCREEN_X_MIN && resultX1 <= SCREEN_X_MAX &&
				resultY1 >= SCREEN_Y_MIN && resultY1 <= SCREEN_Y_MAX &&
				resultX2 >= SCREEN_X_MIN && resultX2 <= SCREEN_X_MAX &&
				resultY2 >= SCREEN_Y_MIN && resultY2 <= SCREEN_Y_MAX &&
				resultX3 >= SCREEN_X_MIN && resultX3 <= SCREEN_X_MAX &&
				resultY3 >= SCREEN_Y_MIN && resultY3 <= SCREEN_Y_MAX &&
				resultX4 >= SCREEN_X_MIN && resultX4 <= SCREEN_X_MAX &&
				resultY4 >= SCREEN_Y_MIN && resultY4 <= SCREEN_Y_MAX);
	
	if(move) {
		e1->move(dx, dy);
		e2->move(dx, dy);
		e3->move(dx, dy);
		e4->move(dx, dy);
	}
}

void Rectangle::scale(int scale) {
	//TBD
}
