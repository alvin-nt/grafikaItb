#include "Color.hpp"

#include "Rasterizer.hpp"

using namespace Graphics;

const Color Color::RED = { 0xff, 0x00, 0x00, 0x00 };
const Color Color::GREEN = { 0x00, 0xff, 0x00, 0x00 };
const Color Color::BLUE = { 0x00, 0x00, 0xff, 0x00 };
const Color Color::WHITE = { 0xff, 0xff, 0xff, 0x00 };
const Color Color::BLACK = { 0x00, 0x00, 0x00, 0x00 };

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

bool Graphics::operator!=(const Color& lhs, const Color& rhs) {
	return !(lhs == rhs);
}

bool Graphics::operator==(const Color& lhs, const Color& rhs) {
	return (lhs.red == rhs.red &&
			lhs.green == rhs.green &&
			lhs.blue == rhs.blue &&
			lhs.alpha == rhs.alpha);
}

Color Graphics::operator+(const Color& lhs, const Color& rhs) {
	return Color(lhs.red + rhs.red,
				lhs.green + rhs.green,
				lhs.blue + rhs.blue,
				lhs.alpha + rhs.alpha);
}

Color Graphics::operator-(const Color& lhs, const Color& rhs) {
	return Color(lhs.red - rhs.red,
				lhs.green - rhs.green,
				lhs.blue - rhs.blue,
				lhs.alpha - rhs.alpha);
}

Color& Graphics::operator+=(Color& lhs, const Color& rhs) {
	lhs.red += rhs.red;
	lhs.green += rhs.green;
	lhs.blue += rhs.blue;
	lhs.alpha += rhs.alpha;
	
	return lhs;
}

Color& Graphics::operator-=(Color& lhs, const Color& rhs) {
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
	
	return (color.red << vinfo.red.offset) |
		(color.green << vinfo.green.offset) |
		(color.blue << vinfo.blue.offset) |
		(color.alpha << vinfo.transp.offset);
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
