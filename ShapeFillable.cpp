#include "ShapeFillable.hpp"

#include "Shape.hpp"
#include <stdexcept>

using namespace Graphics;

ShapeFillable::~ShapeFillable()
{
	for (auto edgePtr: edges) {
		delete edgePtr;
	}
}

ShapeFillable& ShapeFillable::operator= (const ShapeFillable& rhs) {
	if (this != &rhs) {
		this->baseColor = rhs.baseColor;
		
		// copy the value of each edge
		for (unsigned i = 0u; i < edges.size(); i++) {
			if (i < rhs.edges.size()) {
				*(edges[i]) = *(rhs.edges[i]);
			} else {
				throw std::runtime_error("edges<Edge*> length do not match!");;
			}
		}
	}
	
	return *this;
}

void ShapeFillable::draw() const {
	if(this->fill) {
		drawFill();
	} else {
		drawOutline();
	}
}


void ShapeFillable::draw(bool fill) {
	this->fill = fill;
	
	draw();
}

void ShapeFillable::setFill(bool fill) {
	this->fill = fill;
}
		
bool ShapeFillable::getFill() const {
	return fill;
}

void ShapeFillable::setFillColor(const Color& color) {
	baseColor = color;
}
		
const Color& ShapeFillable::getFillColor() const {
	return baseColor;
}

void ShapeFillable::move(int dx, int dy) {
	bool yes = true;
	
	for(auto i = 0u; i < edges.size() && yes; i++) {
		yes = Edge::isMovable(*(edges[i]), dx, dy);
	}
	
	if(yes) {
		for(auto edge: edges) {
			edge->move(dx, dy);
		}
	}
}

void ShapeFillable::rotate(float degree) {
	bool yes = true;
	
	for(auto i = 0u; i < edges.size() && yes; i++) {
		yes = Edge::isRotateable(*(edges[i]), degree);
	}
	
	if(yes) {
		for(auto edge: edges) {
			edge->rotate(degree);
		}
	}
}

void ShapeFillable::scale(float ds) {
	bool yes = true;
	
	for(auto i = 0u; i < edges.size() && yes; i++) {
		yes = Edge::isScaleable(*(edges[i]), ds, ds);
	}
	
	if(yes) {
		for(auto edge: edges) {
			edge->scale(ds);
		}
	}
}

void ShapeFillable::scale(float sx, float sy) {
	bool yes = true;
	
	for(auto i = 0u; i < edges.size() && yes; i++) {
		yes = Edge::isScaleable(*(edges[i]), sx, sy);
	}

	if(yes) {
		for(auto edge: edges) {
			edge->scale(sx, sy);
		}
	}
}

void ShapeFillable::drawOutline() const {
	
}

void ShapeFillable::drawFill() const {
	
}
