#ifndef EDGE_H_
#define EDGE_H_

#include "Shape.hpp"
#include "Point.hpp"
#include "Color.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Edge : public Shape {
	private:
		Point p1;
		
		Point p2;
		
		Color c;
		
		float weight;
	public:
		Edge(const Point& p1, const Point& p2, const Color& c, float weight = 1.0f);
		Edge(int x1, int y1, int x2, int y2, const Color& c, float weight);
		Edge(const Edge&);
		~Edge();
		
		Edge& operator=(const Edge&);
		
		friend bool operator==(const Edge&, const Edge&);
		
		const Point& getPoint1() const;
		void setPoint1(const Point&);
		
		const Point& getPoint2() const;
		void setPoint2(const Point&);
		
		const Color& getColor() const;
		void setColor(const Color&);
		
		float getWeight() const;
		void setWeight(float weight);
		
		double getGradient() const;
		double getLength() const;
		
		Point getMidpoint() const;
		
		void rotate(const Point &center, int degree);
		
		void sortPoints();
		
		inline void draw() const;
		
		inline void move(int dx, int dy);
	};

	typedef Edge Line; // handy naming convention
}

#endif
