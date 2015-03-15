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
	
	// initialize the cube1
	int pov=3;
	Point *p1 = new Point(400, 600,Color::WHITE);
	
	Cube *cube1 = new Cube(*p1,60);
	cube1->setPov(pov);
	
	Point *p2 = new Point(200, 600,Color::WHITE);
	
	Cube *cube2 = new Cube(*p2,100);
	cube2->setPov(pov);
	
	Edge *horizon = new Edge(Drawable::SCREEN_X_MIN, 550, Color::WHITE
							,Drawable::SCREEN_X_MAX, 550, Color::WHITE, 1.0f);
	
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
			case KEY_Z:
				if (pov > 0) {
					pov--;
					cube1->setPov(pov);
					cube2->setPov(pov);
				}
				break;
			case KEY_X:
				if (pov < 4) {
					pov++;
					cube1->setPov(pov);
					cube2->setPov(pov);
				}
				break;
			}
		}
		screen->drawBackground();
		screen->draw(horizon);
		screen->draw(cube1);
		screen->draw(cube2);
		screen->draw(cruiser);
		screen->update();

		// sleep
		usleep(50);
	}
	cleanup();
	delete cube1;
	delete cube2;
	delete cruiser;
	delete p1;
	delete p2;
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
