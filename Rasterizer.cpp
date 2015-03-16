#include "Rasterizer.hpp"
#include "Drawable.hpp"
#include "ShapeFillable.hpp"
#include "Edge.hpp"

#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <list>

using namespace Graphics;

const byte Rasterizer::QUADRANT_ALL = 0b1111;
const byte Rasterizer::QUADRANT_1 = 0b0001;
const byte Rasterizer::QUADRANT_2 = 0b0010;
const byte Rasterizer::QUADRANT_3 = 0b0100;
const byte Rasterizer::QUADRANT_4 = 0b1000;

const byte Rasterizer::QUADRANT_VERTICAL = QUADRANT_1 | QUADRANT_2;
const byte Rasterizer::QUADRANT_MONOTONIC_INCREASE = QUADRANT_1 | QUADRANT_3;
const byte Rasterizer::QUADRANT_MONOTONIC_DECREASE = QUADRANT_2 | QUADRANT_4;

unsigned Rasterizer::zIndexNum = 0u;

bool Rasterizer::instantiated = false;

void Graphics::clearScreen() {
	printf("\033[H\033[J");
}

Bucket::Bucket(int ymin, int ymax, float x, float dx, 
				unsigned zIndex, ShapeFillable* polygon)
	: ymin(ymin), ymax(ymax), x(x), dx(dx), zIndex(zIndex), polygon(polygon)
{
	
}

Bucket::Bucket(Edge& edge)
	: zIndex(Rasterizer::zIndexNum)
{
	edge.setBucket(this);
	edge.refreshBucket();
}

Bucket::Bucket(const Bucket& bucket) 
{
	*this = bucket;
}

Bucket& Bucket::operator=(const Bucket& rhs) {
	if(this != &rhs) {
		ymin = rhs.ymin;
		ymax = rhs.ymax;
		x = rhs.x;
		dx = rhs.dx;
		zIndex = rhs.zIndex;
		polygon = rhs.polygon;
	}
	
	return *this;
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
		
		// reserve for adequate space
		edgeTable.reserve(vinfo.yres);
		
		instantiated = true;
	} else {
		printf("Double instantiation detected!\n");
		Screen::instance()->setGraphicsMode(TEXT);
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
		setGraphicsMode(TEXT);
	close(fdFramebuffer);
}

