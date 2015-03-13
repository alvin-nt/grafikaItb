#ifndef SHAPE_FILLABLE_H_
#define SHAPE_FILLABLE_H_

#include "Point.hpp"
#include "Shape.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include <vector>

using std::vector;

namespace Graphics {
	class ShapeFillable : public Shape {
		friend class Rasterizer;
	protected:
		bool fill = false;
		
		// pointers to edges
		vector<Edge*> edges;
		
		Color baseColor;
	public:
		virtual ~ShapeFillable() = 0;
		
		ShapeFillable& operator= (const ShapeFillable& rhs);
		
		/**
		 * Draws the shape to the screen
		 */
		virtual void draw() const;
		
		/**
		 * Function that stores the call to the apropriate drawing algorithm
		 * Wraps the call to the apropriate function (i.e., drawFill() or drawOutline())
		 *
		 * @param fill the fill mode; false only draws the shape's outline, true draws the outline + the filler
		 */
		virtual void draw(bool fill);
		
		void setFill(bool fill);
		
		void setFillColor(const Color& color);
		
		const Color& getFillColor() const;
		
		bool getFill() const;
		
		void move(int dx, int dy);
		
		void rotate(float degree);
		
		void scale(float ds);
		
		void scale(float sx, float sy);
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
