#ifndef CUBE_H_
#define CUBE_H_

#include "ShapeFillable.hpp"
#include "Point.hpp"
#include "Edge.hpp"
#include "Rectangle.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Cube : public ShapeFillable {
	private:
		Point p1,p2,p3,p4,p5,p6,p7,p8;
		int length, pov;
		/* sudut pandang
		 * 1 = kiri
		 * 2 = tengah
		 * 3 = kanan
		 */
	public:
		Cube(const Point& p, int s);
		~Cube();
		int getLength();
		void setLength(int newLength);
		int getPov();
		void setPov(int newPov);
		void rotate(int degree);
		void move(int dx, int dy);
	protected:
		void drawOutline() const;
		void drawFill() const;
	};

}

#endif

