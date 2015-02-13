#include "ShapeFillable.hpp"

#include "Shape.hpp"

using namespace Graphics;

ShapeFillable::~ShapeFillable() {
}

void ShapeFillable::draw() const {
	draw(false);
}


void ShapeFillable::draw(bool fill) const {
	if(fill)
		drawFill();
	else
		drawOutline();
}

void ShapeFillable::drawFill() const {
	
}

void ShapeFillable::drawOutline() const {
	
}

