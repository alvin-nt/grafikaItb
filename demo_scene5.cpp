#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Helicopter.hpp"
#include "Cruiser.hpp"
#include "Ellipse.hpp"
#include "Parachute.hpp"

#include <cstdlib>
#include <signal.h>
#include <unistd.h> // usleep
#include <ctime>
#include <iostream>

using namespace Graphics;

using std::cout;
using std::cerr;
using std::endl;

// handles ctrl-c
// temporarily not used
void INTHandler(int dummy);

void cleanup();

Keyboard *keyboard;
Rasterizer *screen;

int main()
{
	if (getuid() != 0) {
		printf("This program must be run as root.\n");
		exit(3);
	}

	// initialization
	clearScreen();
	signal(SIGINT, INTHandler); // hook interrupt (Ctrl-C) to INTHandler

	keyboard = new Keyboard();
	screen = Screen::instance(); // singleton
	screen->setMode(GRAPHICS);
	screen->setBackground(Color::WHITE);

	bool exit = false;
	bool fire = false;

	// the main program loop
	
	// initialize the helicopter
	Point p(500,100);
	Helicopter *helicopter = new Helicopter(p, 0, Color::BLACK, 1.0f,1);
	
	// initialize the rectangle
	Cruiser *cruiser = new Cruiser(700,550,Color::BLACK);
						 
	Ellipse *bullet = NULL;
	Parachute *para = NULL;
	
	int movHorizontalship = 10;
	bool bulletExists = false;
	int movHorizontalheli = 1;
	int movHorizontalbullet = 8, movVerticalbullet = 10;
	int phase = 0;
	
	while(!exit) {
		int key = keyboard->getPressedKeyCode();
		
		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			switch(key) {
			case KEY_BACKSPACE:
				exit = true;
				break;
			}
		}
		
		screen->drawBackground();
		if(phase==0){
			helicopter->moveHelicopter(0-movHorizontalheli, 0);
			screen->draw(helicopter);
			screen->draw(helicopter->body);
			screen->draw(cruiser);
		}	
		else if(phase==1){
			
			if(cruiser->getUpperLeftPoint().getX() > 10){
				cruiser->move(0-movHorizontalship);
				screen->draw(cruiser);
			}
			if(para->getHeight() < 600){
				para->move(0,5);
				screen->draw(para);
			}
		}
		
		if(!bulletExists && !fire) {
					Point refPoint(cruiser->getXMidPoint()-10,cruiser->getUpperLeftPoint().getY()-20);
					
					bullet = new Ellipse(refPoint.getX(), refPoint.getY(), Color::WHITE, 1.0f, 5.0f, 5.0f,1.f);
					bulletExists = true;
					fire = true;
				}
		if(bulletExists && bullet != NULL) {
			screen->draw(bullet);
			Point check(bullet->getCenter());
			
			// try to move
			bullet->move(0-movHorizontalbullet,0-movVerticalbullet);
			if(helicopter->getMidpoint().getY()+20 > bullet->getCenter().getY()) {
				delete bullet;
				bulletExists = false;
				phase = 1;
				para = new Parachute(helicopter->getMidpoint().getX(),helicopter->getMidpoint().getY(),Color::BLACK);
			}
		}
		screen->update();

		// sleep
		usleep(50);
	}
	delete helicopter;
	delete cruiser;
	delete para;
	cleanup();

	return 0;
}

void INTHandler(int dummy) {
	cleanup();
	cerr << "Interrupted: SIGINT invoked" << endl;
	exit(1);
}

void cleanup() {
	screen->setMode(TEXT);
	Screen::destroy();
	delete keyboard;
}


 /* int pov=1;
				
				//Gedung kiri
				Point *p1 = new Point(200, 400,Color::WHITE);
				Cube *cube1 = new Cube(*p1,60);
				cube1->setPov(pov);
				
				//Gedung tengah
				Point *p2 = new Point(300, 400,Color::WHITE);
				Cube *cube2 = new Cube(*p2,150);
				cube2->setPov(pov);
				
				//Gedung kanan
				Point *p3 = new Point(450,400, Color::WHITE);
				Cube *cube3 = new Cube(*p3,100);
				cube3->setPov(pov);
				
				//Garis horizon
				Edge *horizon = new Edge(Drawable::SCREEN_X_MIN, 400, Color::WHITE
										,Drawable::SCREEN_X_MAX, 400, Color::WHITE, 1.0f);
				
				//As it says, the cruiser
				Cruiser *cruiser = new Cruiser(550,550);
				
				int movHorizontal = 5, movVertical = 5;
				while(!exit) {

					int key = keyboard->getPressedKeyCode();

					if(key == Keyboard::NO_INPUT) {
						key = 0;
					} else {
						switch(key) {
						case KEY_BACKSPACE:
							exit = true;
							exitMain = true;
							break;
						case KEY_LEFT:
								cruiser->move(0-movHorizontal);
							break;
						case KEY_RIGHT:
								cruiser->move(movHorizontal);
							break;
						}
						//Go to next scene
						if(cruiser->getUpperLeftPoint().getX() == Drawable::SCREEN_X_MIN) {
							exit = true;
							mode = 5;
						}
					}
					//Draw everything on screen
					screen->drawBackground();
					
					if(cruiser->getXMidPoint() > Drawable::SCREEN_X_MAX/2) {
						pov = 1;
						cube1->setPov(pov);
						cube2->setPov(pov);
						cube3->setPov(pov);
						/*Ini harusnya pake draw fill*/
					/*	screen->draw(cube3);
						screen->draw(cube2);
						screen->draw(cube1);
					} else {
						pov = 3;
						cube1->setPov(pov);
						cube2->setPov(pov);
						cube3->setPov(pov);
						/*Ini harusnya juga pake draw fill*/
						/*screen->draw(cube1);
						screen->draw(cube2);
						screen->draw(cube3);
					}
					
					screen->draw(horizon);
					screen->draw(cruiser);
					screen->update();

					// sleep
					usleep(50);
				}
				cleanup();
				delete cube1;
				delete cube2;
				delete cube3;
				delete cruiser;
				delete p1;
				delete p2;
				delete p3;
				delete horizon;
				*/

