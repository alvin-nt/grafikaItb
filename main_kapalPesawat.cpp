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
#include <cmath>

using namespace Graphics;

using std::cout;
using std::cerr;
using std::endl;
using std::abs;

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
	
	// initialize the rectangle
	Rectangle *body = new Rectangle(300, 600, Color::WHITE, //lower left point
									225, 550, Color::WHITE, //upper left point
									525, 550, Color::WHITE, //upper right point
									500, 600, Color::WHITE, //lower right point
									5.0f);
	Ellipse *turret = new Ellipse(375,550, Color::WHITE,1.0f,30.0f,5.0f,1.f);
	Edge *gun = new Edge(375,550, Color::WHITE,
						 350,525, Color::WHITE,
						 5.0f);
						 
	Ellipse *bullet = NULL;
	
	int movHorizontal = 5, movVertical = 5;
	bool bulletExists = false;
	
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
				if(body->getPoint2().getX() > Drawable::SCREEN_X_MIN) {
					body->move(0-movHorizontal, 0);
					turret->move(0-movHorizontal, 0);
					gun->move(0-movHorizontal, 0);
				}
				break;
			case KEY_RIGHT:
				if(body->getPoint3().getX() < Drawable::SCREEN_X_MAX) {
					body->move(movHorizontal, 0);
					turret->move(movHorizontal, 0);
					gun->move(movHorizontal, 0);
				}
				break;
			case KEY_SPACE:
				// fire bullet
				if(!bulletExists) {
					Point refPoint(gun->getPoint2());
					
					bullet = new Ellipse(refPoint.getX(), refPoint.getY(), Color::WHITE, 1.0f, 5.0f, 5.0f,1.f);
					bulletExists = true;
				}
				break;
			}
		}
		
		// draw order
		screen->drawBackground();
		screen->draw(turret);
		screen->draw(gun);
		screen->draw(body);
		
		if(bulletExists && bullet != NULL) {
			screen->draw(bullet);
			Point check(bullet->getCenter());
			
			// try to move
			bullet->move(0-abs(gun->getDeltaX()) / 5 ,0-abs(gun->getDeltaY()) / 5);
			if(check == bullet->getCenter()) {
				delete bullet;
				bulletExists = false;
			}
		}
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
