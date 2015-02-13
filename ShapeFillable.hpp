#ifndef SHAPE_FILLABLE_H_
#define SHAPE_FILLABLE_H_

#include "Point.hpp"
#include "Shape.hpp"

namespace Graphics {
	class ShapeFillable : public Shape {
	public:
		virtual ~ShapeFillable() = 0;
		
		/**
		 * Wraps the call to draw(false)
		 */
		virtual void draw() const;
		
		/**
		 * Function that stores the call to the apropriate drawing algorithm
		 * Wraps the call to the apropriate function (i.e., drawFill() or drawOutline())
		 *
		 * @param fill the fill mode; false only draws the shape's outline, true draws the outline + the filler
		 */
		virtual void draw(bool fill) const;
		
	protected:
		/**
		 * Algorirthm to draw the filled shape
		 */
		virtual void drawFill() const;
		
		
		/**
		 * Algorirthm to draw the outline of the shape
		 */
		virtual void drawOutline() const;
	};
}

#endif
