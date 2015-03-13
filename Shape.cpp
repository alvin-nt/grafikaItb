#include "Shape.hpp"

using namespace Graphics;

Shape::~Shape() {
	
}

Shape& Shape::operator=(const Shape& rhs) {
	if(this != &rhs) {
		anchor = rhs.anchor;
	}
	
	return *this;
}
