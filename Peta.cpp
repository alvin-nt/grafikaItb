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
jawa25(x+197,y+337,Color::WHITE),
ntt1(x+389,y+362,Color::WHITE),ntt2(x+409,y+364,Color::WHITE),ntt3(x+420,y+366,Color::WHITE),ntt4(x+411,y+362,Color::WHITE),
ntt5(x+418,y+357,Color::WHITE),ntt6(x+437,y+363,Color::WHITE),ntt7(x+440,y+370,Color::WHITE),ntt8(x+420,y+375,Color::WHITE),
ntt9(x+400,y+370,Color::WHITE),ntt10(x+381,y+369,Color::WHITE),ntt11(x+387,y+370,Color::WHITE),
sulawesi1(x+470,y+192,Color::WHITE),sulawesi2(x+509,y+195,Color::WHITE),sulawesi3(x+526,y+197,Color::WHITE),sulawesi4(x+539,y+182,Color::WHITE),
sulawesi5(x+548,y+186,Color::WHITE),sulawesi6(x+530,y+209,Color::WHITE),sulawesi7(x+463,y+209,Color::WHITE),sulawesi8(x+459,y+225,Color::WHITE),
sulawesi9(x+466,y+234,Color::WHITE),sulawesi10(x+483,y+226,Color::WHITE),sulawesi11(x+511,y+224,Color::WHITE),sulawesi12(x+518,y+229,Color::WHITE),
sulawesi13(x+517,y+241,Color::WHITE),sulawesi14(x+500,y+240,Color::WHITE),sulawesi15(x+486,y+252,Color::WHITE),sulawesi16(x+503,y+286,Color::WHITE),
sulawesi17(x+512,y+307,Color::WHITE),sulawesi18(x+502,y+316,Color::WHITE),sulawesi19(x+492,y+304,Color::WHITE),sulawesi20(x+470,y+280,Color::WHITE),
sulawesi21(x+473,y+263,Color::WHITE),sulawesi22(x+462,y+266,Color::WHITE),sulawesi23(x+465,y+311,Color::WHITE),sulawesi24(x+447,y+316,Color::WHITE),
sulawesi25(x+441,y+309,Color::WHITE),sulawesi26(x+443,y+272,Color::WHITE),sulawesi27(x+433,y+276,Color::WHITE),sulawesi28(x+432,y+264,Color::WHITE),
sulawesi29(x+443,y+237,Color::WHITE),sulawesi30(x+449,y+226,Color::WHITE),sulawesi31(x+450,y+210,Color::WHITE),
papua1(x+636,y+226,Color::WHITE),papua2(x+650,y+231,Color::WHITE),papua3(x+671,y+217,Color::WHITE),papua4(x+700,y+224,Color::WHITE),
papua5(x+706,y+261,Color::WHITE),papua6(x+732,y+270,Color::WHITE),papua7(x+742,y+255,Color::WHITE),papua8(x+753,y+242,Color::WHITE),
papua9(x+770,y+239,Color::WHITE),papua10(x+824,y+260,Color::WHITE),papua11(x+822,y+376,Color::WHITE),papua12(x+802,y+362,Color::WHITE),
papua13(x+763,y+368,Color::WHITE),papua14(x+770,y+348,Color::WHITE),papua15(x+782,y+343,Color::WHITE),papua16(x+766,y+309,Color::WHITE),
papua17(x+726,y+293,Color::WHITE),papua18(x+695,y+279,Color::WHITE),papua19(x+683,y+292,Color::WHITE),papua20(x+675,y+286,Color::WHITE),
papua21(x+676,y+273,Color::WHITE),papua22(x+662,y+266,Color::WHITE),papua23(x+665,y+258,Color::WHITE),papua24(x+683,y+257,Color::WHITE),
papua25(x+658,y+251,Color::WHITE),papua26(x+659,y+242,Color::WHITE),papua27(x+636,y+235,Color::WHITE),
papX1(x+634,y+212,Color::WHITE),papX2(x+653,y+216,Color::WHITE),papX3(x+644,y+223,Color::WHITE),papX4(x+632,y+214,Color::WHITE),
kapal1(x+264,y+295,Color::BLUE),kapal2(x+284,y+300,Color::BLUE),kapal3(x+300,y+300,Color::BLUE),kapal4(x+280,y+295,Color::BLUE),
pesawat1(x+540,y+360,Color::BLUE),pesawat2(x+580,y+360,Color::BLUE),pesawat3(x+580,y+365,Color::BLUE),pesawat4(x+540,y+365,Color::BLUE),
pesawat5(x+535,y+348,Color::RED),pesawat6(x+565,y+378,Color::RED),pesawat7(x+565,y+348,Color::RED),pesawat8(x+535,y+378,Color::RED)
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

	Edge entt1(ntt1,ntt2,weight);
	Edge entt2(ntt2,ntt3,weight);
	Edge entt3(ntt3,ntt4,weight);
	Edge entt4(ntt4,ntt5,weight);
	Edge entt5(ntt5,ntt6,weight);
	Edge entt6(ntt6,ntt7,weight);
	Edge entt7(ntt7,ntt8,weight);
	Edge entt8(ntt8,ntt9,weight);
	Edge entt9(ntt9,ntt10,weight);
	Edge entt10(ntt10,ntt11,weight);
	Edge entt11(ntt11,ntt1,weight);
	
	Edge esul1(sulawesi1,sulawesi2,weight);
	Edge esul2(sulawesi2,sulawesi3,weight);
	Edge esul3(sulawesi3,sulawesi4,weight);
	Edge esul4(sulawesi4,sulawesi5,weight);
	Edge esul5(sulawesi5,sulawesi6,weight);
	Edge esul6(sulawesi6,sulawesi7,weight);
	Edge esul7(sulawesi7,sulawesi8,weight);
	Edge esul8(sulawesi8,sulawesi9,weight);
	Edge esul9(sulawesi9,sulawesi10,weight);
	Edge esul10(sulawesi10,sulawesi11,weight);
	Edge esul11(sulawesi11,sulawesi12,weight);
	Edge esul12(sulawesi12,sulawesi13,weight);
	Edge esul13(sulawesi13,sulawesi14,weight);
	Edge esul14(sulawesi14,sulawesi15,weight);
	Edge esul15(sulawesi15,sulawesi16,weight);
	Edge esul16(sulawesi16,sulawesi17,weight);
	Edge esul17(sulawesi17,sulawesi18,weight);
	Edge esul18(sulawesi18,sulawesi19,weight);
	Edge esul19(sulawesi19,sulawesi20,weight);
	Edge esul20(sulawesi20,sulawesi21,weight);
	Edge esul21(sulawesi21,sulawesi22,weight);
	Edge esul22(sulawesi22,sulawesi23,weight);
	Edge esul23(sulawesi23,sulawesi24,weight);
	Edge esul24(sulawesi24,sulawesi25,weight);
	Edge esul25(sulawesi25,sulawesi26,weight);
	Edge esul26(sulawesi26,sulawesi27,weight);
	Edge esul27(sulawesi27,sulawesi28,weight);
	Edge esul28(sulawesi28,sulawesi29,weight);
	Edge esul29(sulawesi29,sulawesi30,weight);
	Edge esul30(sulawesi30,sulawesi31,weight);
	Edge esul31(sulawesi31,sulawesi1,weight);

	Edge epap1(papua1,papua2,weight);
	Edge epap2(papua2,papua3,weight);
	Edge epap3(papua3,papua4,weight);
	Edge epap4(papua4,papua5,weight);
	Edge epap5(papua5,papua6,weight);
	Edge epap6(papua6,papua7,weight);
	Edge epap7(papua7,papua8,weight);
	Edge epap8(papua8,papua9,weight);
	Edge epap9(papua9,papua10,weight);
	Edge epap10(papua10,papua11,weight);
	Edge epap11(papua11,papua12,weight);
	Edge epap12(papua12,papua13,weight);
	Edge epap13(papua13,papua14,weight);
	Edge epap14(papua14,papua15,weight);
	Edge epap15(papua15,papua16,weight);
	Edge epap16(papua16,papua17,weight);
	Edge epap17(papua17,papua18,weight);
	Edge epap18(papua18,papua19,weight);
	Edge epap19(papua19,papua20,weight);
	Edge epap20(papua20,papua21,weight);
	Edge epap21(papua21,papua22,weight);
	Edge epap22(papua22,papua23,weight);
	Edge epap23(papua23,papua24,weight);
	Edge epap24(papua24,papua25,weight);
	Edge epap25(papua25,papua26,weight);
	Edge epap26(papua26,papua27,weight);
	Edge epap27(papua27,papua1,weight);

	Edge epapX1(papX1,papX2,weight);
	Edge epapX2(papX2,papX3,weight);
	Edge epapX3(papX3,papX4,weight);
	Edge epapX4(papX4,papX1,weight);
	
	Edge ekapal1(kapal1,kapal2,weight);
	Edge ekapal2(kapal2,kapal3,weight);
	Edge ekapal3(kapal3,kapal4,weight);
	Edge ekapal4(kapal4,kapal1,weight);

	Edge epesawat1(pesawat1,pesawat2,weight);
	Edge epesawat2(pesawat2,pesawat3,weight);
	Edge epesawat3(pesawat3,pesawat4,weight);
	Edge epesawat4(pesawat4,pesawat1,weight);
	Edge epesawat5(pesawat5,pesawat6,weight);
	Edge epesawat6(pesawat7,pesawat8,weight);
			
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
	
	entt1.draw();
	entt2.draw();
	entt3.draw();
	entt4.draw();
	entt5.draw();
	entt6.draw();
	entt7.draw();
	entt8.draw();
	entt9.draw();
	entt10.draw();
	entt11.draw();

	esul1.draw();
	esul2.draw();
	esul3.draw();
	esul4.draw();
	esul5.draw();
	esul6.draw();
	esul7.draw();
	esul8.draw();
	esul9.draw();
	esul10.draw();
	esul11.draw();
	esul12.draw();
	esul13.draw();
	esul14.draw();
	esul15.draw();
	esul16.draw();
	esul17.draw();
	esul18.draw();
	esul19.draw();
	esul20.draw();
	esul21.draw();
	esul22.draw();
	esul23.draw();
	esul24.draw();
	esul25.draw();
	esul26.draw();
	esul27.draw();
	esul28.draw();
	esul29.draw();
	esul30.draw();
	esul31.draw();
	
	epap1.draw();
	epap2.draw();
	epap3.draw();
	epap4.draw();
	epap5.draw();
	epap6.draw();
	epap7.draw();
	epap8.draw();
	epap9.draw();
	epap10.draw();
	epap11.draw();
	epap12.draw();
	epap13.draw();
	epap14.draw();
	epap15.draw();
	epap16.draw();
	epap17.draw();
	epap18.draw();
	epap19.draw();
	epap20.draw();
	epap21.draw();
	epap22.draw();
	epap23.draw();
	epap24.draw();
	epap25.draw();
	epap26.draw();
	epap27.draw();

	epapX1.draw();
	epapX2.draw();
	epapX3.draw();
	epapX4.draw();
	
	ekapal1.draw();
	ekapal2.draw();
	ekapal3.draw();
	ekapal4.draw();
	
	epesawat1.draw();
	epesawat2.draw();
	epesawat3.draw();
	epesawat4.draw();
	epesawat5.draw();
	epesawat6.draw();
}
