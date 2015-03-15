#ifndef HELICOPTER_H_
#define HELICOPTER_H_

#include "ShapeFillable.hpp"
#include "Point.hpp"
#include "Edge.hpp"
#include "Color.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Helicopter : public ShapeFillable {
	//friend class Cube;
	private:
		// now using the edges element
		// @see {ShapeFillable}
		int angle;
		int size;
		Point midpoint;
		float weight;
	public:
		Helicopter(const Point& midpoint, int angle, const Color& baseColor = Color::WHITE, float weight = 1.0f, int size = 1) ;
		Helicopter(const Helicopter&);
		~Helicopter();
		
		Helicopter& operator=(const Helicopter&);
		
		friend bool operator!=(const Helicopter& lhs, const Helicopter& rhs);
		
		friend bool operator==(const Helicopter& lhs, const Helicopter& rhs);
		
		friend double degtorad(int deg);
		
		void setMidpoint(const Point& p);
		
		float getWeight() const;
		
		void setWeight(float weight);
		
		Point getMidpoint() const;
		
		void moveHelicopter(int dx, int dy);
	
	protected:
		void drawOutline() const;
		void drawFill() const;
	};

}

#endif
