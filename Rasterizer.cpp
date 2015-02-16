#include "Rasterizer.hpp"
#include "Drawable.hpp"
#include "ShapeFillable.hpp"

#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace Graphics;

bool Rasterizer::instantiated = false;

void Graphics::clearScreen() {
	printf("\033[H\033[J");
}

Rasterizer::Rasterizer()
	: background(Color::BLACK)
{
	if(!instantiated) {
		memset(&finfo, 0, sizeof(finfo));
		memset(&vinfo, 0, sizeof(vinfo));

		initFramebuffer();

		// setup the terminal
		fdTty = open("/dev/tty1", O_RDWR | O_NOCTTY);
		if(fdTty == -1) {
			perror("Cannot open terminal");
			exit(1);
		}
		instantiated = true;
	} else {
		printf("Double instantiation detected!\n");
		Screen::instance()->setMode(TEXT);
		exit(11);
	}

}

Rasterizer::~Rasterizer() {
	close(fdTty);

	switch (mapMode) {
	case PAN:
		munmap(ptrFramebuffer, screenSize << 1);
		break;
	case DOUBLE:
		munmap(ptrFramebuffer, screenSize);
		munmap(ptrBackbuffer, screenSize);
		break;
	case SINGLE:
		munmap(ptrFramebuffer, screenSize);
		ptrBackbuffer = null;
		break;
	}

	if(mode == GRAPHICS)
		setMode(TEXT);
	close(fdFramebuffer);
}

void Rasterizer::setMode(Graphics::Mode mode) {
	this->mode = mode;

	switch(this->mode) {
	case GRAPHICS:
		if(ioctl(fdTty, KDSETMODE, KD_GRAPHICS) == -1) {
			perror("Cannot change terminal to GRAPHICS mode");
		}
		break;
	case TEXT:
		if(ioctl(fdTty, KDSETMODE, KD_TEXT) == -1) {
			perror("Cannot change terminal to TEXT mode");
		}
		break;
	};
}

Mode Rasterizer::getMode() const {
	return mode;
}

const Color &Rasterizer::getBackground() const {
	return background;
}

void Rasterizer::setBackground(const Color &color) {
	background = color;
}

const ScreenInfoVar& Rasterizer::getVarInfo() const {
	return vinfo;
}

const ScreenInfoFix& Rasterizer::getFixInfo() const {
	return finfo;
}

void Rasterizer::draw(const Drawable *shape) {
	drawBackground();

	shape->draw();
	// TODO: put the object in the drawObject vector
}

void Rasterizer::setPixel(int x, int y, Pixel pixel) {
	long location = getDrawLocation(x, y);

	*((Pixel*)(ptrBackbuffer + location)) = pixel;
}

void Rasterizer::setPixel(int x, int y, const Color& color) {
	setPixel(x, y, color.toPixel());
}

void Rasterizer::draw(const ShapeFillable *shape, bool fill) {
	drawBackground();

	shape->draw(fill);
	// TODO: put the object in the drawObject vector
}

void Rasterizer::destroy(Drawable *drawable) {
	// stub
	(void)(drawable);
}

const byte *Rasterizer::getFramebuffer() const {
	byte *ret;

	switch(mapMode) {
	case PAN:
	case DOUBLE:
		ret = ptrBackbuffer;
		break;
	case SINGLE:
		ret = ptrFramebuffer;
		break;
	default:
		printf("Oops: invalid map mode\n");
		exit(10);
	}

	return ret;
}

void Rasterizer::update() {
	swapBuffers();
}

