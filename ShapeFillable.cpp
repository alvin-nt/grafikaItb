#include "ShapeFillable.hpp"

#include "Shape.hpp"

using namespace Graphics;

ShapeFillable::~ShapeFillable()
{
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

void ShapeFillable::drawFill() const {
	
}

void ShapeFillable::drawOutline() const {
	
}

