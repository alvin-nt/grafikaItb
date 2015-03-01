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
		Point sumatera9,sumatera10,sumatera11,sumatera12,sumatera13,sumatera14,sumatera15,sumatera16;
		Point sumatera17,sumatera18,sumatera19,sumatera20,sumatera21;
		Point sumatera25,sumatera26,sumatera27,sumatera28,sumatera29,sumatera30,sumatera31,sumatera32;
		Point kalimantan1,kalimantan2,kalimantan3,kalimantan4,kalimantan5,kalimantan6,kalimantan7,kalimantan8;
		Point kalimantan9,kalimantan10,kalimantan11,kalimantan12,kalimantan13,kalimantan14,kalimantan15,kalimantan16,kalimantan17;
		Point kalimantan18,kalimantan19,kalimantan20,kalimantan21,kalimantan22,kalimantan23,kalimantan24,kalimantan25,kalimantan26;
		Point kalimantan27;
		Point jawa1,jawa2,jawa3,jawa4,jawa5,jawa6,jawa7,jawa8;
		Point jawa9,jawa10,jawa11,jawa12,jawa13,jawa14,jawa15,jawa16,jawa17;
		Point jawa18,jawa19,jawa20,jawa21,jawa22,jawa23,jawa24,jawa25;
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

