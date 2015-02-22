#ifndef COLOR_H_
#define COLOR_H_

#include "Types.hpp"

namespace Graphics {
	class Color {
	public: // direct access to elements, for reducing funCall overhead
		byte red;
		byte green;
		byte blue;
		byte alpha; // for transparency
		
		// some default colors
		static const Color RED;
		static const Color GREEN;
		static const Color BLUE;
		static const Color WHITE;
		static const Color BLACK;
		static const Color TRANSPARENT;
	public:
		Color(byte red = 0, byte green = 0, byte blue = 0, byte alpha = 0);
		Color(Pixel pix);
		Color(const Color&);
		
		friend bool operator!=(const Color& lhs, const Color& rhs);
		friend bool operator==(const Color& lhs, const Color& rhs);
			
		friend Color operator+(const Color& lhs, const Color& rhs);
		friend Color operator-(const Color& lhs, const Color& rhs);
			
		friend Color& operator+=(Color& lhs, const Color& rhs);
		friend Color& operator-=(Color& lhs, const Color& rhs);
		
		Color& operator=(const Color& rhs);
		
		Pixel toPixel() const;
		
		static Pixel toPixel(const Color& color);
		static Color fromPixel(Pixel pixel);
	};
}

#endif
