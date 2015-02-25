#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Triangle.hpp"

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
	Point p1(200,300,Color::WHITE);
	Point p2(30,40,Color::WHITE);
	Point p3(90,100,Color::WHITE);
	Triangle segitiga(p1,p2,p3,10.0f);
	Point p4(400,400,Color::WHITE);
	segitiga.setAnchor(p4);
	Edge e(p1,p2);
	bool exit = false;

	// the main program loop
	ScreenInfoVar vinfo = screen->getVarInfo();
	//int rotate = 30;
	
	while(!exit) {
		screen->drawBackground();
		/*
		int key = keyboard->getPressedKeyCode();

		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			if(key == KEY_BACKSPACE)
				exit = true;
		}
		segitiga.rotate(rotate);
		*/
		screen->draw(&segitiga, true);
		//screen->draw(&e);
		
		screen->update();

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

