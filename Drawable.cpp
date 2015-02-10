#include "Drawable.hpp"

using namespace Graphics;

const int Drawable::SCREEN_X_MIN = 0;
const int Drawable::SCREEN_Y_MIN = 0;
	
int Drawable::SCREEN_X_MAX = Screen::instance()->getVarInfo().xres;
int Drawable::SCREEN_Y_MAX = Screen::instance()->getVarInfo().yres;
