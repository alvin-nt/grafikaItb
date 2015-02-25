#include "Ellipse.hpp"
#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Ellipse::Ellipse(const Point& center,float theta,float jari,float weight)
	: center(center), theta(theta), jari(jari), weight(weight)
{
	
}

Ellipse::Ellipse(int x1, int y1, const Color& c1,float theta,float jari,float weight)
	: center(x1, y1, c1),theta(theta),jari(jari),weight(weight)
{
	
}

Ellipse::Ellipse(const Ellipse &Ellipse) {
	*this = Ellipse;
}

Ellipse::~Ellipse() {

}

Ellipse& Ellipse::operator=(const Ellipse &rhs) {
	if(this != &rhs) {
		center = rhs.center;
		theta= rhs.theta;
		jari = rhs.jari;
		weight = rhs.weight;
	}
	return *this;
}

bool Graphics::operator!=(const Ellipse &lhs, const Ellipse &rhs) {
	return !(lhs == rhs);
}

bool Graphics::operator==(const Ellipse &lhs, const Ellipse &rhs) {
	return (lhs.center == rhs.center &&
			lhs.theta == rhs.theta &&
			lhs.jari == rhs.jari &&
			lhs.weight == rhs.weight);
}

const Point &Ellipse::getCenter() const {
	return center;
}

void Ellipse::setCenter(const Point& center) {
	this->center = center;
}

float Ellipse::getTheta(){
	return theta;
}

void Ellipse::setTheta(float theta) {
	this->theta = theta;
}

float Ellipse::getJari(){
	return jari;
}

void Ellipse::setJari(float jari){
	this->jari = jari;
}

float Ellipse::getWeight(){
	return weight;
}

void Ellipse::setWeight(float weight) {
	this->weight = weight;
}

double Ellipse::getLength() const {
	return 0;
}

float Ellipse::getLengthFloat() const {
	return 0.0;
}

void Ellipse::rotate(int degree) {
	
}


void Ellipse::drawFill() const {
	//TBD

}

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
void Ellipse::drawOutline() const{
	Rasterizer *raster = Screen::instance();
	Point Ptemp;
	float fullrotate;
	fullrotate = theta;
	Ptemp.setX((int)roundf(center.getX() + jari*cos(fullrotate)));
	Ptemp.setY((int)roundf(center.getY() - 0.5*jari*sin(fullrotate)));
	Pixel basePixel = Color::BLUE.toPixel();
	while(fullrotate != theta+360.00)
	{
		byte alpha = (byte)roundf(std::max(.0f, 255 * (weight)));
		Pixel drawPixel = basePixel | alpha;
		
		raster->setPixel(Ptemp.getX(),Ptemp.getY(), drawPixel);
		fullrotate += 1.0f;
		Ptemp.setX(round(center.getX() + jari*cos(fullrotate)));
		Ptemp.setY(round(center.getY() - 0.5*jari*sin(fullrotate)));
	}
}

void Ellipse::move(int dx,int dy)
{
	center.setX(center.getX() + dx);
	center.setY(center.getY() + dy);
}

void Ellipse::scale(int scale) {
	//TBD
}
