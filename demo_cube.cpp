#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Rectangle.hpp"
#include "Cube.hpp"

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
	
	// initialize the cube
	Point *p1 = new Point(200,200,Color::WHITE);
	Cube *cube = new Cube(*p1,60);
	cube->setPov(3);
	int movHorizontal = 10, movVertical=10;
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
				cube->move(0-movHorizontal, 0);
				break;
			case KEY_RIGHT:
				cube->move(movHorizontal, 0);
				break;
			case KEY_UP:
				cube->move(0, 0-movVertical);
				break;
			case KEY_DOWN:
				cube->move(0, movVertical);
				break;
			}
		}

		screen->drawBackground();
		screen->draw(cube);
		screen->update();

		// sleep
		usleep(50);
	}
	cleanup();
	delete cube;
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
