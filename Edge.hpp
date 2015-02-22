#ifndef EDGE_H_
#define EDGE_H_

#include "Shape.hpp"
#include "Point.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Edge : public Shape {
		friend class Rectangle;
	private:
		Point p1, p2;
		
		float weight;
	public:
		Edge(const Point& p1, const Point& p2, float weight = 1.0f);
		Edge(int x1, int y1, const Color& c1,
			int x2, int y2, const Color& c2, float weight);
		Edge(const Edge&);
		~Edge();
		
		Edge& operator=(const Edge&);
		
		friend bool operator!=(const Edge& lhs, const Edge& rhs);
		
		friend bool operator==(const Edge& lhs, const Edge& rhs);
		
		/**
		 * Gets the first point of the edge
		 * 
		 * @return first point
		 **/
		const Point& getPoint1() const;
		
		/**
		 * Sets the first point of the edge
		 * 
		 * @param point the new point
		 **/
		void setPoint1(const Point& point);
		
		/**
		 * Gets the second point of the edge
		 * 
		 * @return second point
		 **/
		const Point& getPoint2() const;
		
		/**
		 * Sets the second point of the edge
		 * 
		 * @param point the new point
		 **/
		void setPoint2(const Point&);
		
		/**
		 * Gets the weight parameter of the edge
		 * 
		 * @return weight
		 **/
		float getWeight() const;
		
		/**
		 * Sets the weight parameter of the edge
		 * 
		 * @param weight the new weight
		 **/
		void setWeight(float weight);
		
		/**
		 * Gets the horizontal differences between point 2 and point 1
		 * 
		 * @return p2.x - p1.x
		 **/
		int getDeltaX() const;
		
		/**
		 * Gets the vertical differences between point 2 and point 1
		 * 
		 * @return p2.y - p1.y
		 **/
		int getDeltaY() const;
		
		/**
		 * Gets the gradient of the line
		 * 
		 * @return line gradient
		 **/
		double getGradient() const;
		
		/**
		 * Gets the length of the line
		 * 
		 * @return line length, as double
		 **/
		double getLength() const;
		
		/**
		 * Gets the length of the line
		 * 
		 * @return line length, as float
		 **/
		float getLengthFloat() const;
		
		/**
		 * Swaps the first and the second point
		 **/
		void swapPoints();
		
		/**
		 * Gets the midpoint of the line
		 * 
		 * @return midpoint
		 **/
		Point getMidpoint() const;
		
		/**
		 * Rotates the line
		 * 
		 * @param degree the degree
		 **/
		void rotate(int degree);
		
		/**
		 * Scales the line
		 * 
		 * @param ds the scale number
		 **/
		void scale(int ds);
		
		/**
		 * Moves the line
		 * 
		 * @param dx movement in x coordinate
		 * @param dy movement in y coordinate
		 **/
		void move(int dx, int dy);
	
	protected:
		void draw() const;
	};

	typedef Edge Line; // handy naming convention
}

#endif
