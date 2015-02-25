#ifndef BALL_H_
#define BALL_H_

#include "Drawable.hpp"
#include "Point.hpp"
#include "Color.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Ball : public Drawable {
	private:
		Point pusat;
		int moveX;
		int moveY;
		int minY,maxY;
		bool balik;
		int r;
	public:
		Ball(int x, int y, int r);
		~Ball();
		void animate();
		void rotate(int degree);
		void scale(int scale);
		void move(int dx, int dy);
	
	protected:
		void draw() const;
		void drawBall() const;
	};

}

#endif
