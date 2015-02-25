#include "Ball.hpp"
using namespace Graphics; 

Ball::Ball(int x, int y, int r):pusat(x,y,Color::WHITE){
			moveX=0;
			moveY=10;
			minY=150;
			maxY=600;
			this->r=r;
			balik = false;
}

Ball::~Ball(){
			
}

void Ball::animate(){
		//const static int SCREEN_X_MIN; // minimum screen width
		//static int SCREEN_X_MAX; // maximum screen width
		//const static int SCREEN_Y_MIN; // minimum screen height
		//static int SCREEN_Y_MAX; // maximum screen height
	if((pusat.getY()+r)>=maxY){
		balik = !balik;
		minY+=60;
	}
	else if((pusat.getY()-r)<=minY){
		balik = !balik;
	}
	if(!balik){
		move(moveX,moveY);
	}
	else{
		move(moveX,-1*moveY);
	}
}

void Ball::rotate(int degree){
	//TBD
}

void Ball::scale(int scale){
	//TBD
}

void Ball::move(int dx, int dy){
	pusat.move(dx,dy);
}

void Ball::draw() const{
	if(minY+r>SCREEN_Y_MAX){
		//
	}
	else{
		drawBall();
	}
}

void Ball::drawBall() const{
	Color color=Color::WHITE;
   int h = pusat.getX();
   int k = pusat.getY();
   int x=0;
   int y=r;
   int p=(3-(2*r));

   do
  {
     Point p1((h+x),(k+y),color);
     Point p2((h+y),(k+x),color);
     Point p3((h+y),(k-x),color);
     Point p4((h+x),(k-y),color);
     Point p5((h-x),(k-y),color);
     Point p6((h-y),(k-x),color);
     Point p7((h-y),(k+x),color);
     Point p8((h-x),(k+y),color);
	 p1.draw();
	 p2.draw();
	 p3.draw();
	 p4.draw();
	 p5.draw();
	 p6.draw();
	 p7.draw();
	 p8.draw();
	 
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



