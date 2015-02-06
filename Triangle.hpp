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
public:
	Triangle(const Point&, const Point&, const Point&);
	Triangle(int x1, int y1, const Color& color1,
				int x2, int y2, const Color& color2,
				int x3, int y3, const Color& color3);
	
	Triangle& operator=(const Triangle&);
	
	friend bool operator==(const Triangle&, const Triangle&);
	
	const Color &getColor() const;
	void setColor(const Color& color);
	
	inline void draw(bool fill) const;
	
	inline void move(int dx, int dy);

protected:
	inline void drawFill() const;
	
	inline void drawOutline() const;
};

#endif
