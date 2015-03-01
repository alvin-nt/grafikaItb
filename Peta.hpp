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
		Point ntt1,ntt2,ntt3,ntt4,ntt5,ntt6,ntt7,ntt8;
		Point ntt9,ntt10,ntt11;
		Point sulawesi1,sulawesi2,sulawesi3,sulawesi4,sulawesi5,sulawesi6,sulawesi7,sulawesi8;
		Point sulawesi9,sulawesi10,sulawesi11,sulawesi12,sulawesi13,sulawesi14,sulawesi15,sulawesi16,sulawesi17;
		Point sulawesi18,sulawesi19,sulawesi20,sulawesi21,sulawesi22,sulawesi23,sulawesi24,sulawesi25,sulawesi26;
		Point sulawesi27,sulawesi28,sulawesi29,sulawesi30,sulawesi31;
		Point papua1,papua2,papua3,papua4,papua5,papua6,papua7,papua8;
		Point papua9,papua10,papua11,papua12,papua13,papua14,papua15,papua16,papua17;
		Point papua18,papua19,papua20,papua21,papua22,papua23,papua24,papua25,papua26;
		Point papua27,papX1,papX2,papX3,papX4;
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

