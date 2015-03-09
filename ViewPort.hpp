#ifndef VIEWPORT_H_
#define VIEWPORT_H_

#include "Drawable.hpp"
#include "Point.hpp"
#include "Edge.hpp"
#include "Peta.hpp"
#include "Rectangle.hpp"

namespace Graphics {
	class ViewPort : public Drawable {
	private:
		const static int INSIDE = 0; // 0000
		const static int LEFT = 1; // 0001
		const static int RIGHT = 2; // 0010
		const static int BOTTOM = 4; // 0100
		const static int TOP = 8; // 1000
		
	private:
		Point vwCenter, wCenter;
		int hSize, vSize;
		const Peta *peta;
		Rectangle *wBox, *vwBox;
		
		float zoom;
	public:
		ViewPort(int vwx, int vwy, int wx, int wy, int hSize, int vSize, const Peta* pt);
		~ViewPort();
		
		int getMinViewX() const;
		int getMaxViewX() const;
		
		int getMinViewY() const;
		int getMaxViewY() const;
		
		bool isZoom() const;
		
		void setZoom(int zoom);
		void zoomIn();
		void zoomOut();
		void move(int dx, int dy);
		
		void setPeta(const Peta*);
	protected:
		void draw() const;
		
		void clipAndDraw(const Edge& e) const;
		void clipAndDraw(const Point& p1, const Point& p2) const;
		void clipAndDraw(const Point& p) const;
		
		int getOutCode(int x, int y) const;
		
		Point window2View(const Point&) const;
		Point view2Window(const Point&) const;
	};
}

#endif
