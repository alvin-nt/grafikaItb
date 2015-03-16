#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "ShapeFillable.hpp"
#include "Point.hpp"
#include "Edge.hpp"
#include "Color.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Rectangle : public ShapeFillable {
	friend class Cube;
	friend class Cruiser;
	private:
		// now using the edges element
		// @see {ShapeFillable}
		
		float weight;
	public:
		Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4, 
					float weight = 1.0f, const Color& baseColor = Color::WHITE);
		Rectangle(int x1, int y1, const Color& c1,
			int x2, int y2, const Color& c2,
			int x3, int y3, const Color& c3,
			int x4, int y4, const Color& c4, float weight);
		Rectangle(const Rectangle&);
		~Rectangle();
		
		Rectangle& operator=(const Rectangle&);
		
		friend bool operator!=(const Rectangle& lhs, const Rectangle& rhs);
		
		friend bool operator==(const Rectangle& lhs, const Rectangle& rhs);
		
		/**
		 * Gets the first point of the Rectangle
		 * 
		 * @return first point
		 **/
		const Point& getPoint1() const;
		
		/**
		 * Sets the first point of the Rectangle
		 * 
		 * @param point the new point
		 **/
		void setPoint1(const Point& point);
		
		void setPoint1(int x, int y);
		
		/**
		 * Gets the second point of the Rectangle
		 * 
		 * @return second point
		 **/
		const Point& getPoint2() const;
		
		/**
		 * Sets the second point of the Rectangle
		 * 
		 * @param point the new point
		 **/
		void setPoint2(const Point&);
		
		void setPoint2(int x, int y);
		
		/**
		 * Gets the third point of the Rectangle
		 * 
		 * @return third point
		 **/
		const Point& getPoint3() const;
		
		/**
		 * Sets the third point of the Rectangle
		 * 
		 * @param point the new point
		 **/
		void setPoint3(const Point&);
		
		void setPoint3(int x, int y);
		
		/**
		 * Gets the fourth point of the Rectangle
		 * 
		 * @return fourth point
		 **/
		const Point& getPoint4() const;
		
		/**
		 * Sets the fourth point of the Rectangle
		 * 
		 * @param point the new point
		 **/
		void setPoint4(const Point&);
		
		void setPoint4(int x, int y);
		
		/**
		 * Gets the weight parameter of the Rectangle
		 * 
		 * @return weight
		 **/
		float getWeight() const;
		
		/**
		 * Sets the weight parameter of the Rectangle
		 * 
		 * @param weight the new weight
		 **/
		void setWeight(float weight);
		
		double getLength() const;
		
		float getLengthFloat() const;
		
		Point getMidpoint() const;
	
	protected:
		void drawOutline() const;
		void drawFill() const;
	};

}

#endif

