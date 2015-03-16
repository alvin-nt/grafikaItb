#include "Color.hpp"

#include "Rasterizer.hpp"

#include <iomanip>

namespace Graphics {
	Pixel createMask(unsigned a, unsigned b) {
		unsigned r = 0;
		for (unsigned i = a; i <= b; i++) {
			r |= 1 << i;
		}
		
		return r;
	}
	
	const Color Color::RED = { 0xff, 0x00, 0x00, 0x00 };
	const Color Color::GREEN = { 0x00, 0xff, 0x00, 0x00 };
	const Color Color::BLUE = { 0x00, 0x00, 0xff, 0x00 };
	const Color Color::WHITE = { 0xff, 0xff, 0xff, 0x00 };
	const Color Color::BLACK = { 0x00, 0x00, 0x00, 0x00 };
	const Color Color::TRANSPARENT = { 0x00, 0x00, 0x00, 0xff };
	const Color Color::YELLOW = { 0xff, 0xff, 0x00, 0x00 };
	const Color Color::ORANGE = { 0xff, 0xd7, 0x00, 0x00 };

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

	Color& operator+=(Color& lhs, const Color& rhs) {
		lhs.red += rhs.red;
		lhs.green += rhs.green;
		lhs.blue += rhs.blue;
		lhs.alpha += rhs.alpha;
		
		return lhs;
	}

	Color& operator-=(Color& lhs, const Color& rhs) {
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
		Pixel mask;

		mask = createMask(vinfo.red.offset, vinfo.red.offset + 8);
		color.red = (byte)((pixel & mask) >> vinfo.red.offset);

		mask = createMask(vinfo.green.offset, vinfo.green.offset + 8);
		color.green = (byte)((pixel & mask) >> vinfo.green.offset);

		mask = createMask(vinfo.blue.offset, vinfo.blue.offset + 8);
		color.blue = (byte)((pixel & mask) >> vinfo.blue.offset);

		mask = createMask(vinfo.transp.offset, vinfo.transp.offset + 8);
		color.alpha = (byte)((pixel & mask) >> vinfo.transp.offset);
		
		return color;
	}
	
	std::ostream& operator<<(std::ostream& out, const Color& color) {
		ScreenInfoVar vinfo = Screen::instance()->getVarInfo();
		
		out << "#" << std::hex 
					<< ((int)(color.red << vinfo.red.offset) |
					   (int)(color.blue << vinfo.blue.offset) |
					   (int)(color.green << vinfo.green.offset) |
					   (int)(color.alpha << vinfo.transp.offset))
					<< std::dec;

		return out;
	}
}
