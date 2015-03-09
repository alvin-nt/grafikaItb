
#include "Cube.hpp"

#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Cube::Cube(const Point& p,int s)
	: p1(p),p2(p),p3(p),p4(p),p5(p),p6(p),p7(p),p8(p)
{
	length = s;
	pov = 2;
	p2.setX(p.getX()+s);
	p3.setX(p.getX()+s);
	p3.setY(p.getY()-s/2);
	p4.setY(p.getY()-s/2);
	p5.setY(p.getY()-s);
	p6.setX(p.getX()+s);
	p6.setY(p.getY()-s);
	p7.setX(p.getX()+s);
	p7.setY(p.getY()-3*s/2);
	p8.setY(p.getY()-3*s/2);
}

Cube::~Cube() {

}


void Cube::rotate(int degree) {
	
}

void Cube::drawOutline() const {
	if(pov==1){
		Rectangle *sisi1 = new Rectangle(p1,p2,p6,p5);
		Rectangle *sisi2 = new Rectangle(p5,p6,p7,p8);
		Rectangle *sisi3 = new Rectangle(p4,p1,p5,p8);
		sisi1->drawOutline();
		sisi2->drawOutline();
		sisi3->drawOutline();
	} else if(pov==2){
		Rectangle *sisi1 = new Rectangle(p1,p2,p6,p5);
		sisi1->drawOutline();
	} else if(pov==3){
		Rectangle *sisi1 = new Rectangle(p1,p2,p6,p5);
		Rectangle *sisi2 = new Rectangle(p5,p6,p7,p8);
		Rectangle *sisi3 = new Rectangle(p2,p3,p7,p6);
		sisi1->drawOutline();
		sisi2->drawOutline();
		sisi3->drawOutline();
	}
}

void Cube::drawFill() const {
	//TBD

}

void Cube::move(int dx, int dy) {
	//TBD
}


int Cube::getLength(){
	return length;
}

void Cube::setLength(int newLength){
	length = newLength;
}

int Cube::getPov(){
	return pov;
}

void Cube::setPov(int newPov){
	if(newPov!=pov){
		if(newPov==1){
			pov = newPov;
			p3.setX(p1.getX()+length/2);
			p4.setX(p1.getX()-length/2);
			p7.setX(p1.getX()+length/2);
			p8.setX(p1.getX()-length/2);
		}else if(newPov==2){
			pov = newPov;
			p3.setX(p1.getX()+length);
			p4.setX(p1.getX());
			p7.setX(p1.getX()+length);
			p8.setX(p1.getX());
		}else if(newPov==3){
			pov = newPov;
			p3.setX(p1.getX()+3*length/2);
			p4.setX(p1.getX()+length/2);
			p7.setX(p1.getX()+3*length/2);
			p8.setX(p1.getX()+length/2);
		}
	}
}
