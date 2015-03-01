#include "Peta.hpp"
#include <cmath>
using namespace Graphics;
Peta::Peta(int x,int y)
:sumatera1(x+20,y+114,Color::WHITE),sumatera2(x+64,y+117,Color::WHITE),sumatera3(x+74,y+140,Color::WHITE),sumatera4(x+110,y+160,Color::WHITE),
sumatera5(x+143,y+183,Color::WHITE),sumatera6(x+168,y+206,Color::WHITE),sumatera7(x+163,y+227,Color::WHITE),sumatera8(x+183,y+229,Color::WHITE),
sumatera9(x+190,y+250,Color::WHITE),sumatera10(x+209,y+268,Color::WHITE),sumatera11(x+197,y+285,Color::WHITE),sumatera12(x+209,y+309,Color::WHITE),
sumatera13(x+185,y+319,Color::WHITE),sumatera14(x+170,y+304,Color::WHITE),sumatera15(x+146,y+291,Color::WHITE),sumatera16(x+98,y+212,Color::WHITE),
sumatera17(x+87,y+209,Color::WHITE),sumatera18(x+82,y+182,Color::WHITE),sumatera19(x+62,y+173,Color::WHITE),sumatera20(x+50,y+147,Color::WHITE),
sumatera21(x+26,y+133,Color::WHITE),
kalimantan1(x+268,y+175,Color::WHITE),kalimantan2(x+286,y+196,Color::WHITE),kalimantan3(x+301,y+191,Color::WHITE),kalimantan4(x+313,y+194,Color::WHITE),
kalimantan5(x+321,y+184,Color::WHITE),kalimantan6(x+342,y+191,Color::WHITE),kalimantan7(x+356,y+186,Color::WHITE),kalimantan8(x+361,y+173,Color::WHITE),
kalimantan9(x+376,y+157,Color::WHITE),kalimantan10(x+380,y+137,Color::WHITE),kalimantan11(x+409,y+136,Color::WHITE),kalimantan12(x+416,y+150,Color::WHITE),
kalimantan13(x+409,y+156,Color::WHITE),kalimantan14(x+422,y+172,Color::WHITE),kalimantan15(x+420,y+183,Color::WHITE),kalimantan16(x+439,y+196,Color::WHITE),
kalimantan17(x+417,y+202,Color::WHITE),kalimantan18(x+416,y+224,Color::WHITE),kalimantan19(x+390,y+245,Color::WHITE),kalimantan20(x+390,y+280,Color::WHITE),
kalimantan21(x+362,y+286,Color::WHITE),kalimantan22(x+336,y+267,Color::WHITE),kalimantan23(x+313,y+276,Color::WHITE),kalimantan24(x+285,y+264,Color::WHITE),
kalimantan25(x+279,y+237,Color::WHITE),kalimantan26(x+267,y+231,Color::WHITE),kalimantan27(x+257,y+199,Color::WHITE),
jawa1(x+209,y+320,Color::WHITE),jawa2(x+252,y+321,Color::WHITE),jawa3(x+250,y+325,Color::WHITE),jawa4(x+255,y+332,Color::WHITE),
jawa5(x+284,y+325,Color::WHITE),jawa6(x+293,y+327,Color::WHITE),jawa7(x+325,y+327,Color::WHITE),jawa8(x+351,y+339,Color::WHITE),
jawa9(x+347,y+341,Color::WHITE),jawa10(x+325,y+345,Color::WHITE),jawa11(x+334,y+352,Color::WHITE),jawa12(x+350,y+348,Color::WHITE),
jawa13(x+361,y+360,Color::WHITE),jawa14(x+375,y+360,Color::WHITE),jawa15(x+371,y+370,Color::WHITE),jawa16(x+361,y+365,Color::WHITE),
jawa17(x+357,y+371,Color::WHITE),jawa18(x+330,y+365,Color::WHITE),jawa19(x+289,y+362,Color::WHITE),jawa20(x+259,y+351,Color::WHITE),
jawa21(x+239,y+355,Color::WHITE),jawa22(x+234,y+349,Color::WHITE),jawa23(x+212,y+345,Color::WHITE),jawa24(x+215,y+341,Color::WHITE),
jawa25(x+197,y+337,Color::WHITE)
{
	weight = 0.5f;
}

Peta::~Peta(){
	
}

void Peta::move(int dx, int dy){
	//TBD
}

