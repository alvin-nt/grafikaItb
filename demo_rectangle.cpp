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
Color colorPicker();
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
	Color color = colorPicker();
	printf("Selesai");
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

Color colorPicker(){
	bool exit = false;
	int pil=1;
	// the main program loop
	
	// initialize the rectangle
<<<<<<< HEAD
	Rectangle *rect = new Rectangle(200, 200, Color::WHITE,
									200, 300, Color::WHITE,
									300, 300, Color::WHITE,
									300, 200, Color::WHITE,20.0f);
	
	int movHorizontal = 3, movVertical = 3;
=======
	Rectangle *rect1 = new Rectangle(50, 200, Color::BLUE,
									50, 300, Color::BLUE,
									250, 300,Color::BLUE,
									250, 200,Color::BLUE,10.0f);
									
	Rectangle *rect2 = new Rectangle(300, 200, Color::RED,
									300, 300, Color::RED,
									500, 300, Color::RED,
									500, 200, Color::RED,10.0f);
									
	Rectangle *rect3 = new Rectangle(550, 200, Color::GREEN,
									550, 300, Color::GREEN,
									750, 300, Color::GREEN,
									750, 200, Color::GREEN,10.0f);
									
	Rectangle *outline = new Rectangle(40, 190, Color::WHITE,
									40, 310, Color::WHITE,
									260, 310, Color::WHITE,
									260, 190, Color::WHITE,10.0f);
	rect1->setFillColor(Color::BLUE);
	rect2->setFillColor(Color::RED);
	rect3->setFillColor(Color::GREEN);		
>>>>>>> f990632c22c7a74dd670427b44bc1bcb7995866e
	
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
				if(pil!=1)
					pil--;
				break;
			case KEY_RIGHT:
				outline->move(250,0);
				if(pil!=3)
					pil++;
				break;
			case KEY_UP:
				break;
			case KEY_DOWN:
				break;
			}
		}

		screen->drawBackground();
<<<<<<< HEAD
		screen->draw(rect, true);
=======
		screen->draw(rect1,true);
		screen->draw(rect3,true);
		screen->draw(rect2,true);
		screen->draw(outline);
>>>>>>> f990632c22c7a74dd670427b44bc1bcb7995866e
		screen->update();
		printf("Hampir Selesai");
		// sleep
		usleep(500);
	}
	switch(pil){
		case 1 :
			return rect1->getFillColor();
		break;
		case 2 :
			return rect2->getFillColor();
		break;
		case 3 :
			return rect3->getFillColor();
		break;
	}
	
<<<<<<< HEAD
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
=======
	
>>>>>>> f990632c22c7a74dd670427b44bc1bcb7995866e
}
