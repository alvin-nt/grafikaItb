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
	while(!exit) {
		int key = keyboard->getPressedKeyCode();

		printf("Code [%d]\n", key);

		if(key != Keyboard::NO_INPUT) {
			key = 0;
		} else {
			if(key == KEY_BACKSPACE)
				exit = true;
		}

		// blit the screen
		ScreenInfoVar vinfo = screen->getVarInfo();
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

		// sleep for 50ms
		usleep(50);
	}
	cleanup();

	return 0;
}

void INTHandler(int dummy) {
	cleanup();
	std::cerr << "Interrupted: SIGINT invoked" << std::endl;
	exit(1);
}

void cleanup() {
	delete keyboard;
	screen->setMode(TEXT);
}
