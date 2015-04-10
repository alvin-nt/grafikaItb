#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Rectangle.hpp"
#include "Toolbox.hpp"
#include "Cursor.hpp"
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

Keyboard *keyboard = new Keyboard();
Rasterizer *screen;
int mode;
Toolbox *toolbox = new Toolbox();
Cursor *cursor = new Cursor(0,0);
vector<ShapeFillable*> shapebox;
vector<Edge*> edgebox;
bool LeftClickPressed = false;
bool OnToolBox = false;
int ClickedPositionX = 0;
int ClickedPositionY = 0;


int main()
{
	int curposx = 0; //current position mouse x
	int curposy = 0; // current position mouse y
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
		curposx += xd;
		curposy -= yd;
		if(lb >0 )
		{
			LeftClickPressed = true;
			ClickedPositionX = cursor->getPoint().getX();
			ClickedPositionY = cursor->getPoint().getY();
		}
		else if(lb == 0 && LeftClickPressed)
		{
			if(cursor->getPoint().getX() > 0 && cursor->getPoint().getX() < 40 &&
			cursor->getPoint().getY() > 300 && cursor->getPoint().getY() < 340)
			{
				mode = 1;
				LeftClickPressed = false;
				OnToolBox = true;
			}
			else if(cursor->getPoint().getX() > 40 && cursor->getPoint().getX() < 80 &&
			cursor->getPoint().getY() > 300 && cursor->getPoint().getY() < 340)
			{
				mode = 2;
				LeftClickPressed = false;
				OnToolBox = true;
			}
			else if(cursor->getPoint().getX() > 0 && cursor->getPoint().getX() < 40 &&
			cursor->getPoint().getY() > 340 && cursor->getPoint().getY() < 380)
			{
				mode = 3;
				LeftClickPressed = false;
				OnToolBox = true;
			}
			else if(cursor->getPoint().getX() > 40 && cursor->getPoint().getX() < 80 &&
			cursor->getPoint().getY() > 340 && cursor->getPoint().getY() < 380)
			{
				mode = 4;
				LeftClickPressed = false;
				OnToolBox = true;
			}
			if(mode==1 && !OnToolBox) //cursor
			{

			}
			else if(mode==2 && !OnToolBox) //rectangle
			{
				Rectangle *rect = new Rectangle(ClickedPositionX, ClickedPositionX, Color::BLUE,
									curposx, ClickedPositionY, Color::BLUE,
									curposx, curposy,Color::BLUE,
									ClickedPositionX, curposy,Color::BLUE,0.5f);
				shapebox.push_back(rect);
				LeftClickPressed = false;
			}
			else if(mode==3 && !OnToolBox) //ellipse
			{
				Ellipse *elips = new Ellipse(curposx,curposy, Color::RED,45.00,200.00,10.f,0.5);
				shapebox.push_back(elips);
				LeftClickPressed = false;
			}
			else if(mode==4 && !OnToolBox) //line
			{
				Edge *edge = new Edge(ClickedPositionX, ClickedPositionX, Color::BLUE,curposx,curposy,Color::BLUE,0.5f);
				edgebox.push_back(edge);
				LeftClickPressed = false;
			}
			OnToolBox = false;
		} 
		for(int i =0;i<shapebox.size();i++)
		{
			screen->draw(shapebox[i]);
		}
		for(int i =0;i<edgebox.size();i++)
		{
			screen->draw(edgebox[i]);
		}
		int key = keyboard->getPressedKeyCode();		

		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			if(key == KEY_BACKSPACE)
				exit = true;
		}
		screen->update();
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
