#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Helicopter.hpp"

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

	// the main program loop
	
	// initialize the helicopter
	Point p(500,500);
	Helicopter *helicopter = new Helicopter(p, 0, Color::BLACK, 1.0f,1);
	
	int movHorizontal = 5, movVertical = 5;
	
	while(!exit) {
		int key = keyboard->getPressedKeyCode();
		
		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			switch(key) {
			case KEY_BACKSPACE:
				exit = true;
				break;
			case KEY_LEFT:
				helicopter->moveHelicopter(0-movHorizontal, 0);
				break;
			case KEY_RIGHT:
				helicopter->moveHelicopter(movHorizontal, 0);
				break;
			case KEY_UP:
				helicopter->moveHelicopter(0, 0-movVertical);
				break;
			case KEY_DOWN:
				helicopter->moveHelicopter(0, movVertical);
				break;
			}
		}

		screen->drawBackground();
		screen->draw(helicopter);
		screen->draw(helicopter->body);
		screen->update();

		// sleep
		usleep(50);
	}
	delete helicopter;
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
