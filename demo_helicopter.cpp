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
