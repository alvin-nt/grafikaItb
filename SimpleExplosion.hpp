#ifndef SIMPLE_EXPLOSION_H_
#define SIMPLE_EXPLOSION_H_

#include "TemporaryDrawable.hpp"
#include "Color.hpp"
#include "Edge.hpp"

#include <vector>

namespace Graphics {
	/**
	 * Simple, animated explosion
	 **/
	class SimpleExplosion : public TemporaryDrawable {
	private:
		int sparkCount; // number of sparks
		int radiusOffset; // radius from the initial Point
		std::vector<Edge> sparks; // place to store the sparks, initialized at construction
		
		Point initialPoint; // gotta implement my own anchor~
	public:
		/**
		 * Default constructor
		 * 
		 * @param initialPoint the starting point of the explosion
		 * @param sparks number of sparks, divisible by 2
		 * @param steps number of drawing steps (frames), divisible by 2
		 * @param radius the radius of the initial spark from the initial point
		 **/
		SimpleExplosion(const Point& initialPoint, int sparks = 8, int steps = 100, int radius = 5);
		SimpleExplosion(const SimpleExplosion&);
		
		SimpleExplosion& operator=(const SimpleExplosion&);
		
		int getSparkCount() const;
		
		const Point& getInitialPoint();
		
		void setInitialPoint(const Point&);
		void setInitialPoint(int x, int y);
		
		void setStartColor(const Color&);
		void setEndColor(const Color&);
		
	protected:
		void draw();
	};
}

#endif
