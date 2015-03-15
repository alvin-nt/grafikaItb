
#include "Cruiser.hpp"

#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Cruiser::Cruiser(int x, int y) : xAwal(x), yAwal(y)
{
	/*body = new Rectangle(300, 600, Color::WHITE, //lower left point
									225, 550, Color::WHITE, //upper left point
									525, 550, Color::WHITE, //upper right point
									500, 600, Color::WHITE, //lower right point
									5.0f);*/
	body = new Rectangle(xAwal, yAwal, Color::WHITE, //lower left point
									xAwal-75, yAwal-50, Color::WHITE, //upper left point
									xAwal+225, yAwal-50, Color::WHITE, //upper right point
									xAwal+200, yAwal, Color::WHITE, //lower right point
									5.0f);
	turret = new Ellipse(xAwal+75,yAwal-50, Color::WHITE,1.0f,30.0f,5.0f,1.f);
	gun = new Edge(xAwal+75,yAwal-50, Color::WHITE,
						 xAwal+50,yAwal-75, Color::WHITE,
						 5.0f);
}

Cruiser::~Cruiser() {

}


void Cruiser::fire() {
	
}

void Cruiser::drawOutline() const {
	body->drawOutline();
	turret->drawOutline();
	gun->draw();
}

void Cruiser::drawFill() const {
	//TBD

}

void Cruiser::move(int dx, int dy) {
	//TBD
}
