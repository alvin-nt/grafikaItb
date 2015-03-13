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
		
		void rotate(const Point& base, float degree);
		
		void scale(const Point& base, float ds);
		
		void scale(const Point& base, float sx, float sy);
		
		/**
		 * Moves a point.
		 * 
		 * NOTE: this method assumes that the point uses all-positive coordinate system.
		 * Therefore, if other coordinate system is used, modify this method as needed
		 * 
		 * @param point the point that is going to be moved
		 * @param dx horizontal translation
		 * @param dy vertical translation
		 **/
		static void move(Point& point, int dx, int dy);
		
		/**
		 * Rotates a point.
		 * 
		 * NOTE: this method assumes that the point uses all-positive coordinate system.
		 * Therefore, if other coordinate system is used, modify this method as needed
		 * 
		 * @param base the point, acting as rotation reference
		 * @param target the point that is going to be rotated
		 * @param degree degree of rotation
		 **/
		static void rotate(const Point& base, Point& target, float degree);
		
		/**
		 * Scales a point.
		 * 
		 * NOTE: this method assumes that the point uses all-positive coordinate system.
		 * Therefore, if other coordinate system is used, modify this method as needed
		 * 
		 * @param base the point, acting as scaling reference
		 * @param target the point that is going to be scaled
		 * @param sx the scale of horizontal point
		 * @param sy the scale of vertical point
		 **/
		static void scale(const Point& base, Point& target, float sx, float sy);
		
		/**
		 * Checks whether a point is movable.
		 * 
		 * NOTE: this method assumes that the point uses all-positive coordinate system.
		 * Therefore, if other coordinate system is used, modify this method as needed
		 * 
		 * @param point the point that is going to be moved
		 * @param dx horizontal translation
		 * @param dy vertical translation
		 **/
		static bool isMovable(const Point& point, int dx, int dy);
		
		/**
		 * Rotates a point.
		 * 
		 * NOTE: this method assumes that the point uses all-positive coordinate system.
		 * Therefore, if other coordinate system is used, modify this method as needed
		 * 
		 * @param base the point, acting as rotation reference
		 * @param target the point that is going to be rotated
		 * @param degree degree of rotation
		 **/
		static bool isRotateable(const Point& base, const Point& target, float degree);
		
		/**
		 * Checks whether a point is scaleable or not
		 * 
		 * NOTE: this method assumes that the point uses all-positive coordinate system.
		 * Therefore, if other coordinate system is used, modify this method as needed
		 * 
		 * @param base the point, acting as scaling reference
		 * @param target the point that is going to be scaled
		 * @param sx the scale of horizontal point
		 * @param sy the scale of vertical point
		 **/
		static bool isScaleable(const Point& base, const Point& target, float sx, float sy);
	protected:
		void draw() const;		
	};
};

#endif
