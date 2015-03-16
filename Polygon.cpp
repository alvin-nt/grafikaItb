#include "Polygon.hpp"
#include <iostream>

using namespace Graphics;

Polygon::Builder::Builder() 
	: mBaseColor(Color::WHITE), mWeight(1.0f)
{
	args.reserve(10);
}

Polygon::Builder::Builder(int nPoints) 
	: mBaseColor(Color::WHITE), mWeight(1.0f)
{
	args.reserve(nPoints);
}

Polygon::Builder::~Builder() 
{
	
}

Polygon::Builder& Polygon::Builder::point(const Point& p) {
	args.push_back(p);
	
	return *this;
}

Polygon::Builder& Polygon::Builder::point(int x, int y) {
	args.push_back(Point(x, y));
	
	return *this;
}

Polygon::Builder& Polygon::Builder::baseColor(const Color& color) {
	mBaseColor = color;
	
	return *this;
}

Polygon::Builder& Polygon::Builder::baseColor(Pixel pixel) {
	mBaseColor = Color::fromPixel(pixel);
	
	return *this;
}

Polygon::Builder& Polygon::Builder::weight(float weight) {
	mWeight = weight;
	
	return *this;
}

Polygon::Builder& Polygon::Builder::translate(int dx, int dy) {
	bool translate = true;
	
	int count = 0;
	for (auto it = args.begin(); it != args.end() && translate; it++) {
		translate = Point::isMovable(*it, dx, dy);
		std::cout << "[" << count++ << "] translateable? " << translate << std::endl;
	}
	
	if (translate) {
		for (auto point: args) {
			point.move(dx, dy);
		}
	}
	
	return *this;
}

Polygon Polygon::Builder::build() const {
	return Polygon(args, mBaseColor, mWeight);
}

Polygon* Polygon::Builder::buildNew() const {
	return new Polygon(args, mBaseColor, mWeight);
}

Polygon::Polygon(const std::vector<Point>& args) 
{
	int minX, maxX, minY, maxY;
	
	fill = false;
	baseColor = Color::WHITE;
	edges.reserve(args.size());
	
	minX = maxX = args[0].getX();
	minY = maxY = args[0].getY();
	
	for(auto i = 0u; i < args.size() - 1; i++) {
		edges.push_back(new Edge(args[i], args[i+1]));
		
		// check for min/max (x, y)
		int tempX = args[i + 1].getX();
		minX = tempX < minX ? tempX : minX;
		maxX = tempX > maxX ? tempX : maxX;
		
		int tempY = args[i + 1].getY();
		minY = tempY < minY ? tempY : minY;
		maxY = tempY > maxY ? tempY : maxY;
	}
	
	// check last edge, whether it was closed/open
	auto lastEdge = *(edges.end() - 1);
	auto beginEdge = *(edges.begin());
	
	if (beginEdge->getPoint1() != lastEdge->getPoint2()) {
		edges.push_back(new Edge(lastEdge->getPoint2(), beginEdge->getPoint1()));
	}
	
	// assign the anchor to the 'center' of the polygon
	anchor = Point((minX + maxX) >> 1, (minY + maxY) >> 1);
}

Polygon::Polygon(const std::vector<Point>& args, 
				const Color& baseColor,
				float weight)
	: weight(weight)
{
	fill = false;
	int minX, maxX, minY, maxY;
	
	edges.reserve(args.size());
	this->baseColor = baseColor;
	
	minX = maxX = args[0].getX();
	minY = maxY = args[0].getY();
	
	for(auto i = 0u; i < args.size() - 1; i++) {
		edges.push_back(new Edge(args[i], args[i + 1]));
		
		// check for min/max (x, y)
		int tempX = args[i + 1].getX();
		minX = tempX < minX ? tempX : minX;
		maxX = tempX > maxX ? tempX : maxX;
		
		int tempY = args[i + 1].getY();
		minY = tempY < minY ? tempY : minY;
		maxY = tempY > maxY ? tempY : maxY;
	}
	
	// check last edge, whether it was closed/open
	auto lastEdge = *(edges.end() - 1);
	auto beginEdge = *(edges.begin());
	
	if (beginEdge->getPoint1() != lastEdge->getPoint2()) {
		edges.push_back(new Edge(lastEdge->getPoint2(), beginEdge->getPoint1()));
	}
	
	// assign the anchor to the 'center' of the polygon
	anchor = Point((minX + maxX) >> 1, (minY + maxY) >> 1);
}

Polygon::Polygon(const Polygon& polygon) {
	baseColor = polygon.baseColor;
	weight = polygon.weight;
	edges.reserve(polygon.edges.size());
	
	for(auto i = 0u; i < polygon.edges.size(); i++) {
		edges.push_back(new Edge(*(polygon.edges[i])));
	}
	
	anchor = polygon.anchor;
}

Polygon::~Polygon() {
	
}

bool Polygon::operator==(const Polygon& rhs) const {
	bool ret = (this == &rhs);
	
	if(!ret) {
		ret = (edges.size() == rhs.edges.size() &&
				baseColor == rhs.baseColor &&
				weight == rhs.weight);
		
		if(ret) {
			for (auto i = 0u; i < edges.size() && ret; i++) {
				ret = (*(edges[i]) == *(rhs.edges[i]));
			}
		}
	} else {
		ret = true;
	}
	
	return ret;
}

std::ostream& Graphics::operator<<(std::ostream& out, const Polygon& poly) {
	out << "[Polygon]" << std::endl;

	for(unsigned i = 0u; i < poly.edges.size(); i++) {
		out << "((x, y), (x, y)): ((" 
			<< poly.edges[i]->getPoint1().getX() << ", " << poly.edges[i]->getPoint1().getY() << "), ("
			<< poly.edges[i]->getPoint2().getX() << ", " << poly.edges[i]->getPoint2().getY() << "))"
			<< std::endl;
	}
	
	return out;
}
