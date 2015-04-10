#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Rectangle.hpp"
#include "Toolbox.hpp"
#include "Cursor.hpp"
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

Keyboard *keyboard = new Keyboard();
Rasterizer *screen;
int mode;
Toolbox *toolbox = new Toolbox();
Cursor *cursor = new Cursor(0,0);

int main()
{
	if (getuid() != 0) {
		printf("This program must be run as root.\n");
		exit(3);
	}
	
	// initialization
	clearScreen();
	signal(SIGINT, INTHandler); // hook interrupt (Ctrl-C) to INTHandler

	screen = Screen::instance(); // singleton
	screen->setMode(GRAPHICS);
	screen->setBackground(Color::WHITE);
	Toolbox *toolbox = new Toolbox();
        //while((c = Gpm_Getc(stdin)) != EOF)
         //       printf("%c", c);
        
	bool exit = false;
	FILE *fmouse;
	char b[3];
	fmouse = fopen("/dev/input/mice","r");
	int xd=0,yd=0; //x/y movement delta
	int xo=0,yo=0; //x/y overflow (out of range -255 to +255)
	int lb=0,mb=0,rb=0,hs=0,vs=0; //left/middle/right mousebutton
	mode = 1;
	
	while(!exit) {

		
		
		screen->drawBackground();
		screen->draw(toolbox);
		screen->draw(cursor);
		screen->update();
		fread(b,sizeof(char),3,fmouse);
		lb=(b[0]&1)>0;
		rb=(b[0]&2)>0;
		mb=(b[0]&4)>0;
		hs=(b[0]&16)>0;
		vs=(b[0]&32)>0;
		xo=(b[0]&64)>0;
		yo=(b[0]&128)>0;
		xd=b[1];
		yd=b[2];
		cursor->move(xd,-yd);
		if(mode==1) //cursor
		{
			
		}
		else if(mode==2) //rectangle
		{
			
		}
		else if(mode==3) //ellipse
		{
			
		}
		else if(mode==4) //line
		{
			
		}
		int key = keyboard->getPressedKeyCode();		

		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			if(key == KEY_BACKSPACE)
				exit = true;
		}
		// sleep
		usleep(500);
	}
delete toolbox;
cleanup();
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
