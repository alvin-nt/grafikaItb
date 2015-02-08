#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"

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

	bool exit = false;

	// the main program loop
	ScreenInfoVar vinfo = screen->getVarInfo();
	
	while(!exit) {
		int key = keyboard->getPressedKeyCode();

		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			if(key == KEY_BACKSPACE)
				exit = true;
		}

		// blit the screen
		for(auto y = 0u; y < vinfo.yres; y++) {
			for(auto x = 0u; x < vinfo.xres; x++) {
				Color color(0xFF, 0X00, 0xFF, 0x00);

				Pixel pixel = color.toPixel();
				pixel = ((x << 10) % pixel) / (key + 1);

				// blacklines
				if(y % 32 < 16)
					pixel = 0;
				screen->setPixel(x, y, pixel);
			}
		}
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
