#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Polygon.hpp"

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
	screen->setGraphicsMode(GRAPHICS);

	bool exit = false;

	// build the polygon
	auto builder = Polygon::Builder();
	
	// set the params for the star
	// points
	builder.point(300, 100) 
		.point(350, 200).point(450, 150) 
		.point(375, 350) 
		.point(425, 500)
		.point(300, 350)
		.point(175, 500)
		.point(225, 350)
		.point(150, 150).point(250, 200);
	
	builder.baseColor(Color::ORANGE)
			.weight(1.5f);
	
	Polygon *star1 = builder.buildNew();
	
	std::cout << "Star 1: " << std::endl;
	std::cout << *star1;
	
	// create the second star
	builder.translate(100, 0).baseColor(Color::BLUE);
	
	//Polygon *star2 = builder.buildNew();
	//std::cout << "Star 2: " << std::endl;
	//std::cout << *star2;

	bool fill = true;
	float deg = 10.f;
	// the main program loop
	while(!exit) {
		int key = keyboard->getPressedKeyCode();

		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			switch (key) {
			case KEY_BACKSPACE:
				exit = true;
				break;
			case KEY_1:
				// swap first element's zIndex with the second
				break;
			case KEY_2:
				// switch fill
				fill = !fill;
				break;
			}
		}

		screen->drawBackground();
		screen->draw(star1, fill);
		//screen->draw(star2, fill);

		screen->update();

		// rotate
		star1->rotate(deg);
		//star2->rotate(-deg);

		// sleep
		usleep(50);
	}
	delete star1;
	//delete star2;
	cleanup();

	return 0;
}

void INTHandler(int dummy) {
	cleanup();
	cerr << "Interrupted: SIGINT invoked" << endl;
	exit(1);
}

void cleanup() {
	screen->setGraphicsMode(TEXT);
	Screen::destroy();
	delete keyboard;
}
