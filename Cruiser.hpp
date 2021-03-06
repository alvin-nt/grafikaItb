#ifndef CRUISER_H_
#define CRUISER_H_

#include "ShapeFillable.hpp"
#include "Point.hpp"
#include "Edge.hpp"
#include "Rectangle.hpp"
#include "Ellipse.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Cruiser : public ShapeFillable {
	private:
		Rectangle *body;
		Ellipse *turret;
		Edge *gun;
		Ellipse *bullet;
		int xAwal;
		int yAwal;
		
	public:
		Cruiser(int x, int y, const Color& baseColor);
		~Cruiser();
		void fire();
		void move(int dx);
		Point getLowerLeftPoint();
		Point getUpperLeftPoint();
		Point getUpperRightPoint();
		Point getLowerRightPoint();
		int getXMidPoint();
	protected:
		void drawOutline() const;
		void drawFill() const;
	};

}

#endif

