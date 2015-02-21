#include "Square.hpp"
#include "Rasterizer.hpp"
#include <cmath>
#include <algorithm>

using namespace Graphics;

	Square::Square(const Point& P1, int Length, float tetha): p1(P1), length(Length), tetha(tetha){
		p2 = Point((P1.getX() + roundf(Length*cos(tetha))), (P1.getY() + roundf(Length*sin(tetha))), P1.getColor());
		p3 = Point(P1.getX() + roundf(Length*cos(tetha+45)), (P1.getY() + roundf(Length*sin(tetha+45))), P1.getColor());
		p4 = Point(P1.getX() + roundf(Length*cos(tetha+90)), (P1.getY() + roundf(Length*sin(tetha+90))), P1.getColor());
		center = Point(P1.getX() + roundf(Length*0.5*cos(tetha+45)), (P1.getY() + roundf(Length*0.5*sin(tetha+45))));
		anchor = Point(center);
	}

	Square::Square(int x1, int y1, const Color& color,int Length, float tetha) : p1(x1,y1,color), length(length), tetha(tetha){
		p2 = Point((x1+roundf(Length*cos(tetha))), (y1 + roundf(Length*sin(tetha))), color);
		p3 = Point((x1+roundf(Length*cos(tetha+45))), (y1 + roundf(Length*sin(tetha+45))), color);
		p4 = Point((x1+roundf(Length*cos(tetha+90))), (y1 + roundf(Length*sin(tetha+90))), color);
	}

	Square::Square(const Square &sqr){
		*this = sqr;
	}

	Square& Square::operator=(const Square &sqr){
		if(this != &sqr){
			this->p1 = sqr.p1;
			this->p2 = sqr.p2;
			this->p3 = sqr.p3;
			this->p4 = sqr.p4;
			this->length = sqr.length;
			this->tetha = sqr.tetha;
		}
		return *this;
	}

	Square::~Square(){
	}

	bool Graphics::operator==(const Square& S1, const Square& S2){
		if ((S1.p1 == S2.p1) && (S1.p2 == S2.p2) && (S1.p3 == S2.p3) && (S1.p4 == S2.p4)){
			return true;
		}
		else{
			return false;
		}
	}

	bool Graphics::operator!=(const Square& S1, const Square& S2){
		return !(S1 == S2);
	}

	const Point &Square::getPoint1() const{
		return p1;
	}

	const Point &Square::getPoint2() const{
		return p2;
	}

	const Point &Square::getPoint3() const{
		return p3;
	}

	const Point &Square::getPoint4() const{
		return p4;
	}

	const Point &Square::getAnchor() const{
		return anchor;
	}

	const Point &Square::getCenter() const{
		return center;
	}

	void Square::setPoint1(const Point& p){
		this->p1 = p;
	}

	void Square::setPoint2(const Point& p){
		this->p2 = p;
	}

	void Square::setPoint3(const Point& p){
		this->p3 = p;
	}

	void Square::setPoint4(const Point& p){
		this->p4 = p;
	}

	void Square::setAnchor(const Point& p){
		this->anchor = p;
	}

	int Square::getLength(){
		return length;
	}

	/*const Color &Square::getColor() const{
		return color;
	}

	void Square::setColor(const Color& color){
		this->color = color;
	}*/

	void Square::move(int dx, int dy){
		int rslx1 = p1.getX() + dx;
		int rslx2 = p2.getX() + dx;
		int rslx3 = p3.getX() + dx;
		int rslx4 = p4.getX() + dx;
		int rsly1 = p1.getY() + dy;
		int rsly2 = p1.getY() + dy;
		int rsly3 = p1.getY() + dy;
		int rsly4 = p1.getY() + dy;
		bool geser = (rslx1 >= SCREEN_X_MIN && rslx1 <= SCREEN_X_MAX &&
					  rslx2 >= SCREEN_X_MIN && rslx2 <= SCREEN_X_MAX &&
					  rslx3 >= SCREEN_X_MIN && rslx3 <= SCREEN_X_MAX &&
					  rslx4 >= SCREEN_X_MIN && rslx4 <= SCREEN_X_MAX &&
					  rsly1 >= SCREEN_Y_MIN && rsly1 <= SCREEN_Y_MAX &&
					  rsly2 >= SCREEN_Y_MIN && rsly2 <= SCREEN_Y_MAX &&
					  rsly3 >= SCREEN_Y_MIN && rsly3 <= SCREEN_Y_MAX &&
					  rsly4 >= SCREEN_Y_MIN && rsly4 <= SCREEN_Y_MAX);
		if (geser){
			p1.move(dx,dy);
			p2.move(dx,dy);
			p3.move(dx,dy);
			p4.move(dx,dy);
			center.move(dx,dy);
			anchor.move(dx,dy);
		}
	}

	void Square::drawFill() const{
	}

	void Square::drawOutline() const{
		Edge drawer1(p1,p2);
		Edge drawer2(p1,p4);
		Edge drawer3(p2,p3);
		Edge drawer4(p3,p4);

		drawer1.draw();
		drawer2.draw();
		drawer3.draw();
		drawer4.draw();
	}
