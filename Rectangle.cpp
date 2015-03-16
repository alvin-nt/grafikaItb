#include "Rectangle.hpp"

#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4, 
					float weight, const Color& baseColor)
	: weight(weight)
{	
	edges.reserve(4);
	this->baseColor = baseColor;
	// TODO: maybe some assertion here? to make sure that the quad really represents a true rectangle
	// i.e., point 1 and point 2 are vertically equal, point 2 and 3 are horizontally equal, etc.
	
	edges.push_back(new Edge(p1, p2, weight));
	edges.push_back(new Edge(p2, p3, weight));
	edges.push_back(new Edge(p3, p4, weight));
	edges.push_back(new Edge(p4, p1, weight));
	
	anchor = Point((p1.getX() + p2.getX()) >> 1, (p1.getY() + p2.getY()) >> 1);
}

Rectangle::Rectangle(int x1, int y1, const Color& c1,
			int x2, int y2, const Color& c2,
			int x3, int y3, const Color& c3,
			int x4, int y4, const Color& c4, float weight)
	: weight(weight)
{
	edges.reserve(4);
	baseColor = c1;
	Point p1(x1, y1, c1), p2(x2, y2, c2), p3(x3, y3, c3), p4(x4, y4, c4);
	
	edges.push_back(new Edge(p1, p2, weight));
	edges.push_back(new Edge(p2, p3, weight));
	edges.push_back(new Edge(p3, p4, weight));
	edges.push_back(new Edge(p4, p1, weight));
	
	anchor = Point((p1.getX() + p2.getX()) >> 1, (p1.getY() + p2.getY()) >> 1);
}

Rectangle::Rectangle(const Rectangle &rectangle) {
	edges.reserve(4);
	for (int i = 0; i < 4; i++) {
		edges.push_back(new Edge(Point(), Point()));
	}
	
	*this = rectangle;
}

Rectangle::~Rectangle() {
	// now handled by the shapeFillable
}

Rectangle& Rectangle::operator=(const Rectangle &rhs) {
	if(this != &rhs) {
		// call the parent class, to copy the value of the edges
		ShapeFillable::operator=(rhs);
		
		// assign other params
		baseColor = rhs.baseColor;
		weight = rhs.weight;
	}
	
	return *this;
}

bool Graphics::operator!=(const Rectangle &lhs, const Rectangle &rhs) {
	return !(lhs == rhs);
}

bool Graphics::operator==(const Rectangle &lhs, const Rectangle &rhs) {
	return (*(lhs.edges[0]) == *(rhs.edges[0]) &&
			*(lhs.edges[1]) == *(rhs.edges[1]) &&
			*(lhs.edges[2]) == *(rhs.edges[2]) &&
			*(lhs.edges[3]) == *(rhs.edges[3]) &&
			lhs.baseColor == rhs.baseColor &&
			lhs.weight == rhs.weight);
}

const Point &Rectangle::getPoint1() const {
	return edges[0]->getPoint1();
}

void Rectangle::setPoint1(const Point& p1) {
	edges[0]->setPoint1(p1);
	edges[3]->setPoint2(p1);
}

void Rectangle::setPoint1(int x, int y) {
	edges[0]->setPoint1(x, y);
	edges[3]->setPoint2(x, y);
}

const Point &Rectangle::getPoint2() const {
	return edges[1]->getPoint1();
}

void Rectangle::setPoint2(const Point& p2) {
	edges[0]->setPoint2(p2);
	edges[1]->setPoint1(p2);
}

void Rectangle::setPoint2(int x, int y) {
	edges[0]->setPoint2(x, y);
	edges[1]->setPoint1(x, y);
}

const Point &Rectangle::getPoint3() const {
	return edges[2]->getPoint1();
}

void Rectangle::setPoint3(const Point& p3) {
	edges[1]->setPoint2(p3);
	edges[2]->setPoint1(p3);
}

void Rectangle::setPoint3(int x, int y) {
	edges[1]->setPoint2(x, y);
	edges[2]->setPoint1(x, y);
}

const Point &Rectangle::getPoint4() const {
	return edges[3]->getPoint1();
}

void Rectangle::setPoint4(const Point& p4) {
	edges[2]->setPoint2(p4);
	edges[3]->setPoint1(p4);
}

void Rectangle::setPoint4(int x, int y) {
	edges[2]->setPoint2(x, y);
	edges[3]->setPoint1(x, y);
}

float Rectangle::getWeight() const {
	return weight;
}

void Rectangle::setWeight(float weight) {
	this->weight = weight;
}

double Rectangle::getLength() const {
	return (edges[0]->getLength() + edges[1]->getLength() + 
			edges[2]->getLength() + edges[3]->getLength());
}

float Rectangle::getLengthFloat() const {
	return (edges[0]->getLengthFloat() + edges[1]->getLengthFloat() + 
			edges[2]->getLengthFloat() + edges[3]->getLengthFloat());
}

=======
void Rectangle::drawOutline() const {
	edges[0]->draw();
	edges[1]->draw();
	edges[2]->draw();
	edges[3]->draw();
}

void Rectangle::drawFill() const {
	//TBD
	//SEMENTARA BUAT COLOR PICKER
	drawOutline();
	int x1 = edges[0]->getPoint1().getX();
	int x2 = edges[3]->getPoint1().getX();
	int y1 = edges[0]->getPoint1().getY();
	int y2 = edges[1]->getPoint1().getY();
	for(int i=y1;i<=y2;i++){
		Edge e1(x1,i,baseColor,x2,i,baseColor,1.f);
		e1.draw();
	}
}

Point Rectangle::getMidpoint() const {
	int x = (edges[0]->getPoint1().getX() + edges[1]->getPoint1().getX()) >> 1;
	int y = (edges[0]->getPoint1().getY() + edges[4]->getPoint1().getY()) >> 1;

	return Point(x, y);
}
