//#include "Edge.hpp"
#include "Rectangle.hpp"
#include "Rasterizer.hpp"
#include "Toolbox.hpp"

using namespace Graphics;

Toolbox::Toolbox(){
	rect[0] = new Rectangle(1, 301, Color::WHITE,
			40, 301, Color::WHITE,
			40, 340, Color::WHITE,
			1, 340, Color::WHITE, 0.5f);
	rect[1] = new Rectangle(41, 301, Color::RED,
			80, 301, Color::RED,
			80, 340, Color::RED,
			41, 340, Color::RED, 0.5f);
	rect[2] = new Rectangle(1, 341, Color::BLUE,
			40, 341, Color::BLUE,
			40, 380, Color::BLUE,
			1, 380, Color::BLUE, 0.5f);
	rect[3] = new Rectangle(41, 341, Color::GREEN,
			80, 341, Color::GREEN,
			80, 380, Color::GREEN,
			41, 380, Color::GREEN, 0.5f);
}

Toolbox::~Toolbox(){
	delete rect[0];
	delete rect[1];
	delete rect[2];
	delete rect[3];
}

void Toolbox::drawOutline() const{
	rect[0]->drawOutline();
	rect[1]->drawOutline();
	rect[2]->drawOutline();
	rect[3]->drawOutline();
}

void Toolbox::drawFill() const{

}
