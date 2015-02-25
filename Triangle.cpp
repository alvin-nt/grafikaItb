#include "Triangle.hpp"
#include "Rasterizer.hpp"
#include <list>
#include <cmath>
#include <algorithm>

using namespace Graphics;

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3,float weight)
	: p1(p1), p2(p2), p3(p3), weight(weight)
{
}

Triangle::Triangle(int x1, int y1, const Color& c1,
			int x2, int y2, const Color& c2,
			int x3, int y3, const Color& c3, float weight)
	: p1(x1, y1, c1), p2(x2, y2, c2), p3(x3, y3, c3), weight(weight)
{
}

Triangle::Triangle(const Triangle &Triangle) {
	*this = Triangle;
}

Triangle::~Triangle() {

}

Triangle& Triangle::operator=(const Triangle &rhs) {
	if(this != &rhs) {
		p1 = rhs.p1;
		p2 = rhs.p2;
		p3 = rhs.p3;
		weight = rhs.weight;
	}
	return *this;
}

bool Graphics::operator!=(const Triangle &lhs, const Triangle &rhs) {
	return !(lhs == rhs);
}

bool Graphics::operator==(const Triangle &lhs, const Triangle &rhs) {
	return (lhs.p1 == rhs.p1 &&
			lhs.p2 == rhs.p2 &&
			lhs.p3 == rhs.p3 &&
			lhs.weight == rhs.weight);
}

const Point &Triangle::getPoint1() const {
	return p1;
}

void Triangle::setPoint1(const Point& p1) {
	this->p1 = p1;
}

const Point &Triangle::getPoint2() const {
	return p2;
}

void Triangle::setPoint2(const Point& p2) {
	this->p2 = p2;
}

const Point &Triangle::getPoint3() const {
	return p3;
}

void Triangle::setPoint3(const Point& p3) {
	this->p3 = p3;
}


float Triangle::getWeight() const {
	return weight;
}

void Triangle::setWeight(float weight) {
	this->weight = weight;
}

double Triangle::getLength() const {
	return 0;
}

float Triangle::getLengthFloat() const {
	return 0.0;
}

void Triangle::rotate(int degree) {
	int tmp = p1.getX();
	double rad = (double)degree*180/3.1415926535897;
	p1.setX(anchor.getX() + p1.getX()*cos(rad) - p1.getY()*sin(rad));
	p1.setY(anchor.getY() + p1.getY()*cos(rad) + tmp*sin(rad));
	tmp = p2.getX();
	p2.setX(anchor.getX() + p2.getX()*cos(rad) - p2.getY()*sin(rad));
	p2.setY(anchor.getY() + p2.getY()*cos(rad) + tmp*sin(rad));
	tmp = p3.getX();
	p3.setX(anchor.getX() + p3.getX()*cos(rad) - p3.getY()*sin(rad));
	p3.setY(anchor.getY() + p3.getY()*cos(rad) + tmp*sin(rad));
}

void Triangle::drawOutline() const {
	//panggil edge aja disini
	Edge drawer1(p1,p2);
	Edge drawer2(p2,p3);
	Edge drawer3(p3,p1);
	drawer1.draw();
	drawer2.draw();
	drawer3.draw();
}

void Triangle::drawFill() const {
	int i,x1,x2,x3,y1,y2,y3,j1,j2;
	std::list<Edge> L;
	Color c(Color::RED);
	x1 = p1.getX();
	x2 = p2.getX();
	x3 = p3.getX();
	y1 = p1.getY();
	y2 = p2.getY();
	y3 = p3.getY();
	for(i=x1;i<x2;i++){
		j1 = (i-x1) * (y3-y1) / (x3-x1) + y1;
		j2 = (i-x1) * (y2-y1) / (x2-x1) + y1;
		Point t1(i,j1,c);
		Point t2(i,j2,c);
		Edge e(t1,t2);
		L.push_back(e);
	}
	
	for(i=x2;i<x3;i++){
		j1 = (i-x1) * (y3-y1) / (x3-x1) + y1;
		j2 = (i-x2) * (y3-y2) / (x3-x2) + y2;
		Point t1(i,j1,c);
		Point t2(i,j2,c);
		Edge e(t1,t2);
		L.push_back(e);
	}
	
	std::list<Edge>::iterator p;
	for(p = L.begin(); p!=L.end() ; ++p){
		(*p).draw();
	}

}

void Triangle::move(int dx, int dy) {
	int resultX1 = p1.getX() + dx;
	int resultY1 = p1.getY() + dy;
	int resultX2 = p2.getX() + dx;
	int resultY2 = p2.getY() + dy;
	int resultX3 = p3.getX() + dx;
	int resultY3 = p3.getY() + dy;
	
	bool move =(resultX1 >= SCREEN_X_MIN && resultX1 <= SCREEN_X_MAX &&
				resultY1 >= SCREEN_Y_MIN && resultY1 <= SCREEN_Y_MAX &&
				resultX2 >= SCREEN_X_MIN && resultX2 <= SCREEN_X_MAX &&
				resultY2 >= SCREEN_Y_MIN && resultY2 <= SCREEN_Y_MAX &&
				resultX3 >= SCREEN_X_MIN && resultX3 <= SCREEN_X_MAX &&
				resultY3 >= SCREEN_Y_MIN && resultY3 <= SCREEN_Y_MAX);
	
	if(move) {
		p1.move(dx, dy);
		p2.move(dx, dy);
		p3.move(dx, dy);
	}
}

void Triangle::sortX(){
	Point p;
	if(p1.getX() < p2.getX()){
		//p1.getX() < p2.getX()
		if(p2.getX() < p3.getX()){
			//p1.getX() < p2.getX() < p3.getX()
			//do nothing
		}
		else{
			//p3.getX() < p2.getX() && p1.getX() < p2.getX()
			if(p3.getX()<p1.getX()){
				//p3.getX() < p1.getX() < p2.getX()
				p=p3;
				p3=p2;
				p2=p1;
				p1=p3;
			}
			else{
				//p1.getX() < p3.getX() < p2.getX()
				p=p3;
				p3=p2;
				p2=p;
			}
		}
	}
	else{
		//p2.getX() < p1.getX()
		if(p1.getX() < p3.getX()){
			//p2.getX() < p1.getX() < p3.getX()
			p=p2;
			p2=p1;
			p1=p;
		}
		else{
			//p3.getX() < p1.getX() && p2.getX() < p1.getX()
			if(p3.getX()<p2.getX()){
				//p3.getX() < p2.getX() < p1.getX()
				p=p3;
				p3=p1;
				p1=p;
			}
			else{
				//p2.getX() < p3.getX() < p1.getX()
				p=p1;
				p1=p2;
				p2=p3;
				p3=p;
			}
		}
	}
}

void Triangle::scale(int scale){

}
