#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Rectangle.hpp"
#include "Cube.hpp"
#include "Cruiser.hpp"

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

	bool exit = false;

	// the main program loop
	
	// initialize the pov
	int pov=1;
	
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
				break;
			case KEY_LEFT:
					cruiser->move(0-movHorizontal);
				break;
			case KEY_RIGHT:
					cruiser->move(movHorizontal);
				break;
			}
			//This should change scene in real demo, not exit
			if(cruiser->getUpperLeftPoint().getX() == Drawable::SCREEN_X_MIN) {
				exit = true;
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
			screen->draw(cube3);
			screen->draw(cube2);
			screen->draw(cube1);
		} else {
			pov = 3;
			cube1->setPov(pov);
			cube2->setPov(pov);
			cube3->setPov(pov);
			/*Ini harusnya juga pake draw fill*/
			screen->draw(cube1);
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
