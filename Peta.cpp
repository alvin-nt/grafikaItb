#include "Peta.hpp"
#include <cmath>
using namespace Graphics;
Peta::Peta(int x,int y)
:sumatera1(x+27,y+158,Color::WHITE),sumatera2(x+87,y+162,Color::WHITE),sumatera3(x+108,y+197,Color::WHITE),sumatera4(x+144,y+220,Color::WHITE),
sumatera5(x+162,y+241,Color::WHITE),sumatera6(x+187,y+245,Color::WHITE),sumatera7(x+236,y+287,Color::WHITE),sumatera8(x+232,y+314,Color::WHITE),
sumatera9(x+255,y+322,Color::WHITE),sumatera10(x+266,y+350,Color::WHITE),sumatera11(x+288,y+370,Color::WHITE),sumatera12(x+285,y+434,Color::WHITE),
sumatera13(x+256,y+443,Color::WHITE),sumatera14(x+200,y+390,Color::WHITE),sumatera15(x+123,y+293,Color::WHITE),sumatera16(x+115,y+253,Color::WHITE),
sumatera17(x+90,y+241,Color::WHITE),
kalimantan1(x+374,y+245,Color::WHITE),kalimantan2(x+403,y+274,Color::WHITE),kalimantan3(x+420,y+267,Color::WHITE),kalimantan4(x+437,y+267,Color::WHITE),
kalimantan5(x+445,y+256,Color::WHITE),kalimantan6(x+474,y+265,Color::WHITE),kalimantan7(x+485,y+258,Color::WHITE),kalimantan8(x+499,y+260,Color::WHITE),
kalimantan9(x+500,y+239,Color::WHITE),kalimantan10(x+511,y+231,Color::WHITE),kalimantan11(x+514,y+220,Color::WHITE),kalimantan12(x+524,y+198,Color::WHITE),
kalimantan13(x+526,y+186,Color::WHITE),kalimantan14(x+566,y+188,Color::WHITE),kalimantan15(x+579,y+203,Color::WHITE),kalimantan16(x+572,y+214,Color::WHITE),
kalimantan17(x+586,y+235,Color::WHITE),kalimantan18(x+582,y+247,Color::WHITE),kalimantan19(x+612,y+271,Color::WHITE),kalimantan20(x+570,y+280,Color::WHITE),
kalimantan21(x+575,y+312,Color::WHITE),kalimantan22(x+548,y+341,Color::WHITE),kalimantan23(x+540,y+382,Color::WHITE),kalimantan24(x+543,y+396,Color::WHITE),
kalimantan25(x+463,y+374,Color::WHITE),kalimantan26(x+434,y+382,Color::WHITE),kalimantan27(x+436,y+370,Color::WHITE),kalimantan28(x+391,y+364,Color::WHITE),
kalimantan29(x+387,y+324,Color::WHITE),kalimantan30(x+364,y+296,Color::WHITE),kalimantan31(x+367,y+261,Color::WHITE)//,kalimantan32(x+115,y+253,Color::WHITE),
//kalimantan33(x+90,y+241,Color::WHITE)

{
	weight = 0.5f;
}

Peta::~Peta(){
	
}

void Peta::move(int dx, int dy){
	//TBD
}

void Peta::draw() const{
	Edge e1(sumatera1,sumatera2,weight);
	Edge e2(sumatera2,sumatera3,weight);
	Edge e3(sumatera3,sumatera4,weight);
	Edge e4(sumatera4,sumatera5,weight);
	Edge e5(sumatera5,sumatera6,weight);
	Edge e6(sumatera6,sumatera7,weight);
	Edge e7(sumatera7,sumatera8,weight);
	Edge e8(sumatera8,sumatera9,weight);
	Edge e9(sumatera9,sumatera10,weight);
	Edge e10(sumatera10,sumatera11,weight);
	Edge e11(sumatera11,sumatera12,weight);
	Edge e12(sumatera12,sumatera13,weight);
	Edge e13(sumatera13,sumatera14,weight);
	Edge e14(sumatera14,sumatera15,weight);
	Edge e15(sumatera15,sumatera16,weight);
	Edge e16(sumatera16,sumatera17,weight);
	Edge e17(sumatera1,sumatera17,weight);
	
	Edge e18(kalimantan1,kalimantan2,weight);
	Edge e19(kalimantan2,kalimantan3,weight);
	Edge e20(kalimantan3,kalimantan4,weight);
	Edge e21(kalimantan4,kalimantan5,weight);
	Edge e22(kalimantan5,kalimantan6,weight);
	Edge e23(kalimantan6,kalimantan7,weight);
	Edge e24(kalimantan7,kalimantan8,weight);
	Edge e25(kalimantan8,kalimantan9,weight);
	Edge e26(kalimantan9,kalimantan10,weight);
	Edge e27(kalimantan10,kalimantan11,weight);
	Edge e28(kalimantan11,kalimantan12,weight);
	Edge e29(kalimantan12,kalimantan13,weight);
	Edge e30(kalimantan13,kalimantan14,weight);
	Edge e31(kalimantan14,kalimantan15,weight);
	Edge e32(kalimantan15,kalimantan16,weight);
	Edge e33(kalimantan16,kalimantan17,weight);
	Edge e34(kalimantan17,kalimantan18,weight);
	Edge e35(kalimantan18,kalimantan19,weight);
	Edge e36(kalimantan19,kalimantan20,weight);
	Edge e37(kalimantan20,kalimantan21,weight);
	Edge e38(kalimantan21,kalimantan22,weight);
	Edge e39(kalimantan22,kalimantan23,weight);
	Edge e40(kalimantan23,kalimantan24,weight);
	Edge e41(kalimantan24,kalimantan25,weight);
	Edge e42(kalimantan25,kalimantan26,weight);
	Edge e43(kalimantan26,kalimantan27,weight);
	Edge e44(kalimantan27,kalimantan28,weight);
	Edge e45(kalimantan28,kalimantan29,weight);
	Edge e46(kalimantan29,kalimantan30,weight);
	Edge e47(kalimantan30,kalimantan31,weight);
	Edge e48(kalimantan31,kalimantan1,weight);


	
	e1.draw();
	e2.draw();
	e3.draw();
	e4.draw();
	e5.draw();
	e6.draw();
	e7.draw();
	e8.draw();
	e9.draw();
	e10.draw();
	e11.draw();
	e12.draw();
	e13.draw();
	e14.draw();
	e15.draw();
	e16.draw();
	e17.draw();
	e18.draw();
	e19.draw();
	e20.draw();
	e21.draw();
	e22.draw();
	e23.draw();
	e24.draw();
	e25.draw();
	e26.draw();
	e27.draw();
	e28.draw();
	e29.draw();
	e30.draw();
	e31.draw();
	e32.draw();
	e33.draw();
	e34.draw();
	e35.draw();
	e36.draw();
	e37.draw();
	e38.draw();
	e39.draw();
	e40.draw();
	e41.draw();
	e42.draw();
	e43.draw();
	e44.draw();
	e45.draw();
	e46.draw();
	e47.draw();
	e48.draw();

}
