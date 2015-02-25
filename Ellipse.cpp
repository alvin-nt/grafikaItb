#include "Ellipse.hpp"
#include "Rasterizer.hpp"

#include <cmath>
#include <algorithm>

using namespace Graphics;

Ellipse::Ellipse(const Point& center,float theta,float jari,float weight,float smash)
	: center(center), theta(theta), jari(jari), weight(weight),smash(smash)
{
	
}

Ellipse::Ellipse(int x1, int y1, const Color& c1,float theta,float jari,float weight,float smash)
	: center(x1, y1, c1),theta(theta),jari(jari),weight(weight),smash(smash)
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
		smash = rhs.smash;
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
			lhs.weight == rhs.weight&&
			lhs.smash == rhs.smash);
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

float Ellipse::getSmash(){
	return smash;
}

void Ellipse::setSmash(int smash){
	this->smash = smash;
}

void Ellipse::rotate(int degree) {
	setTheta(theta + (float)degree);
}


void Ellipse::drawFill() const {
	//TBD

}

void Ellipse::drawOutline() const{
	Rasterizer *raster = Screen::instance();
	float fullrotate = 0.0f;
	
	int drawPixelX = (int)roundf(center.getX() + jari * cosf(fullrotate));
	int drawPixelY = (int)roundf(center.getY() - (0.5 * jari * sinf(fullrotate)));
	
	Pixel basePixel = Color::BLUE.toPixel();
	byte alpha = (byte)roundf(std::max(.0f, 255 * (weight)));
	Pixel drawPixel = basePixel | alpha;
	while(fullrotate != 90)
	{
		raster->setPixel(drawPixelX, drawPixelY, drawPixel);
		fullrotate += 0.7f;
		drawPixelX = (int)roundf(center.getX() + jari * cosf(fullrotate));
		drawPixelY = (int)roundf(center.getY() - 0.5 * jari * sinf(fullrotate));
	}
}

void Ellipse::move(int dx,int dy)
{
	int newX = center.getX() + dx;
	int newY = center.getY() + dy;
	
	bool move =(newX-(int)jari*cosf(theta) >= SCREEN_X_MIN && newX+(int)jari*cosf(theta) <= SCREEN_X_MAX &&
				newY-(int)jari*smash*sinf(theta) >= SCREEN_Y_MIN && newY+(int)jari*sinf(theta) <= SCREEN_Y_MAX);
	
	if(move) {
		center.setX(newX);
		center.setY(newY);
	}
}

void Ellipse::scale(int x){
	
}
