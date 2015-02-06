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
		Edge(int x1, int y1, const Color& c1
			int x2, int y2, const Color& c2, float weight);
		Edge(const Edge&);
		~Edge();
		
		Edge& operator=(const Edge&);
		
		friend bool operator==(const Edge&, const Edge&);
		
		const Point& getPoint1() const;
		void setPoint1(const Point&);
		
		const Point& getPoint2() const;
		void setPoint2(const Point&);
		
		float getWeight() const;
		void setWeight(float weight);
		
		inline int getDeltaX() const;
		inline int getDeltaY() const;
		
		inline double getGradient() const;
		
		inline double getLength() const;
		inline float getLengthFloat() const;
		
		void swapPoints();
		
		Point getMidpoint() const;
		
		void rotate(const Point &center, int degree);
		
		inline void draw() const;
		
		inline void move(int dx, int dy);
	};

	typedef Edge Line; // handy naming convention
}

#endif
