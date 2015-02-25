#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Rectangle.hpp"
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
	Rectangle *body = new Rectangle(300, 600, Color::WHITE, //lower left point
									225, 550, Color::WHITE, //upper left point
									525, 550, Color::WHITE, //upper right point
									500, 600, Color::WHITE, //lower right point
									5.0f);
	Ellipse *turret = new Ellipse(375,550, Color::WHITE,1.0f,30.0f,5.0f);
	Edge *gun = new Edge(375,550, Color::WHITE,
						 350,525, Color::WHITE,
						 5.0f);
						 
	Ellipse *bullet = new Ellipse(350,525, Color::WHITE, 1.0f, 5.0f, 5.0f);
	
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
				body->move(0-movHorizontal, 0);
				turret->move(0-movHorizontal, 0);
				gun->move(0-movHorizontal, 0);
				break;
			case KEY_RIGHT:
				body->move(movHorizontal, 0);
				turret->move(movHorizontal, 0);
				gun->move(movHorizontal, 0);
				break;
			case KEY_UP:
				body->move(0, 0-movVertical);
				turret->move(0, 0-movVertical);
				gun->move(0, 0-movVertical);
				break;
			case KEY_DOWN:
				body->move(0, movVertical);
				turret->move(0, movVertical);
				gun->move(0, movVertical);
				break;
			}
		}
		
		bullet->move(0-movHorizontal,0-movVertical);
		//body->move(0-movHorizontal, 0);
		screen->drawBackground();
		screen->draw(turret);
		screen->draw(gun);
		screen->draw(body);
		screen->draw(bullet);
		screen->update();

		// sleep
		usleep(11500);
	}
	delete body;
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
