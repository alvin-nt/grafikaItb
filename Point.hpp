#ifndef POINT_H_
#define POINT_H_

#include "Drawable.hpp"
#include "Color.hpp"

namespace Graphics {
	class Point : public Drawable {
	friend class Rasterizer;
	friend class Parachute;
	friend class Ball;
	friend class ViewPort;
	protected:
		int x;
		int y;
		
		Color color;
	public:
		Point(int x = 0, int y = 0, const Color& color = Color::BLACK);
		Point(const Point&);
		~Point();
		
		Point& operator=(const Point&);
		
		friend bool operator!=(const Point&, const Point&);
		friend bool operator==(const Point&, const Point&);
		
		friend Point operator+(const Point&, const Point&);
		friend Point operator-(const Point&, const Point&);
		
		friend Point& operator+=(Point&, const Point&);
		friend Point& operator-=(Point&, const Point&);
		
		void setX(int x);
		void setY(int y);
		
		int getX() const;
		int getY() const;
		
		const Color& getColor() const;
		void setColor(const Color &color);
		
		void move(int dx, int dy);
	protected:
		void draw() const;		
	};
};

#endif
