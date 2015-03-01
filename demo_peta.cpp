#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Peta.hpp"

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
		cout<<"This program must be run as root."<<endl;
		exit(3);
	}

	// initialization
	clearScreen();
	signal(SIGINT, INTHandler); // hook interrupt (Ctrl-C) to INTHandler

	keyboard = new Keyboard();
	screen = Screen::instance(); // singleton
	//screen->setMode(GRAPHICS);

	bool exit = false;

	// initialize the ellipse
	Peta *peta = new Peta(0,0);
	
	int movHorizontal = 5, movVertical = 5;
	int rotatevalue = 10;
	while(!exit) {
		int key = keyboard->getPressedKeyCode();

		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			if(key == KEY_BACKSPACE)
				exit = true;
		}
		screen->drawBackground();
		screen->draw(peta);
		screen->update();

		// sleep
		usleep(50);
	}
	delete peta;
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
