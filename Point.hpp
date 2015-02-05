#ifndef POINT_H_
#define POINT_H_

#include "Drawable.hpp"

namespace Graphics {
	class Point : public Drawable {
	protected:
		int x;
		int y;
	public:
		Point(int x = 0, int y = 0);
		Point(const Point&);
		
		Point& operator=(const Point&);
		
		friend bool operator==(const Point&, const Point&);
		
		friend Point operator+(const Point&, const Point&);
		friend Point operator-(const Point&, const Point&);
		
		friend Point& operator+=(const Point&, const Point&);
		friend Point& operator-=(const Point&, const Point&);
		
		void setX(int x);
		void setY(int y);
		
		int getX() const;
		int getY() const;
		
		int getQuadrant() const;
		
		static int quadrant(const Graphics::Point& point);
		
		inline void draw() const;
	};
};

#endif
