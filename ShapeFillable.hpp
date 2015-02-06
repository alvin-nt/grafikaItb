#ifndef SHAPE_FILLABLE_H_
#define SHAPE_FILLABLE_H_

#include "Point.hpp"
#include "Shape.hpp"

namespace Graphics {
	class Shape;
	
	class ShapeFillable : public Shape {
	public:
		virtual ~ShapeFillable() = 0;
		
		/**
		 * Wraps the call to draw(false)
		 */
		inline void draw() const {
			draw(false);
		}
		
		/**
		 * Function that stores the call to the apropriate drawing algorithm
		 * Wraps the call to the apropriate function (i.e., drawFill() or drawOutline())
		 *
		 * @param fill the fill mode; false only draws the shape's outline, true draws the outline + the filler
		 */
		virtual inline void draw(bool fill) const {
			if(fill)
				drawFill();
			else
				drawOutline();
		}
		
	protected:
		/**
		 * Algorirthm to draw the filled shape
		 */
		virtual inline void drawFill() const = 0;
		
		/**
		 * Algorirthm to draw the outline of the shape
		 */
		virtual inline void drawOutline() const = 0;
	};
}

#endif
