#include "Cursor.hpp"
#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Cursor::Cursor(int x, int y)
{	
	edges.reserve(3);
	this->baseColor = Color::GREEN;
	Point p1(x,y,Color::GREEN), p2(x+10,y+5,Color::GREEN), p3(x+5,y+10,Color::GREEN);
	edges.push_back(new Edge(p1, p2, 1.0f));
	edges.push_back(new Edge(p2, p3, 1.0f));
	edges.push_back(new Edge(p3, p1, 1.0f));
}

Cursor::~Cursor() {
	// now handled by the shapeFillable
}

const Point &Cursor::getPoint() const {
	return edges[0]->getPoint1();
}

void Cursor::setPoint(int x, int y) {
	edges[0]->setPoint1(x, y);
	edges[0]->setPoint2(x+20,y+10);
	edges[1]->setPoint1(x+20,y+10);
	edges[1]->setPoint2(x+10,y+20);
	edges[2]->setPoint1(x+10,y+20);
	edges[2]->setPoint2(x, y);
}


void Cursor::drawOutline() const {
	edges[0]->draw();
	edges[1]->draw();
	edges[2]->draw();
}

void Cursor::drawFill() const {
	
}
