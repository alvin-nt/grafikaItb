#include "ViewPort.hpp"
#include "Rectangle.hpp"
#include "Peta.hpp"
#include <cmath>

using namespace Graphics;

ViewPort::ViewPort(int vwx, int vwy, int wx, int wy, int hSize, int vSize, const Peta* pt)
	: vwCenter(vwx, vwy), wCenter(wx, wy), hSize(hSize), vSize(vSize), zoom(1), peta(pt)
{
	
}

ViewPort::~ViewPort()
{
	
}

int ViewPort::getMinViewX() const
{
	return vwCenter.getX() - (hSize >> 1);
}

int ViewPort::getMaxViewX() const
{
	return vwCenter.getX() + (hSize >> 1);
}
		
int ViewPort::getMinViewY() const
{
	return vwCenter.getY() - (vSize >> 1);
}

int ViewPort::getMaxViewY() const
{
	return vwCenter.getY() + (vSize >> 1);
}
		
void ViewPort::setZoom(int zoom)
{
	this->zoom = zoom;
}

void ViewPort::zoomIn()
{
	if(zoom <= 4) {
		zoom <<= 1;
	}
}

void ViewPort::zoomOut()
{
	if(zoom > 1) {
		zoom >>= 1;
	}
}

void ViewPort::draw() const
{
	// draw the window
	Rectangle window(wCenter.getX() - (hSize >> 1), wCenter.getY() - (vSize >> 1), Color::WHITE,
					wCenter.getX() + (hSize >> 1), wCenter.getY() - (vSize >> 1), Color::WHITE,
					wCenter.getX() + (hSize >> 1), wCenter.getY() + (vSize >> 1), Color::WHITE,
					wCenter.getX() - (hSize >> 1), wCenter.getY() + (vSize >> 1), Color::WHITE,
					1.0f);
	window.draw();
	
	// do sum clipping here
	for(int i = 0; i < 155; i++) 
	{
		clipAndDraw(peta->e[i]);
	}
}

void ViewPort::move(int dx, int dy)
{
	bool move = (dx != 0 || dy != 0);
	
	// check dx
	if(move) {
		if(dx > 0) {
			move = (getMaxViewX() <= SCREEN_X_MAX);
		}
		else if (dx < 0) {
			move = (getMinViewX() >= SCREEN_X_MIN);
		}
	}
	
	// check dy
	if(move) {
		if (dy > 0) {
			move = (getMaxViewY() <= SCREEN_Y_MAX);
		}
		else if (dy < 0) {
			move = (getMinViewY() >= SCREEN_Y_MIN);
		}
	}
	
	// move it!
	if(move) {
		vwCenter.move(dx, dy);
	}
}

void ViewPort::clipAndDraw(const Edge& e) const
{
	clipAndDraw(e.getPoint1(), e.getPoint2());
}

void ViewPort::setPeta(const Peta* peta)
{
	this->peta = peta;
}

void ViewPort::clipAndDraw(const Point& p1, const Point& p2) const
{
	// check the outcode, and check whether both of them lies in the window/viewport
	int outCode1 = getOutCode(p1.getX(), p1.getY());
	int outCode2 = getOutCode(p2.getX(), p2.getY());
	bool accept =  false;
	
	int x0 = p1.getX(), x1 = p2.getX();
	int y0 = p1.getY(), y1 = p2.getY();
	
	while (true) {
		if (!(outCode1 | outCode2)) { // Bitwise OR == 0 >> line inside the viewport
			accept = true;
			break;
		} else if (outCode1 & outCode2) { // Bitwise AND != 0 >> line outside the viewport
			break;
		} else {
			int x, y;
			
			// check one of the points, must be outside.
			int outCodeOut = outCode1 ? outCode1 : outCode2;
			
			// find the intersection point
			if (outCodeOut & TOP) {
				x = x0 + (x1 - x0) * (getMaxViewY() - y0) / (y1 - y0);
				y = getMaxViewY();
			} else if (outCodeOut & BOTTOM) {
				x = x0 + (x1 - x0) * (getMinViewY() - y0) / (y1 - y0);
				y = getMinViewY();
			} else if (outCodeOut & RIGHT) {
				y = y0 + (y1 - y0) * (getMaxViewX() - x0) / (x1 - x0);
				x = getMaxViewX();
			} else if (outCodeOut & LEFT) {
				y = y0 + (y1 - y0) * (getMinViewX() - x0) / (x1 - x0);
				x = getMinViewX();
			}
			
			// update the respective points
			if (outCodeOut == outCode1) {
				x0 = x;
				y0 = y;
				outCode1 = getOutCode(x0, y0);
			} else {
				x1 = x;
				y1 = y;
				outCode2 = getOutCode(x1, y1);
			}
		}
	}
	
	if (accept) {
		Point dr1(view2Window(Point(x0, y0)));
		dr1.setColor(Color::WHITE);
		Point dr2(view2Window(Point(x1, y1)));
		dr2.setColor(Color::WHITE);
		
		Edge dre(dr1, dr2);
		dre.draw();
	}
}

void ViewPort::clipAndDraw(const Point& p) const
{
	int x = p.getX();
	int y = p.getY();
	
	if(x >= getMinViewX() && x <= getMaxViewX() &&
		y >= getMinViewY() && y <= getMaxViewY())
	{
		p.draw();
	}
}

int ViewPort::getOutCode(int x, int y) const
{
	int code = INSIDE;
	
	if (x < getMinViewX()) {
		code |= LEFT;
	} else if (x > getMaxViewX()) {
		code |= RIGHT;
	}
	
	if (y < getMinViewY()) { // 'below' the clip window
		code |= BOTTOM;
	} else if (y > getMaxViewY()) { // 'top' of the clip window
		code |= TOP;
	}
	
	return code;
}

Point ViewPort::window2View(const Point& pw) const
{
	Point pv;
	pv.setX((pw.getX()-wCenter.getX())*zoom+vwCenter.getX());
	pv.setY((pw.getY()-wCenter.getY())*zoom+vwCenter.getY());
	return pv;
}

Point ViewPort::view2Window(const Point& pv) const
{
	Point pw;
	pw.setX(round((pv.getX()-vwCenter.getX())/zoom)+wCenter.getX());
	pw.setY(round((pv.getY()-vwCenter.getY())/zoom)+wCenter.getY());
	return pw;
}
