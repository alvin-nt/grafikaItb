#ifndef SQUARE_H_
#define SQUARE_H_

#include "ShapeFillable.hpp"
#include "Point.hpp"
#include "Edge.hpp"

namespace Graphics {

	class Square : public ShapeFillable {
		private:
			Point p1, p2, p3, p4, anchor, center;
			float tetha;
			int length;

		protected:
			void drawFill() const;
			void drawOutline() const;

		public:
			Square(const Point&, int Length, float tetha); // pake lenght, jadi titiknya cuman 2 aja
			Square(int x1, int y1, const Color& color1, int Length, float tetha);
			Square(const Square&);
			Square& operator=(const Square&);
			~Square();
			friend bool operator==(const Square&, const Square&);
			friend bool operator!=(const Square&, const Square&);

			const Point& getPoint1() const;
			const Point& getPoint2() const;
			const Point& getPoint3() const;
			const Point& getPoint4() const;
			const Point& getAnchor() const;
			const Point& getCenter() const;

			void setPoint1(const Point&);
			void setPoint2(const Point&);
			void setPoint3(const Point&);
			void setPoint4(const Point&);
			void setAnchor(const Point&);

			int getLength();


			//const &Color getColor() const;
			//void setColor(const Color& color);
			void move(int dx, int dy);
	};
}
#endif
