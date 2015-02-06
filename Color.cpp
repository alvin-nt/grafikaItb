#include "Color.hpp"

#include "Rasterizer.hpp"

using namespace Graphics;

const Color Color::RED = Color(0xff, 0x00, 0x00, 0x00);
const Color Color::GREEN = Color(0x00, 0xff, 0x00, 0x00);
const Color Color::BLUE = Color(0x00, 0x00, 0xff, 0x00);
const Color Color::WHITE = Color(0xff, 0xff, 0xff, 0x00);
const Color Color::BLACK = Color(0x00, 0x00, 0x00, 0x00);

Color::Color(byte red, byte green, byte blue, byte alpha)
	: red(red), green(green), blue(blue), alpha(alpha)
{
}

Color::Color(Pixel pix) {
	*this = fromPixel(pix);
}

Color::Color(const Color& color) {
	*this = color;
}

Color& Color::operator=(const Color& rhs) {
	if(this != &rhs) {
		red = rhs.red;
		green = rhs.green;
		blue = rhs.blue;
		alpha = rhs.alpha;
	}
	
	return *this;
}

bool operator!=(const Color& lhs, const Color& rhs) {
	return !(lhs == rhs);
}

bool operator==(const Color& lhs, const Color& rhs) {
	return (lhs.red == rhs.red &&
			lhs.green == rhs.green &&
			lhs.blue == rhs.blue &&
			lhs.alpha == rhs.alpha);
}

Color operator+(const Color& lhs, const Color& rhs) {
	return Color(lhs.red + rhs.red,
				lhs.green + rhs.green,
				lhs.blue + rhs.blue,
				lhs.alpha + rhs.alpha);
}

Color operator-(const Color& lhs, const Color& rhs) {
	return Color(lhs.red - rhs.red,
				lhs.green - rhs.green,
				lhs.blue - rhs.blue,
				lhs.alpha - rhs.alpha);
}

Color& operator+=(const Color& lhs, const Color& rhs) {
	lhs.red += rhs.red;
	lhs.green += rhs.green;
	lhs.blue += rhs.blue;
	lhs.alpha += rhs.alpha;
	
	return lhs;
}

Color& operator+=(const Color& lhs, const Color& rhs) {
	lhs.red -= rhs.red;
	lhs.green -= rhs.green;
	lhs.blue -= rhs.blue;
	lhs.alpha -= rhs.alpha;
	
	return lhs;
}

Pixel Color::toPixel() const {
	return toPixel(*this);
}

Pixel Color::toPixel(const Color& color) {
	ScreenInfoVar vinfo = Screen::instance()->getVarInfo();
	
	return (red << vinfo.red.offset) |
		(green << vinfo.green.offset) |
		(blue << vinfo.blue.offset) |
		(alpha << vinfo.transp.offset);
}

Color Color::fromPixel(Pixel pixel) {
	Color color;
	
	ScreenInfoVar vinfo = Screen::instance()->getVarInfo();
	
	Pixel mask, seed = (1 << 8);

	mask = (seed << vinfo.red.offset);
	color.red = (byte)((pixel >> vinfo.red.offset) & mask);

	mask = (seed << vinfo.green.offset);
	color.green = (byte)((pixel >> vinfo.green.offset) & mask);

	mask = (seed << vinfo.blue.offset);
	color.blue = (byte)((pixel >> vinfo.blue.offset) & mask);

	mask = (seed << vinfo.transp.offset);
	color.alpha = (byte)((pixel >> vinfo.transp.offset) & mask);
	
	return color;
}
