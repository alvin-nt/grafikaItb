#include "Parachute.hpp"
#include <cmath>
using namespace Graphics;
Parachute::Parachute(int x, int y)
:anchor(x,y,Color::WHITE),tanganKiri(x-30,y,Color::WHITE),tanganKanan(x+30,y,Color::WHITE),leherAtas(x,y-20,Color::WHITE),
kepala1(x-20,y-20,Color::WHITE),kepala2(x+20,y-20,Color::WHITE),kepala3(x+20,y-40,Color::WHITE),kepala4(x-20,y-40,Color::WHITE),
kakiKiri(x-20,y+30,Color::WHITE),kakiKanan(x+20,y+30,Color::WHITE),kiriParasut(x-60,y-70,Color::WHITE),kananParasut(x+60,y-70,Color::WHITE)
{
	weight = 1.0f;
}

Parachute::~Parachute(){
	
}

void Parachute::animate(){
	//TBD
}

void Parachute::rotate(int degree){
	//TBD
}
void Parachute::scale(int scale){
	//TBD
}

void Parachute::move(int dx, int dy){
	anchor.move(dx,dy);
	tanganKiri.move(dx,dy);
	tanganKanan.move(dx,dy);
	kakiKiri.move(dx,dy);
	kakiKanan.move(dx,dy);
	leherAtas.move(dx,dy);
	kepala1.move(dx,dy);
	kepala2.move(dx,dy);
	kepala3.move(dx,dy);
	kepala4.move(dx,dy);
	kiriParasut.move(dx,dy);
	kananParasut.move(dx,dy);
}
void Parachute::drawArc(const int h, const int k, const int r) const{
       Color color=Color::WHITE;

       int x=0;
       int y=r;
       int p=(3-(2*r));

       do
      {
         //Point p1((h+x),(k+y),color);
         //Point p2((h+y),(k+x),color);
         Point p3((h+y),(k-x),color);
         Point p4((h+x),(k-y),color);
         Point p5((h-x),(k-y),color);
         Point p6((h-y),(k-x),color);
         //Point p7((h-y),(k+x),color);
         //Point p8((h-x),(k+y),color);
		 //p1.draw();
		 //p2.draw();
		 p3.draw();
		 p4.draw();
		 p5.draw();
		 p6.draw();
		 //p7.draw();
		 //p8.draw();
		 
         x++;

         if(p<0)
        p+=((4*x)+6);

         else
        {
           y--;
           p+=((4*(x-y))+10);
        }
      }
       while(x<=y);
 
}

void Parachute::draw() const{
	Edge e1(kepala1,kepala2,weight);
	Edge e2(kepala2,kepala3,weight);
	Edge e3(kepala3,kepala4,weight);
	Edge e4(kepala4,kepala1,weight);
	Edge e5(leherAtas,anchor,weight);
	Edge e6(tanganKiri,tanganKanan,weight);
	Edge e7(anchor,kakiKiri,weight);
	Edge e8(anchor,kakiKanan,weight);
	Edge e9(anchor,kiriParasut);
	Edge e10(anchor,kananParasut);
	Edge e11(kiriParasut,kananParasut);
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
	Point p1(kiriParasut);
	int pusX = (kiriParasut.getX()+kananParasut.getX())/2;
	int pusY = kiriParasut.getY();
	drawArc(pusX,pusY,60);
}
