#ifndef PARACHUTE_H_
#define PARACHUTE_H_

#include "Drawable.hpp"
#include "Point.hpp"
#include "Edge.hpp"
#include "Color.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Parachute : public Drawable {
	private:
		Point kepala1, kepala2, kepala3, kepala4;
		Point leherAtas,anchor;
		Point tanganKiri,tanganKanan;
		Point kakiKiri,kakiKanan;
		Point kiriParasut, kananParasut;
		float weight;
	public:
		Parachute(int x, int y);
		~Parachute();
		void animate();
		void rotate(int degree);
		void scale(int scale);
		void move(int dx, int dy);
	
	protected:
		void draw() const;
	};

}

#endif

