#include "TemporaryDrawable.hpp"

using namepsace Graphics;

int TemporaryDrawable::getDrawSteps() const {
	return drawSteps;
}

void TemporaryDrawable::setDrawSteps(int steps) {
	drawSteps = steps
}

bool TemporaryDrawable::isExpired() const {
	return drawSteps <= 0;
}
