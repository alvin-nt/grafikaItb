#ifndef Triangle_H_
#define Triangle_H_

#include "ShapeFillable.hpp"
#include "Point.hpp"
#include "Edge.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Triangle : public ShapeFillable {
	private:
		Point p1, p2, p3;
		float weight;
	public:
		Triangle(const Point& p1, const Point& p2, const Point& p3, float weight = 1.0f);
		Triangle(int x1, int y1, const Color& c1,
			int x2, int y2, const Color& c2,
			int x3, int y3, const Color& c3, float weight);
		Triangle(const Triangle&);
		~Triangle();
		
		Triangle& operator=(const Triangle&);
		
		friend bool operator!=(const Triangle& lhs, const Triangle& rhs);
		
		friend bool operator==(const Triangle& lhs, const Triangle& rhs);
		
		/**
		 * Gets the first point of the Triangle
		 * 
		 * @return first point
		 **/
		const Point& getPoint1() const;
		
		/**
		 * Sets the first point of the Triangle
		 * 
		 * @param point the new point
		 **/
		void setPoint1(const Point& point);
		
		/**
		 * Gets the second point of the Triangle
		 * 
		 * @return second point
		 **/
		const Point& getPoint2() const;
		
		/**
		 * Sets the second point of the Triangle
		 * 
		 * @param point the new point
		 **/
		void setPoint2(const Point&);
		
		/**
		 * Gets the third point of the Triangle
		 * 
		 * @return third point
		 **/
		const Point& getPoint3() const;
		
		/**
		 * Sets the third point of the Triangle
		 * 
		 * @param point the new point
		 **/
		void setPoint3(const Point&);
		
		/**
		 * Gets the fourth point of the Triangle
		 * 
		 * @return fourth point
		 **/
		
		float getWeight() const;
		
		/**
		 * Sets the weight parameter of the Triangle
		 * 
		 * @param weight the new weight
		 **/
		void setWeight(float weight);
		
		double getLength() const;
		float getLengthFloat() const;
		
		void rotate(int degree);
		void scale(int scale);
		void move(int dx, int dy);
	
	protected:
		void drawOutline() const;
		void drawFill() const;
	};

}

#endif

