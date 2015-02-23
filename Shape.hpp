#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point.hpp"
#include "Types.hpp"

namespace Graphics {
	class Drawable;
	
	class Shape : public Drawable {
	protected:
		Point anchor;
	public:
		virtual ~Shape() = 0;
		
		/**
		 * Rotates a shape
		 * 
		 * @param degree the degree of rotation
		 */
		virtual void rotate(int degree) = 0;
		
		/**
		 * Scales the shape
		 * 
		 * @param scale the scale factor
		 **/
		virtual void scale(int scale) = 0;
		
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
