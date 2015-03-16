#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Triangle.hpp"
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
	printf("Screen Instance");
	screen->setMode(GRAPHICS);
	Parachute parasut(400,150,Color::WHITE);
	printf("Parasut Instansiasi");
	bool exit = false;

	// the main program loop
	ScreenInfoVar vinfo = screen->getVarInfo();
	int counter = 0;
	while(!exit && counter<100) {
		printf("While");
		screen->drawBackground();
		/*
		int key = keyboard->getPressedKeyCode();

		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			if(key == KEY_BACKSPACE)
				exit=true;
		}*/
		parasut.move(0,2);
		screen->draw(&parasut);
		screen->update();
		counter++;
		// sleep
		usleep(50);
	}
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

