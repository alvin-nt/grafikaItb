#include "Edge.hpp"

#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Edge::Edge(const Point &p1, const Point &p2, float weight)
	: p1(p1), p2(p2), weight(weight)
{
}

Edge::Edge(int x1, int y1, const Color& c1,
			int x2, int y2, const Color& c2, float weight)
	: p1(x1, y1, c1), p2(x2, y2, c2), weight(weight)
{
}

Edge::Edge(const Edge &edge) {
	*this = edge;
}

Edge::~Edge() {
	
}

Edge& Edge::operator=(const Edge &rhs) {
	p1 = rhs.p1;
	p2 = rhs.p2;
	weight = rhs.weight;
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

const Point &Edge::getPoint2() const {
	return p2;
}

void Edge::setPoint2(const Point& p2) {
	this->p2 = p2;
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
	// stub
	return Point();
}

void Edge::draw() const {
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
}

void Edge::move(int dx, int dy) {
	p1.move(dx, dy);
	p2.move(dx, dy);
}
