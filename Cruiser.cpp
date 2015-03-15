
#include "Cruiser.hpp"

#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Cruiser::Cruiser(int x, int y) : xAwal(x), yAwal(y)
{
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

void Cruiser::move(int dx) {
	//TBD
	if (dx < 0) {
		if(body->getPoint2().getX() > Drawable::SCREEN_X_MIN) {
			body->move(dx, 0);
			turret->move(dx, 0);
			gun->move(dx, 0);
		}
	} else {
		if(body->getPoint3().getX() < Drawable::SCREEN_X_MAX) {
			body->move(dx, 0);
			turret->move(dx, 0);
			gun->move(dx, 0);
		}
	}
}

Point Cruiser::getLowerLeftPoint() {
	return body->getPoint1();
}
Point Cruiser::getUpperLeftPoint() {
	return body->getPoint2();	
}
Point Cruiser::getUpperRightPoint() {
	return body->getPoint3();	
}
Point Cruiser::getLowerRightPoint() {
	return body->getPoint4();	
}
