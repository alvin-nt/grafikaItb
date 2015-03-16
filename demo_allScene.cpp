#include "Rasterizer.hpp"
#include "Keyboard.hpp"
#include "Color.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "Types.hpp"
#include "Rectangle.hpp"
#include "Cube.hpp"
#include "Cruiser.hpp"
#include "Peta.hpp"
#include "ViewPort.hpp"
#include "Helicopter.hpp"
#include "Parachute.hpp"
#include "writetext.hpp"
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

Color colorPicker();

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
	bool exitMain = false;

	// the main program loop
	int mode = 1; //this indicate which scene is active
	while(!exitMain) {
		if(mode == 1) { /* Scene 1: Welcome Screen */
		mode = 2;
		} else if (mode == 2) { /* Scene 2: Colorpicker */
		Color color = colorPicker();
		mode = 3;
		} else if (mode == 3) { /* Scene 3: Peta Indonesia */

			Peta *peta = new Peta(0,-60);
			ViewPort *vp = new ViewPort(200,200,600,400,200,200,peta);
			
			int movHorizontal = 2, movVertical = 2;
			while(!exit) {
				int key = keyboard->getPressedKeyCode();

				if(key == Keyboard::NO_INPUT) {
					key = 0;
				} else {
					switch(key)
					{
						case KEY_BACKSPACE:
							exit = true;
							break;
						case KEY_LEFT:
							vp->move(0-movHorizontal, 0);
							break;
						case KEY_RIGHT:
							vp->move(movHorizontal, 0);
							break;
						case KEY_UP:
							vp->move(0, 0-movVertical);
							break;
						case KEY_DOWN:
							vp->move(0, movVertical);
							break;
						case KEY_Z:
							vp->zoomOut();
							break;
						case KEY_X:
							vp->zoomIn();
							break;
						case KEY_ENTER:
							exit = true;
							mode = 4;
							break;
					}
				}
				screen->drawBackground();
				
				peta->move(10,0);
				peta->setPoin();
				
				screen->draw(peta);
				screen->draw(vp);
				screen->update();

				// sleep
				usleep(50);
			}
			//TODO fix dtor
			/* Causes Segfault, fuck clean code */
			/*cleanup();
			delete vp;
			delete peta;*/
		
		} else if (mode == 4) { /* Scene 4: Kapal dan gedung "3D"*/
				// initialize the pov
				int pov=1;
				
				//Gedung kiri
				Point *p1 = new Point(200, 400,Color::WHITE);
				Cube *cube1 = new Cube(*p1,60);
				cube1->setPov(pov);
				
				//Gedung tengah
				Point *p2 = new Point(300, 400,Color::WHITE);
				Cube *cube2 = new Cube(*p2,150);
				cube2->setPov(pov);
				
				//Gedung kanan
				Point *p3 = new Point(450,400, Color::WHITE);
				Cube *cube3 = new Cube(*p3,100);
				cube3->setPov(pov);
				
				//Garis horizon
				Edge *horizon = new Edge(Drawable::SCREEN_X_MIN, 400, Color::WHITE
										,Drawable::SCREEN_X_MAX, 400, Color::WHITE, 1.0f);
				
				//As it says, the cruiser
				Cruiser *cruiser = new Cruiser(550,550,Color::WHITE);
				
				int movHorizontal = 5, movVertical = 5;
				while(!exit) {

					int key = keyboard->getPressedKeyCode();

					if(key == Keyboard::NO_INPUT) {
						key = 0;
					} else {
						switch(key) {
						case KEY_BACKSPACE:
							exit = true;
							exitMain = true;
							break;
						case KEY_LEFT:
								cruiser->move(0-movHorizontal);
							break;
						case KEY_RIGHT:
								cruiser->move(movHorizontal);
							break;
						}
						//Go to next scene
						if(cruiser->getUpperLeftPoint().getX() == Drawable::SCREEN_X_MIN) {
							exit = true;
							mode = 5;
						}
					}
					//Draw everything on screen
					screen->drawBackground();
					
					if(cruiser->getXMidPoint() > Drawable::SCREEN_X_MAX/2) {
						pov = 1;
						cube1->setPov(pov);
						cube2->setPov(pov);
						cube3->setPov(pov);
						/*Ini harusnya pake draw fill*/
						screen->draw(cube3);
						screen->draw(cube2);
						screen->draw(cube1);
					} else {
						pov = 3;
						cube1->setPov(pov);
						cube2->setPov(pov);
						cube3->setPov(pov);
						/*Ini harusnya juga pake draw fill*/
						screen->draw(cube1);
						screen->draw(cube2);
						screen->draw(cube3);
					}
					
					screen->draw(horizon);
					screen->draw(cruiser);
					screen->update();

					// sleep
					usleep(50);
				}
				//cleanup();
				delete cube1;
				delete cube2;
				delete cube3;
				delete cruiser;
				delete p1;
				delete p2;
				delete p3;
				delete horizon;
		} else if (mode == 5) { /* Scene 5: Perang heli vs kapal */
			

	screen->setBackground(Color::WHITE);
	// initialize the helicopter
	Point p(500,100);
	Helicopter *helicopter = new Helicopter(p, 0, Color::BLACK, 1.0f,1);
	
	// initialize the rectangle
	Cruiser *cruiser = new Cruiser(550,550,Color::BLACK);
						 
	Ellipse *bullet = NULL;
	Parachute *para = NULL;
	
	int movHorizontalship = 10;
	bool bulletExists = false;
	int movHorizontalheli = 1;
	int movHorizontalbullet = 8, movVerticalbullet = 10;
	int phase = 0;
	bool fire = false;
	exit = false;
	printf("fafafa");
	while(!exit) {
		int key = keyboard->getPressedKeyCode();
		
		if(key == Keyboard::NO_INPUT) {
			key = 0;
		} else {
			switch(key) {
			case KEY_BACKSPACE:
				exit = true;
				break;
			}
		}
		
		screen->drawBackground();
		if(phase==0){
			helicopter->moveHelicopter(0-movHorizontalheli, 0);
			screen->draw(helicopter);
			screen->draw(helicopter->body);
			screen->draw(cruiser);
		}	
		else if(phase==1){
			
			if(cruiser->getUpperLeftPoint().getX() > 10){
				cruiser->move(0-movHorizontalship);
				screen->draw(cruiser);
			}
			if(para->getHeight() < 600){
				para->move(0,5);
				screen->draw(para);
			}
			else
			{
				exit = true;
			}
		}
		
		if(!bulletExists && !fire) {
					Point refPoint(cruiser->getXMidPoint()-10,cruiser->getUpperLeftPoint().getY()-20);
					
					bullet = new Ellipse(refPoint.getX(), refPoint.getY(), Color::WHITE, 1.0f, 5.0f, 5.0f,1.f);
					bulletExists = true;
					fire = true;
				}
		if(bulletExists && bullet != NULL) {
			screen->draw(bullet);
			Point check(bullet->getCenter());
			
			// try to move
			bullet->move(0-movHorizontalbullet,0-movVerticalbullet);
			if(helicopter->getMidpoint().getY()+20 > bullet->getCenter().getY()) {
				delete bullet;
				bulletExists = false;
				phase = 1;
				para = new Parachute(helicopter->getMidpoint().getX(),helicopter->getMidpoint().getY(),Color::BLACK);
			}
		}
		screen->update();

		// sleep
		usleep(2500);
	}
	/*delete helicopter;
	delete cruiser;
	delete para;
	cleanup();*/

	screen->setBackground(Color::BLACK);
	
	mode = 6; //maju scene
		} else if (mode == 6) { /* Scene 6: You WIN */
			writetext *write = new writetext("you win!",10,0.5,300,300);
			write->ReadFromFile("dictionary.txt");
			write->Allocatechar();
			
			while(!exit) {
				int key = keyboard->getPressedKeyCode();

				if(key == Keyboard::NO_INPUT) {
					key = 0;
				} else {
					if(key == KEY_BACKSPACE)
						exit = true;
						exitMain = true;
				}
				screen->drawBackground();
				screen->draw(write);
				screen->update();

				// sleep
				usleep(50);
			}
			//delete write;
			cleanup();
			mode++;
			
		}
		exit = false;
		clearScreen();
	}
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
			case KEY_ENTER:
				exit = true;
				break;
			}
		}

		screen->drawBackground();
		screen->draw(rect1,true);
		screen->draw(rect3,true);
		screen->draw(rect2,true);
		screen->draw(outline);
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
	
	
}
