#ifndef POLYGON_H_
#define POLYGON_H_

#include "ShapeFillable.hpp"

#include <vector>
#include <iostream>

namespace Graphics {
	
	class Polygon : public ShapeFillable {
	public:
		class Builder {
		public:
			Builder();
			Builder(int nPoints);
			~Builder();
			
			Builder& point(const Point&);
			Builder& point(int x, int y);
			Builder& baseColor(const Color& color);
			Builder& baseColor(Pixel pixel);
			Builder& weight(float weight);
			Builder& translate(int dx, int dy);
			
			Polygon build() const;
			Polygon* buildNew() const;
		private:
			std::vector<Point> args;
			Color mBaseColor;
			float mWeight;
		};
		
	public:
		Polygon(const std::vector<Point>& args);
		Polygon(const std::vector<Point>& args, 
				const Color& baseColor,
				float weight);
		Polygon(const Polygon& polygon);
		~Polygon();
		
		bool operator==(const Polygon& rhs) const;
		
		friend std::ostream& operator<<(std::ostream&, const Polygon&);
	private:
		float weight;		
	};
	
	std::ostream& operator<<(std::ostream&, const Polygon&);
}
#endif
