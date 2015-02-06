#ifndef EDGE_H_
#define EDGE_H_

#include "Shape.hpp"
#include "Point.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Edge : public Shape {
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
		inline int getDeltaX() const;
		
		/**
		 * Gets the vertical differences between point 2 and point 1
		 * 
		 * @return p2.y - p1.y
		 **/
		inline int getDeltaY() const;
		
		/**
		 * Gets the gradient of the line
		 * 
		 * @return line gradient
		 **/
		inline double getGradient() const;
		
		inline double getLength() const;
		inline float getLengthFloat() const;
		
		/**
		 * Swaps the first and the second point
		 **/
		void swapPoints();
		
		Point getMidpoint() const;
		
		//void rotate(const Point &center, int degree);
		
		inline void move(int dx, int dy);
	
	protected:
		inline void draw() const;
	};

	typedef Edge Line; // handy naming convention
}

#endif
