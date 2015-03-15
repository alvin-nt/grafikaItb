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
	Rectangle *rect = new Rectangle(50, 200, Color::BLUE,
									50, 300, Color::BLUE,
									250, 300,Color::BLUE,
									250, 200,Color::BLUE,10.0f);
									
	Rectangle *rect1 = new Rectangle(300, 200, Color::RED,
									300, 300, Color::RED,
									500, 300, Color::RED,
									500, 200, Color::RED,10.0f);
									
	Rectangle *rect2 = new Rectangle(550, 200, Color::GREEN,
									550, 300, Color::GREEN,
									750, 300, Color::GREEN,
									750, 200, Color::GREEN,10.0f);
									
	Rectangle *outline = new Rectangle(40, 190, Color::WHITE,
									40, 310, Color::WHITE,
									260, 310, Color::WHITE,
									260, 190, Color::WHITE,10.0f);
	rect->setFillColor(Color::BLUE);
	rect1->setFillColor(Color::RED);
	rect2->setFillColor(Color::GREEN);			
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
				outline->move(-250,0);
				break;
			case KEY_RIGHT:
				outline->move(250,0);
				break;
			case KEY_UP:
				break;
			case KEY_DOWN:
				break;
			}
		}

		screen->drawBackground();
		screen->draw(rect,true);
		screen->draw(rect2,true);
		screen->draw(rect1,true);
		screen->draw(outline);
		screen->update();

		// sleep
		usleep(5000);
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
