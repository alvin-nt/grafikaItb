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
	Point *p1 = new Point(400, 400,Color::WHITE);
	
	Cube *cube1 = new Cube(*p1,60);
	cube1->setPov(3);
	
	Point *p2 = new Point(200, 400,Color::WHITE);
	
	Cube *cube2 = new Cube(*p2,100);
	cube2->setPov(3);
	
	Cruiser *cruiser = new Cruiser(300,600);
	
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
	delete p1;
	
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
