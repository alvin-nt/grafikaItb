#ifndef PETA_H_
#define PETA_H_

#include "Drawable.hpp"
#include "Point.hpp"
#include "Edge.hpp"
#include "Color.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Peta : public Drawable {
	private:
		Point sumatera1,sumatera2,sumatera3,sumatera4,sumatera5,sumatera6,sumatera7,sumatera8;
		Point sumatera9,sumatera10,sumatera11,sumatera12,sumatera13,sumatera14,sumatera15,sumatera16,sumatera17;
		Point kalimantan1,kalimantan2,kalimantan3,kalimantan4,kalimantan5,kalimantan6,kalimantan7,kalimantan8;
		Point kalimantan9,kalimantan10,kalimantan11,kalimantan12,kalimantan13,kalimantan14,kalimantan15,kalimantan16,kalimantan17;
		Point kalimantan18,kalimantan19,kalimantan20,kalimantan21,kalimantan22,kalimantan23,kalimantan24,kalimantan25,kalimantan26;
		Point kalimantan27,kalimantan28,kalimantan29,kalimantan30,kalimantan31;//,kalimantan32,kalimantan33,kalimantan34,kalimantan35;
		float weight;
	public:
		Peta(int x, int y);
		~Peta();
		void move(int dx,int dy);
	
	protected:
		void draw() const;
	};

}

#endif

