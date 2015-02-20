#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Rectangle.hpp"

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
//	screen->setMode(GRAPHICS);

	bool exit = false;

	// the main program loop
	
	// initialize the rectangle
	Rectangle *rect = new Rectangle(200, 200, Color::WHITE,
									200, 600, Color::WHITE,
									600, 600, Color::WHITE,
									600, 200, Color::WHITE,
									10.0f);
	
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
				rect->move(0-movHorizontal, 0);
				break;
			case KEY_RIGHT:
				rect->move(movHorizontal, 0);
				break;
			case KEY_UP:
				rect->move(0, 0-movVertical);
				break;
			case KEY_DOWN:
				rect->move(0, movVertical);
				break;
			}
		}

		screen->draw(rect);
		screen->update();

		// sleep
		usleep(50);
	}
	delete rect;
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
