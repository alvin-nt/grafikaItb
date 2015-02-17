#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Ellipse.hpp"

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
	screen->setMode(GRAPHICS);

	bool exit = false;

	// the main program loop
	
	// initialize the line
//	Ellipse::Ellipse(int x1, int y1, const Color& c1,int x2, int y2, const Color& c2,int cx3, int cy3, const Color& c3,float weight)
	Ellipse *elips = new Ellipse(200, 200, Color::BLACK,0.00,200.00,10.f);
	
	//int movHorizontal = 5, movVertical = 5;
	
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
				//line->move(0-movHorizontal, 0);
				break;
			case KEY_RIGHT:
				//line->move(movHorizontal, 0);
				break;
			case KEY_UP:
				//line->move(0, 0-movVertical);
				break;
			case KEY_DOWN:
				//line->move(0, movVertical);
				break;
			}
		}

		screen->draw(elips);
		screen->update();

		// sleep
		usleep(50);
	}
	delete elips;
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