void Peta::draw() const{
	Edge esum1(sumatera1,sumatera2,weight);
	Edge esum2(sumatera2,sumatera3,weight);
	Edge esum3(sumatera3,sumatera4,weight);
	Edge esum4(sumatera4,sumatera5,weight);
	Edge esum5(sumatera5,sumatera6,weight);
	Edge esum6(sumatera6,sumatera7,weight);
	Edge esum7(sumatera7,sumatera8,weight);
	Edge esum8(sumatera8,sumatera9,weight);
	Edge esum9(sumatera9,sumatera10,weight);
	Edge esum10(sumatera10,sumatera11,weight);
	Edge esum11(sumatera11,sumatera12,weight);
	Edge esum12(sumatera12,sumatera13,weight);
	Edge esum13(sumatera13,sumatera14,weight);
	Edge esum14(sumatera14,sumatera15,weight);
	Edge esum15(sumatera15,sumatera16,weight);
	Edge esum16(sumatera16,sumatera17,weight);
	Edge esum17(sumatera17,sumatera18,weight);
	Edge esum18(sumatera18,sumatera19,weight);
	Edge esum19(sumatera19,sumatera20,weight);
	Edge esum20(sumatera20,sumatera21,weight);
	Edge esum21(sumatera21,sumatera1,weight);
	
	Edge ekal1(kalimantan1,kalimantan2,weight);
	Edge ekal2(kalimantan2,kalimantan3,weight);
	Edge ekal3(kalimantan3,kalimantan4,weight);
	Edge ekal4(kalimantan4,kalimantan5,weight);
	Edge ekal5(kalimantan5,kalimantan6,weight);
	Edge ekal6(kalimantan6,kalimantan7,weight);
	Edge ekal7(kalimantan7,kalimantan8,weight);
	Edge ekal8(kalimantan8,kalimantan9,weight);
	Edge ekal9(kalimantan9,kalimantan10,weight);
	Edge ekal10(kalimantan10,kalimantan11,weight);
	Edge ekal11(kalimantan11,kalimantan12,weight);
	Edge ekal12(kalimantan12,kalimantan13,weight);
	Edge ekal13(kalimantan13,kalimantan14,weight);
	Edge ekal14(kalimantan14,kalimantan15,weight);
	Edge ekal15(kalimantan15,kalimantan16,weight);
	Edge ekal16(kalimantan16,kalimantan17,weight);
	Edge ekal17(kalimantan17,kalimantan18,weight);
	Edge ekal18(kalimantan18,kalimantan19,weight);
	Edge ekal19(kalimantan19,kalimantan20,weight);
	Edge ekal20(kalimantan20,kalimantan21,weight);
	Edge ekal21(kalimantan21,kalimantan22,weight);
	Edge ekal22(kalimantan22,kalimantan23,weight);
	Edge ekal23(kalimantan23,kalimantan24,weight);
	Edge ekal24(kalimantan24,kalimantan25,weight);
	Edge ekal25(kalimantan25,kalimantan26,weight);
	Edge ekal26(kalimantan26,kalimantan27,weight);
	Edge ekal27(kalimantan27,kalimantan1,weight);

	Edge ejaw1(jawa1,jawa2,weight);
	Edge ejaw2(jawa2,jawa3,weight);
	Edge ejaw3(jawa3,jawa4,weight);
	Edge ejaw4(jawa4,jawa5,weight);
	Edge ejaw5(jawa5,jawa6,weight);
	Edge ejaw6(jawa6,jawa7,weight);
	Edge ejaw7(jawa7,jawa8,weight);
	Edge ejaw8(jawa8,jawa9,weight);
	Edge ejaw9(jawa9,jawa10,weight);
	Edge ejaw10(jawa10,jawa11,weight);
	Edge ejaw11(jawa11,jawa12,weight);
	Edge ejaw12(jawa12,jawa13,weight);
	Edge ejaw13(jawa13,jawa14,weight);
	Edge ejaw14(jawa14,jawa15,weight);
	Edge ejaw15(jawa15,jawa16,weight);
	Edge ejaw16(jawa16,jawa17,weight);
	Edge ejaw17(jawa17,jawa18,weight);
	Edge ejaw18(jawa18,jawa19,weight);
	Edge ejaw19(jawa19,jawa20,weight);
	Edge ejaw20(jawa20,jawa21,weight);
	Edge ejaw21(jawa21,jawa22,weight);
	Edge ejaw22(jawa22,jawa23,weight);
	Edge ejaw23(jawa23,jawa24,weight);
	Edge ejaw24(jawa24,jawa25,weight);
	Edge ejaw25(jawa25,jawa1,weight);

	
	esum1.draw();
	esum2.draw();
	esum3.draw();
	esum4.draw();
	esum5.draw();
	esum6.draw();
	esum7.draw();
	esum8.draw();
	esum9.draw();
	esum10.draw();
	esum11.draw();
	esum12.draw();
	esum13.draw();
	esum14.draw();
	esum15.draw();
	esum16.draw();
	esum17.draw();
	esum18.draw();
	esum19.draw();
	esum20.draw();
	esum21.draw();
	
	ekal1.draw();
	ekal2.draw();
	ekal3.draw();
	ekal4.draw();
	ekal5.draw();
	ekal6.draw();
	ekal7.draw();
	ekal8.draw();
	ekal9.draw();
	ekal10.draw();
	ekal11.draw();
	ekal12.draw();
	ekal13.draw();
	ekal14.draw();
	ekal15.draw();
	ekal16.draw();
	ekal17.draw();
	ekal18.draw();
	ekal19.draw();
	ekal20.draw();
	ekal21.draw();
	ekal22.draw();
	ekal23.draw();
	ekal24.draw();
	ekal25.draw();
	ekal26.draw();
	ekal27.draw();
	
	ejaw1.draw();
	ejaw2.draw();
	ejaw3.draw();
	ejaw4.draw();
	ejaw5.draw();
	ejaw6.draw();
	ejaw7.draw();
	ejaw8.draw();
	ejaw9.draw();
	ejaw10.draw();
	ejaw11.draw();
	ejaw12.draw();
	ejaw13.draw();
	ejaw14.draw();
	ejaw15.draw();
	ejaw16.draw();
	ejaw17.draw();
	ejaw18.draw();
	ejaw19.draw();
	ejaw20.draw();
	ejaw21.draw();
	ejaw22.draw();
	ejaw23.draw();
	ejaw24.draw();
	ejaw25.draw();

}
