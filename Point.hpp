#ifndef POINT_H_
#define POINT_H_

#include "Drawable.hpp"
#include "Color.hpp"

namespace Graphics {
	class Point : public Drawable {
	protected:
		int x;
		int y;
		
		Color color;
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
		
		const Color& getColor() const;
		
		void setColor(const Color &color);
		
		inline void draw() const;
		
		inline void move(int dx, int dy) const;
	};
};

#endif
