#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point.hpp"
#include "Drawable.hpp"
#include "Types.hpp"

namespace Graphics {
	class Shape : public Drawable {
	protected:
		// future implementation of anchor point?
		Point anchor;
	public:
		virtual ~Shape() = 0;
		
		/**
		 * Moves the shape
		 * 
		 * @param dx movement along the horizonal line
		 * @param dy movement along the vertical line
		 **/
		virtual inline void move(int dx, int dy) = 0;
		
		/**
		 * Rotates a shape
		 * 
		 * @param degree the degree of rotation
		 */
		virtual void rotate(int degree) = 0;
		
		/**
		 * get the anchor point
		 **/
		const Point &getAnchor() const {
			return anchor;
		}
		
		void setAnchor(const Point &p) {
			anchor = p;
		}
		
		void setAnchor(int x, int y) {
			anchor.setX(x);
			anchor.setY(y);
		}
	};
}

#endif
