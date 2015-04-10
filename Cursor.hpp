#ifndef CURSOR_H_
#define CURSOR_H_

#include "ShapeFillable.hpp"
#include "Point.hpp"
#include "Edge.hpp"
#include "Color.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Cursor : public ShapeFillable {
	public:
		Cursor(int x, int y);
		~Cursor();
		
		const Point& getPoint() const;
		
		/**
		 * Sets the first point of the Rectangle
		 * 
		 * @param point the new point
		 **/
		//void setPoint(const Point& point);
		
		void setPoint(int x, int y);
	
	protected:
		void drawOutline() const;
		void drawFill() const;
	};

}

#endif
