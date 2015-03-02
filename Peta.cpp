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
	pesawat1.move(dx,dy);
	pesawat2.move(dx,dy);
	pesawat3.move(dx,dy);
	pesawat4.move(dx,dy);
	pesawat5.move(dx,dy);
	pesawat6.move(dx,dy);
	pesawat7.move(dx,dy);
	pesawat8.move(dx,dy);
}

void Peta::setPoin(){
	e[0].setPoint(sumatera1,sumatera2,weight);
	  e[1].setPoint(sumatera2,sumatera3,weight);
	  e[2].setPoint(sumatera3,sumatera4,weight);
	  e[3].setPoint(sumatera4,sumatera5,weight);
	  e[4].setPoint(sumatera5,sumatera6,weight);
	  e[5].setPoint(sumatera6,sumatera7,weight);
	  e[6].setPoint(sumatera7,sumatera8,weight);
	  e[7].setPoint(sumatera8,sumatera9,weight);
	  e[8].setPoint(sumatera9,sumatera10,weight);
	  e[9].setPoint(sumatera10,sumatera11,weight);
	  e[10].setPoint(sumatera11,sumatera12,weight);
	  e[11].setPoint(sumatera12,sumatera13,weight);
	  e[12].setPoint(sumatera13,sumatera14,weight);
	  e[13].setPoint(sumatera14,sumatera15,weight);
	  e[14].setPoint(sumatera15,sumatera16,weight);
	  e[15].setPoint(sumatera16,sumatera17,weight);
	  e[16].setPoint(sumatera17,sumatera18,weight);
	  e[17].setPoint(sumatera18,sumatera19,weight);
	  e[18].setPoint(sumatera19,sumatera20,weight);
	  e[19].setPoint(sumatera20,sumatera21,weight);
	  e[20].setPoint(sumatera21,sumatera1,weight);
	
	  e[21].setPoint(kalimantan1,kalimantan2,weight);
	  e[22].setPoint(kalimantan2,kalimantan3,weight);
	  e[23].setPoint(kalimantan3,kalimantan4,weight);
	  e[24].setPoint(kalimantan4,kalimantan5,weight);
	  e[25].setPoint(kalimantan5,kalimantan6,weight);
	  e[26].setPoint(kalimantan6,kalimantan7,weight);
	  e[27].setPoint(kalimantan7,kalimantan8,weight);
	  e[28].setPoint(kalimantan8,kalimantan9,weight);
	  e[29].setPoint(kalimantan9,kalimantan10,weight);
	  e[30].setPoint(kalimantan10,kalimantan11,weight);
	  e[31].setPoint(kalimantan11,kalimantan12,weight);
	  e[32].setPoint(kalimantan12,kalimantan13,weight);
	  e[33].setPoint(kalimantan13,kalimantan14,weight);
	  e[34].setPoint(kalimantan14,kalimantan15,weight);
	  e[35].setPoint(kalimantan15,kalimantan16,weight);
	  e[36].setPoint(kalimantan16,kalimantan17,weight);
	  e[37].setPoint(kalimantan17,kalimantan18,weight);
	  e[38].setPoint(kalimantan18,kalimantan19,weight);
	  e[39].setPoint(kalimantan19,kalimantan20,weight);
	  e[40].setPoint(kalimantan20,kalimantan21,weight);
	  e[41].setPoint(kalimantan21,kalimantan22,weight);
	  e[42].setPoint(kalimantan22,kalimantan23,weight);
	  e[43].setPoint(kalimantan23,kalimantan24,weight);
	  e[44].setPoint(kalimantan24,kalimantan25,weight);
	  e[45].setPoint(kalimantan25,kalimantan26,weight);
	  e[46].setPoint(kalimantan26,kalimantan27,weight);
	  e[47].setPoint(kalimantan27,kalimantan1,weight);

	  e[48].setPoint(jawa1,jawa2,weight);
	  e[49].setPoint(jawa2,jawa3,weight);
	  e[50].setPoint(jawa3,jawa4,weight);
	  e[51].setPoint(jawa4,jawa5,weight);
	  e[52].setPoint(jawa5,jawa6,weight);
	  e[53].setPoint(jawa6,jawa7,weight);
	  e[54].setPoint(jawa7,jawa8,weight);
	  e[55].setPoint(jawa8,jawa9,weight);
	  e[56].setPoint(jawa9,jawa10,weight);
	  e[57].setPoint(jawa10,jawa11,weight);
	  e[58].setPoint(jawa11,jawa12,weight);
	  e[59].setPoint(jawa12,jawa13,weight);
	  e[60].setPoint(jawa13,jawa14,weight);
	  e[61].setPoint(jawa14,jawa15,weight);
	  e[62].setPoint(jawa15,jawa16,weight);
	  e[63].setPoint(jawa16,jawa17,weight);
	  e[64].setPoint(jawa17,jawa18,weight);
	  e[65].setPoint(jawa18,jawa19,weight);
	  e[66].setPoint(jawa19,jawa20,weight);
	  e[67].setPoint(jawa20,jawa21,weight);
	  e[68].setPoint(jawa21,jawa22,weight);
	  e[69].setPoint(jawa22,jawa23,weight);
	  e[70].setPoint(jawa23,jawa24,weight);
	  e[71].setPoint(jawa24,jawa25,weight);
	  e[72].setPoint(jawa25,jawa1,weight);

	  e[73].setPoint(ntt1,ntt2,weight);
	  e[74].setPoint(ntt2,ntt3,weight);
	  e[75].setPoint(ntt3,ntt4,weight);
	  e[76].setPoint(ntt4,ntt5,weight);
	  e[77].setPoint(ntt5,ntt6,weight);
	  e[78].setPoint(ntt6,ntt7,weight);
	  e[79].setPoint(ntt7,ntt8,weight);
	  e[80].setPoint(ntt8,ntt9,weight);
	  e[81].setPoint(ntt9,ntt10,weight);
	  e[82].setPoint(ntt10,ntt11,weight);
	  e[83].setPoint(ntt11,ntt1,weight);
	
	  e[84].setPoint(sulawesi1,sulawesi2,weight);
	  e[85].setPoint(sulawesi2,sulawesi3,weight);
	  e[86].setPoint(sulawesi3,sulawesi4,weight);
	  e[87].setPoint(sulawesi4,sulawesi5,weight);
	  e[88].setPoint(sulawesi5,sulawesi6,weight);
	  e[89].setPoint(sulawesi6,sulawesi7,weight);
	  e[90].setPoint(sulawesi7,sulawesi8,weight);
	  e[91].setPoint(sulawesi8,sulawesi9,weight);
	  e[92].setPoint(sulawesi9,sulawesi10,weight);
	  e[93].setPoint(sulawesi10,sulawesi11,weight);
	  e[94].setPoint(sulawesi11,sulawesi12,weight);
	  e[95].setPoint(sulawesi12,sulawesi13,weight);
	  e[96].setPoint(sulawesi13,sulawesi14,weight);
	  e[97].setPoint(sulawesi14,sulawesi15,weight);
	  e[98].setPoint(sulawesi15,sulawesi16,weight);
	  e[99].setPoint(sulawesi16,sulawesi17,weight);
	  e[100].setPoint(sulawesi17,sulawesi18,weight);
	  e[101].setPoint(sulawesi18,sulawesi19,weight);
	  e[102].setPoint(sulawesi19,sulawesi20,weight);
	  e[103].setPoint(sulawesi20,sulawesi21,weight);
	  e[104].setPoint(sulawesi21,sulawesi22,weight);
	  e[105].setPoint(sulawesi22,sulawesi23,weight);
	  e[106].setPoint(sulawesi23,sulawesi24,weight);
	  e[107].setPoint(sulawesi24,sulawesi25,weight);
	  e[108].setPoint(sulawesi25,sulawesi26,weight);
	  e[109].setPoint(sulawesi26,sulawesi27,weight);
	  e[110].setPoint(sulawesi27,sulawesi28,weight);
	  e[111].setPoint(sulawesi28,sulawesi29,weight);
	  e[112].setPoint(sulawesi29,sulawesi30,weight);
	  e[113].setPoint(sulawesi30,sulawesi31,weight);
	  e[114].setPoint(sulawesi31,sulawesi1,weight);

	  e[115].setPoint(papua1,papua2,weight);
	  e[116].setPoint(papua2,papua3,weight);
	  e[117].setPoint(papua3,papua4,weight);
	  e[118].setPoint(papua4,papua5,weight);
	  e[119].setPoint(papua5,papua6,weight);
	  e[120].setPoint(papua6,papua7,weight);
	  e[121].setPoint(papua7,papua8,weight);
	  e[122].setPoint(papua8,papua9,weight);
	  e[123].setPoint(papua9,papua10,weight);
	  e[124].setPoint(papua10,papua11,weight);
	  e[125].setPoint(papua11,papua12,weight);
	  e[126].setPoint(papua12,papua13,weight);
	  e[127].setPoint(papua13,papua14,weight);
	  e[128].setPoint(papua14,papua15,weight);
	  e[129].setPoint(papua15,papua16,weight);
	  e[130].setPoint(papua16,papua17,weight);
	  e[131].setPoint(papua17,papua18,weight);
	  e[132].setPoint(papua18,papua19,weight);
	  e[133].setPoint(papua19,papua20,weight);
	  e[134].setPoint(papua20,papua21,weight);
	  e[134].setPoint(papua21,papua22,weight);
	  e[135].setPoint(papua22,papua23,weight);
	  e[136].setPoint(papua23,papua24,weight);
	  e[137].setPoint(papua24,papua25,weight);
	  e[138].setPoint(papua25,papua26,weight);
	  e[139].setPoint(papua26,papua27,weight);
	  e[140].setPoint(papua27,papua1,weight);

	  e[141].setPoint(papX1,papX2,weight);
	  e[142].setPoint(papX2,papX3,weight);
	  e[143].setPoint(papX3,papX4,weight);
	  e[144].setPoint(papX4,papX1,weight);
	
	  e[145].setPoint(kapal1,kapal2,weight);
	  e[146].setPoint(kapal2,kapal3,weight);
	  e[147].setPoint(kapal3,kapal4,weight);
	  e[148].setPoint(kapal4,kapal1,weight);

	  e[149].setPoint(pesawat1,pesawat2,weight);
	  e[150].setPoint(pesawat2,pesawat3,weight);
	  e[151].setPoint(pesawat3,pesawat4,weight);
	  e[152].setPoint(pesawat4,pesawat1,weight);
	  e[153].setPoint(pesawat5,pesawat6,weight);
	  e[154].setPoint(pesawat7,pesawat8,weight);
}

void Peta::draw() const{
			
			for(int i = 0; i <= 154; i++)
				e[i].draw();
}
