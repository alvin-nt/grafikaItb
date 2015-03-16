#include "Helicopter.hpp"

#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

double degtorad(int deg)
{
	return deg*3.1415926535898/180;
}

Helicopter::Helicopter(const Point& midpoint, int angle, const Color& baseColor, float weight, int size)
	: midpoint(midpoint),weight(weight),angle(angle),size(size)
{	
	edges.reserve(4);
	this->baseColor = Color::WHITE;
	
	Point p[12];
	p[0].setX(midpoint.getX()-50*size);
	p[0].setY(midpoint.getY()-25*size);
	p[1].setX(midpoint.getX()+50*size);
	p[1].setY(midpoint.getY()-25*size);
	p[2].setX(midpoint.getX()+50*size);
	p[2].setY(midpoint.getY()+25*size);
	p[3].setX(midpoint.getX()-50*size);
	p[3].setY(midpoint.getY()+25*size);
	body = new Rectangle(p[0],p[1],p[2],p[3],weight,this->baseColor);
	p[4].setX(midpoint.getX());
	p[4].setY(midpoint.getY()-25*size);
	p[5].setX(midpoint.getX());
	p[5].setY(midpoint.getY()-40*size);
	p[6].setX(midpoint.getX()+50*size);
	p[6].setY(midpoint.getY());
	p[7].setX(midpoint.getX()+100*size);
	p[7].setY(midpoint.getY());
	//baling-baling
	int x1 = midpoint.getX()+(floor(15*cos(degtorad(angle))))*size;
	int y1 = midpoint.getY()+(-40+floor(15*sin(degtorad(angle))))*size;
	int x2 = midpoint.getX()+(-floor(15*cos(degtorad(angle))))*size;
	int y2 = midpoint.getY()+(-40-floor(15*sin(degtorad(angle))))*size;
	p[8].setX(x1);
	p[8].setY(y1);
	p[9].setX(x2);
	p[9].setY(y2);
	x1 = midpoint.getX()+(100+floor(10*cos(degtorad(angle))))*size;
	y1 = midpoint.getY()+(floor(10*sin(degtorad(angle))))*size;
	x2 = midpoint.getX()+(100-floor(10*cos(degtorad(angle))))*size;
	y2 = midpoint.getY()+(-floor(10*sin(degtorad(angle))))*size;
	p[10].setX(x1);
	p[10].setY(y1);
	p[11].setX(x2);
	p[11].setY(y2);
	
	edges.push_back(new Edge(p[4], p[5], weight));
	edges.push_back(new Edge(p[6], p[7], weight));
	edges.push_back(new Edge(p[8], p[9], weight));
	edges.push_back(new Edge(p[10], p[11], weight));
}

Helicopter::Helicopter(const Helicopter &Helicopter) {
	for (int i = 0; i < 4; i++) {
		edges.push_back(new Edge(Point(), Point()));
	}
	
	*this = Helicopter;
}

Helicopter::~Helicopter() {
	delete body;
}

Helicopter& Helicopter::operator=(const Helicopter &rhs) {
	if(this != &rhs) {
		// call the parent class, to copy the value of the edges
		ShapeFillable::operator=(rhs);
		
		// assign other params
		baseColor = rhs.baseColor;
		weight = rhs.weight;
	}
	
	return *this;
}

bool Graphics::operator!=(const Helicopter &lhs, const Helicopter &rhs) {
	return !(lhs == rhs);
}

bool Graphics::operator==(const Helicopter &lhs, const Helicopter &rhs) {
	return (lhs.midpoint == rhs.midpoint &&
			lhs.baseColor == rhs.baseColor &&
			lhs.weight == rhs.weight);
}

void Helicopter::setMidpoint(const Point& p) {
	midpoint.setX(p.getX());
	midpoint.setY(p.getY());
}

float Helicopter::getWeight() const {
	return weight;
}

void Helicopter::setWeight(float weight) {
	this->weight = weight;
}

void Helicopter::drawOutline() const {
	for (int i = 0; i < 4; i++) 
		edges[i]->draw();
}

void Helicopter::drawFill() const {
	//TBD
}

Point Helicopter::getMidpoint() const {
	return midpoint;
}

void Helicopter::moveHelicopter(int dx, int dy){
	
	move(dx,dy);
	body->move(dx,dy);
	midpoint.move(dx,dy);
	angle = (angle + 5) % 360;
	int x1 = midpoint.getX()+(floor(15*cos(degtorad(angle))))*size;
	int y1 = midpoint.getY()+(-40+floor(15*sin(degtorad(angle))))*size;
	int x2 = midpoint.getX()+(-floor(15*cos(degtorad(angle))))*size;
	int y2 = midpoint.getY()+(-40-floor(15*sin(degtorad(angle))))*size;
	Point p[4];
	p[0].setX(x1);
	p[0].setY(y1);
	p[1].setX(x2);
	p[1].setY(y2);
	edges[2]->setPoint1(p[0]);
	edges[2]->setPoint2(p[1]);
	x1 = (midpoint.getX()+100+floor(10*cos(degtorad(angle))))*size;
	y1 = (midpoint.getY()+floor(10*sin(degtorad(angle))))*size;
	x2 = (midpoint.getX()+100-floor(10*cos(degtorad(angle))))*size;
	y2 = (midpoint.getY()-floor(10*sin(degtorad(angle))))*size;
	p[2].setX(x1);
	p[2].setY(y1);
	p[3].setX(x2);
	p[3].setY(y2);
	edges[3]->setPoint1(p[2]);
	edges[3]->setPoint2(p[3]);
}
