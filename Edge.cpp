#include "Edge.hpp"

#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Edge::Edge()
	: p1(0, 0), p2(0, 0), anchor(getMidpoint()), color(p1.getColor())
{

}

Edge::Edge(const Point &p1, const Point &p2, float weight)
	: p1(p1), p2(p2), anchor(getMidpoint()), weight(weight), color(p1.getColor())
{
	
}

Edge::Edge(int x1, int y1, const Color& c1,
			int x2, int y2, const Color& c2, float weight)
	: p1(x1, y1, c1), p2(x2, y2, c2), anchor(getMidpoint()), 
		weight(weight), color(c1)
{
	
}

Edge::Edge(const Edge &edge) {
	*this = edge;
}

Edge::~Edge() {

}

Edge& Edge::operator=(const Edge &rhs) {
	if(this != &rhs) {
		Shape::operator=(rhs);
		
		p1 = rhs.p1;
		p2 = rhs.p2;
		weight = rhs.weight;
	}
	
	return *this;
}

bool Graphics::operator!=(const Edge &lhs, const Edge &rhs) {
	return !(lhs == rhs);
}

bool Graphics::operator==(const Edge &lhs, const Edge &rhs) {
	return (lhs.p1 == rhs.p1 &&
			lhs.p2 == rhs.p2 &&
			lhs.weight == rhs.weight);
}

const Point &Edge::getPoint1() const {
	return p1;
}

void Edge::setPoint1(const Point& p1) {
	this->p1 = p1;
}

void Edge::setPoint1(int x, int y) {
	p1.setX(x);
	p1.setY(y);
}

const Point &Edge::getPoint2() const {
	return p2;
}

void Edge::setPoint2(const Point& p2) {
	this->p2 = p2;
}

void Edge::setPoint2(int x, int y) {
	p2.setX(x);
	p2.setY(y);
}

void Edge::setPoint(const Point& p1,const Point& p2, float weight) {
	this->p1 = p1;
	this->p2 = p2;
	this->weight = weight;
}

int Edge::getDeltaX() const {
	return p2.getX() - p1.getX();
}

int Edge::getDeltaY() const {
	return p2.getY() - p1.getY();
}

float Edge::getWeight() const {
	return weight;
}

void Edge::setWeight(float weight) {
	this->weight = weight;
}

double Edge::getGradient() const {
	return (double)getDeltaY() / (double)getDeltaX();
}

double Edge::getLength() const {
	int deltaX = getDeltaX();
	int deltaY = getDeltaY();
	
	return sqrt((double)(deltaX * deltaX) + (double)(deltaY * deltaY));
}

float Edge::getLengthFloat() const {
	int deltaX = getDeltaX();
	int deltaY = getDeltaY();
	
	return sqrtf((float)(deltaX * deltaX) + (float)(deltaY * deltaY));
}

void Edge::swapPoints() {
	Point temp = p2;
	p2 = p1;
	p1 = temp;
}

Point Edge::getMidpoint() const {
	return Point((p1.getX() + p2.getX()) >> 1, (p1.getY() + p2.getY()) >> 1);
}

void Edge::draw() const {
	Rasterizer *raster = Screen::instance();
	
	int dx = abs(getDeltaX()), signX = p1.getX() < p2.getX() ? 1 : -1;
	int dy = abs(getDeltaY()), signY = p1.getY() < p2.getY() ? 1 : -1;
	int err = dx - dy, err2;
	
	int x0 = p1.getX(), x1 = p2.getX();
	int y0 = p1.getY(), y1 = p2.getY();
	
	Pixel basePixel = p1.getColor().toPixel();
	
	// check for flat line
	float ed = dx + dy == 0 ? 1 : getLengthFloat();
	
	for(auto weightDraw = ((weight+1)); ;) {
		// draw initial point
		byte alpha = (byte)roundf(std::max(.0f, BYTE_MAX * (abs(err - dx + dy)/ed - weightDraw + 1)));
		Pixel drPixel = basePixel | (alpha << raster->getVarInfo().transp.offset);
		
		raster->setPixel(x0, y0, drPixel);
									
		err2 = err;
		auto x2 = x0;
		int y2;
		
		if(err2 << 1 >= -dx) { // x steps
			for(err2 += dy, y2 = y0; 
				err2 < ed * weightDraw && (y1 != y2 || dx > dy);
				err2 += dx) 
			{
				byte alpha = (byte)roundf(std::max(.0f, BYTE_MAX * (abs(err2)/ed - weightDraw + 1)));
				Pixel drPixel = basePixel | (alpha << raster->getVarInfo().transp.offset);
				
				raster->setPixel(x0, y2 += signY, drPixel);
			}
			
			if(x0 == x1)
				break;
			
			err2 = err;
			err -= dy;
			x0 += signX;
		}
		
		if(err2 << 1 <= dy) { // y steps
			for(err2 = dx - err2;
				err2 < ed * weightDraw && (x1 != x2 || dx < dy);
				err2 += dy)
			{
				byte alpha = (byte)roundf(std::max(.0f, BYTE_MAX * (abs(err2)/ed - weightDraw + 1)));
				Pixel drPixel = basePixel | (alpha << raster->getVarInfo().transp.offset);
				
				raster->setPixel(x2 += signX, y0, drPixel);
			}
			
			if(y0 == y1)
				break;
			err += dx;
			y0 += signY;
		}
	}
}

void Edge::rotate(float degree) {
	if (isRotateable(*this, degree))
	{		
		Point::rotate(anchor, p1, degree);
		Point::rotate(anchor, p2, degree);
	}
}

void Edge::scale(float ds) {
	if(isScaleable(*this, ds, ds)) {
		Point::scale(anchor, p1, ds, ds);
		Point::scale(anchor, p2, ds, ds);
	}
}

void Edge::scale(float sx, float sy) {
	if(isScaleable(*this, sx, sy)) {
		Point::scale(anchor, p1, sx, sy);
		Point::scale(anchor, p2, sx, sy);
	}
}

void Edge::move(int dx, int dy) {
	if (isMovable(*this, dx, dy)) {
		Point::move(anchor, dx, dy);
		Point::move(p1, dx, dy);
		Point::move(p2, dx, dy);
	}
}

bool Edge::isMovable(const Edge& edge, int dx, int dy) {
	return (Point::isMovable(edge.anchor, dx, dy) &&
			Point::isMovable(edge.p1, dx, dy) &&
			Point::isMovable(edge.p2, dx, dy));
}
	
bool Edge::isScaleable(const Edge& edge, float sx, float sy) {
	return (Point::isScaleable(edge.anchor, edge.p1, sx, sy) &&
			Point::isScaleable(edge.anchor, edge.p2, sx, sy));
}
	
bool Edge::isRotateable(const Edge& edge, float degree) {
	return (Point::isRotateable(edge.anchor, edge.p1, degree) &&
			Point::isRotateable(edge.anchor, edge.p2, degree));
}
