#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "ShapeFillable.hpp"
#include "Types.hpp"
#include "Color.hpp"

namespace Graphics {
	class Triangle;
}

class Triangle : public ShapeFillable {
protected:
	Point p1, p2, p3;

	Color c;
public:
	Triangle(const Point&, const Point&, const Point&, const Color& color);
	Triangle(int x1, int y1, int x2, int y2, 
				int x3, int y3, const Color& color);
	
	Triangle& operator=(const Triangle&);
	
	friend bool operator==(const Triangle&, const Triangle&);
	
	const Color &getColor() const;
	void setColor(const Color& color);
	
	inline void draw(bool fill) const;
	
	inline void move(int dx, int dy);

protected:
	inline void drawFill(const Rasterizer&);
	
	inline void drawOutline(const Rasterizer&);
};

#endif