void Rasterizer::swapBuffers() {
	switch(mapMode) {
	case PAN:
		vinfo.yoffset = vinfo.yoffset == 0 ? screenSize : 0;

		// "Pan" to the backbuffer
		if(ioctl(fdFramebuffer, FBIOPAN_DISPLAY, &vinfo) == -1) {
			perror("Cannot pan the framebuffer.");
			// this is somewhat fatal, since the screen cannot be updated.
			// need some work to make the screen still drawable, without crashing the program
			// maybe revert to SINGLE map mode?
		}

		// update the pointer to the back buffer
		long tmp;

		tmp = (long)ptrFramebuffer;
		ptrFramebuffer = ptrBackbuffer;
		ptrBackbuffer = (byte*)tmp;
		break;
	case DOUBLE:
		for (int i = 0; i < screenSize; i++) {
			*((Pixel*)(ptrFramebuffer + i)) = ptrBackbuffer[i];
		}

		// IMBA mode: write this in assembly, using SSE stuff~~~~
		break;
	case SINGLE:
		// nothing
		break;
	default:
		printf("Oops: invalid map mode\n");
		exit(10);
	}
}

// TODO: refactor to getDrawOffset
long Rasterizer::getDrawLocation(int x, int y) {
	return (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8)
		+ (y + vinfo.yoffset) * finfo.line_length;
}

void Rasterizer::drawBackground() {
	Pixel pixel = background.toPixel();

	for(auto y = 0u; y < vinfo.yres; y++) {
		for(auto x = 0u; x < vinfo.xres; x++) {
			setPixel(x, y, pixel);
		}
	}
}

void Rasterizer::initFramebuffer() {
	fdFramebuffer = open("/dev/fb0", O_RDWR);
	if(fdFramebuffer == -1) {
		perror("Cannot open framebuffer device");
		exit(1);
	}

	// get and set screen to 32-bit mode
	if(ioctl(fdFramebuffer, FBIOGET_VSCREENINFO, &vinfo) == -1) {
		perror("Cannot get variable screen info.");
		exit(2);
	}

	// switch to 32-bit mode
	vinfo.grayscale = 0; // 0 == color, 1 == grayscale
	vinfo.bits_per_pixel = 32; // guess what :p

	if(ioctl(fdFramebuffer, FBIOPUT_VSCREENINFO, &vinfo) == -1) {
		perror("Cannot set variable screen info.");
		exit(3);
	}
	if(ioctl(fdFramebuffer, FBIOGET_VSCREENINFO, &vinfo) == -1) {
		perror("Cannot get variable screen info.");
		exit(2);
	}

	if(ioctl(fdFramebuffer, FBIOGET_FSCREENINFO, &finfo) == -1) {
		perror("Cannot get fixed screen info.");
		exit(2);
	}

	screenSize = vinfo.yres_virtual * finfo.line_length;

	// trial #1: map the framebuffer, 2x the size (PAN): still buggy, therefore not implemented yet
	// TODO: guess from the vinfo
	/*ptrFramebuffer = (byte*) mmap(0, screenSize << 1,
								PROT_READ | PROT_WRITE,
								MAP_SHARED, fdFramebuffer, (off_t) 0);*/

	// double buffer initialization
	/*if((int) ptrFramebuffer == -1) */{
		/*perror("Framebuffer device does not support PAN mode");
		printf("Trying DOUBLE mode\n");*/

		// Trial #2: map the framebuffer
		ptrFramebuffer = (byte*) mmap(0, screenSize,
								PROT_READ | PROT_WRITE,
								MAP_SHARED, fdFramebuffer, (off_t) 0);

		if((int) ptrFramebuffer == -1) {
			perror("Cannot map FB device");
			exit(4);
		} else {
			// try to map the backbuffer
			ptrBackbuffer = (byte*) mmap(0, screenSize, PROT_READ | PROT_WRITE,
									MAP_PRIVATE | MAP_ANONYMOUS, -1, (off_t) 0);

			// fallback to single buffer	 
			if((int) ptrBackbuffer == -1) {
				perror("Cannot map second buffer");
				printf("Reverting to SINGLE mode\n");
				ptrBackbuffer = ptrFramebuffer;
				
				mapMode = SINGLE;
				printf("Framebuffer initialized as SINGLE mode\n");
			} else {
				mapMode = DOUBLE;
				printf("Framebuffer initialized as DOUBLE mode\n");
			}
		}
	} /*else {
		ptrBackbuffer = ptrFramebuffer + screenSize;
		mapMode = PAN;
		
		printf("Framebuffer initialized as PAN mode\n");
	}*/
}