void Rasterizer::setGraphicsMode(GraphicsMode mode) {
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

GraphicsMode Rasterizer::getGraphicsMode() const {
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

void Rasterizer::setPixel(int x, int y, Pixel pixel) {
	if(x >= 0 && x < (int) vinfo.xres &&
		y >= 0 && y < (int) vinfo.yres) 
	{
		long location = getDrawOffset(x, y);

		*((Pixel*)(ptrBackbuffer + location)) = pixel;
	}
}

void Rasterizer::setPixel(int x, int y, const Color& color) {
	setPixel(x, y, color.toPixel());
}

void Rasterizer::draw(Drawable *shape) {
	shape->draw();
}

void Rasterizer::draw(ShapeFillable *shape, bool fill) {
	shape->setFill(fill);
	
	/*if(!shape->added) {
		// add every shape's edge to the bucket
		for(auto edge: shape->edges) {
			// iterate every edge in the table, check for any points that 
			// intersect.
			
			// first, check whether the edge is not flat (dy != 0)
			if (edge->getDeltaY() != 0) {
				Bucket temp(*edge);
				temp.polygon = shape;
				
				// check whether there has been an element with same ymin or not
				bool addNew = true;
				
				auto it = edgeTable.begin();
				while(addNew && it != edgeTable.end()) {
					addNew = (it->begin()->ymin != temp.ymin);
						
					if(addNew) {
						it++;
					}
				}
				
				// no occupancy; add the new element
				if (addNew) {
					// add the ymin
					if(ymin.empty()) {
						ymin.push_back((unsigned) temp.ymin);
						std::cout << "First ymin: " << temp.ymin << std::endl;
					} else {
						// special case: 'jumping' scanline, due to empty space in between shapes
						if (temp.ymin - std::prev(edgeTable.end())->begin()->ymax > 0) {
							ymin.push_back((unsigned) temp.ymin);
							
							std::cout << "Other ymin [" << yminJumps << "]: " << temp.ymin << std::endl;
							yminJumps++;
						}
					}
					
					edgeTable.push_back(std::list<Bucket>());
					std::prev(edgeTable.end())->push_back(temp);
				} else {
					// insert the element
					it->push_back(temp);
				}
				
				zIndexNum++;
			} 
			else {
				// edge is flat. just skip it.
			}
		}
		
		shape->added = true;
		sorted = false;
	}*/
	
	// draw the outline
	shape->draw();
}

void Rasterizer::destroy(Drawable *drawable) {
	// STUB
}

void Rasterizer::refresh() {
	/*if (!sorted) {
		std::sort(edgeTable.begin(), edgeTable.end(), 
			[](const std::list<Bucket>& a, const std::list<Bucket>& b) { // declaring sorting function
				return (a.begin()->ymin < b.begin()->ymin);
			});
		sorted = true;
	}
	
	fillScreen();*/
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
	refresh();
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
			setGraphicsMode(TEXT);
			exit(11);
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
		fprintf(stderr, "Oops: invalid map mode\n");
		exit(10);
	}
}

// TODO: refactor to getDrawOffset
long Rasterizer::getDrawOffset(int x, int y) {
	return (x + vinfo.xoffset) * (vinfo.bits_per_pixel >> 3)
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

Pixel Rasterizer::getPixel(int x, int y) {
	Pixel pixel = 0;	
	if(x >= 0 && x < (int) vinfo.xres &&
		y >= 0 && y < (int) vinfo.yres) 
	{
		long location = getDrawOffset(x, y);

		pixel = *((Pixel*)(ptrBackbuffer + location));
	}
	
	return pixel;
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

void Rasterizer::fillScreen()
{
	unsigned idx_ymin = 0u, y = ymin[idx_ymin++];
	unsigned idx_edgeTable = 0u;
	const unsigned ymax = std::prev(edgeTable.end())->begin()->ymax;
	
	// duplicte the edgeTable
	std::list<Bucket> activeEdgeTable(edgeTable[idx_edgeTable++]);
	
	while(y < ymax) {
		std::cout << "Current y: " << y << std::endl;
		
		// first iteration: sort the bucket
		activeEdgeTable.sort([](const Bucket& a, const Bucket& b) {
			return (a.x < b.x);
		});
		std::cout << "[" << y << "] Sort OK" << std::endl;
		
		// second iteration: check and add duplicates if necessary
		checkAndAddDuplicates(activeEdgeTable, y);
		std::cout << "[" << y << "] Duplicate OK" << std::endl;
		
		// third iteration: fill up the scanline
		fillLine(activeEdgeTable, y);
		std::cout << "[" << y << "] Fill OK" << std::endl;
		
		// fourth iteration: update everything
		auto it = activeEdgeTable.begin();
		while(it != activeEdgeTable.end()) {
			if((unsigned)it->ymax > y) {
				it->x += it->dx;
				it++;
			} else {
				std::cout << "[" << y << "] Deleting (" << (int)roundf(it->x) << ", " << y << ")" << std::endl;
				it = activeEdgeTable.erase(it);
			}
		}
		std::cout << "[" << y << "] Update OK" << std::endl;
		
		// insert the new elements
		if (idx_edgeTable < edgeTable.size()) {
			if (edgeTable[idx_edgeTable].size() > 0) {
				if ((unsigned)edgeTable[idx_edgeTable].begin()->ymin == y) {
					if(idx_edgeTable + 1 < edgeTable.size()) {
						std::cout << "[" << y << "] Inserting..." << std::endl;
						activeEdgeTable.insert(activeEdgeTable.end(), 
										edgeTable[idx_edgeTable].begin(), 
										edgeTable[idx_edgeTable].end());
						
						idx_edgeTable++;
						std::cout << "[" << y << "] Insert OK" << std::endl;
					} else {
						break;
					}
					
					std::cout << "[" << y << "] Insert OK" << std::endl;
				}
			}
		}
		
		// check for empty scanline segment
		if (activeEdgeTable.empty()) {
			std::cout << "[" << y << "] Empty ..." << std::endl;
			
			// jump to the next nearest scanline
			// make sure that the index is within jumps
			if((idx_ymin + 1) < yminJumps && idx_edgeTable < edgeTable.size()) {
				std::cout << "[" << y << "] Switching..." << std::endl;
				y = ymin[++idx_ymin];
				
				std::cout << "[" << y << "] Copying..." << std::endl;
				// do some insertion
				activeEdgeTable.insert(activeEdgeTable.end(),
										edgeTable[idx_edgeTable].begin(),
										edgeTable[idx_edgeTable].end());
				idx_edgeTable++;
				std::cout << "[" << y << "] Copy OK" << std::endl;
			} else {
				std::cout << "[" << y << "] Quitting..." << std::endl;
				break; // just quit already!
			}
		} else {
			y++; // next scanline!
		}
	}
}

byte Rasterizer::getRelativeQuadrant(const std::list<Bucket>::iterator& it,
										int y) const
{
	byte ret;

	if (it->ymax == y) {
		ret = (it->dx >= 0.f ? QUADRANT_3 : QUADRANT_2);
	} else {
		if (it->dx > 0.f) {
			ret = QUADRANT_1;
		} else if (it->dx < 0.f) {
			ret = QUADRANT_4;
		} else {
			// special case, if somehow the intersecting edge is in the middle
			ret = (it->ymin == y) ? QUADRANT_1 : QUADRANT_VERTICAL;
		}
	}
	
	return ret;
}

void Rasterizer::fillLine(const std::list<Bucket>& activeEdgeTable, int y) {
	auto it = activeEdgeTable.begin();
	
	std::vector<std::tuple<int, int, Color>> zBuffer;
	
	bool fill = true;
	while(std::next(it) != activeEdgeTable.end()) {
		auto itNext = std::next(it);
		Color color = it->polygon->baseColor;
		unsigned baseZIndex = it->zIndex;
		
		// check for 'barrier': 
		// the element with higher/same zIndex, or
		// the end of the polygons.
		while(std::next(itNext) != activeEdgeTable.end() && 
				itNext->zIndex > baseZIndex) 
		{
			itNext++;
		}
		
		if(fill) {
			if(!it->polygon->fill) {
				color.alpha = 0xff;
			}
			
			zBuffer.push_back(
				std::make_tuple((int)roundf(it->x), (int)roundf(itNext->x),
								color)
			);
		}
		fill = ~fill;
		
		// update the it position
		it = itNext;
	}
	
	fillLine(zBuffer, y);
}

void Rasterizer::checkAndAddDuplicates(std::list<Bucket>& activeEdgeTable, int y) {
	auto it = activeEdgeTable.begin();
	
	// check critical points, create duplicates if necessary
	while(std::next(it) != activeEdgeTable.end()) {
		float x = roundf(it->x);
		
		// there's a critical point
		if (roundf(std::next(it)->x) == x) {
			// critical point cases:
			// 1. monotonically increasing/monotonically decreasing --> ignore
			// 2. 'less-than' or 'greater-than' case ('<' or '>') --> ignore
			// 3. 'v' or '^' case --> duplicate
			// 4. self-intersecting polygon ('><', including 'K' and similars) --> treat like no. 3
			// 5. triads (monotonic line with another segment, or vertical line with another segment) --> treat like no. 3
			
			// special case: critical point at the end of the list
			// treat as even
			byte currentQuad = getRelativeQuadrant(it, y);
			byte nextQuad = getRelativeQuadrant(std::next(it), y);
			
			byte resultQuad = (currentQuad | nextQuad);
			if(resultQuad & (QUADRANT_1 | QUADRANT_4) ||
				resultQuad & (QUADRANT_2 | QUADRANT_3))
			{
				// duplicate!
				Bucket duplicate(*it);
				duplicate.ymax = y;
				
				activeEdgeTable.insert(it, duplicate);
			} else if (resultQuad == QUADRANT_ALL) {
				Bucket duplicate(*it);
				duplicate.ymax = y;
				
				// use two duplicates?
				activeEdgeTable.insert(it, duplicate);
				activeEdgeTable.insert(it, duplicate);
			}
		} // end of checking critical point
		it++;
	}
}

void Rasterizer::fillLine(const std::vector<std::tuple<int, int, Color>>& zBuffer, int y) 
{
	for(auto line: zBuffer) {
		int startx = std::get<0>(line);
		int endx = std::get<1>(line);
		Color color = std::get<2>(line);
		
		for(int x = startx; x <= endx; x++) {
			setPixel(x, y, color);
		}
	}
}
