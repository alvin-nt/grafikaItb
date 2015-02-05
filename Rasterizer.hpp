#ifndef RASTERIZER_H_
#define RASTERIZER_H_

#include "Singleton.hpp"
#include "Types.hpp"
#include "ShapeFillable.hpp"

#include "Color.hpp"

#include <vector>

namespace Graphics {
	enum Mode {TEXT, GRAPHICS};
	
	void clearScreen();
	
	/**
	 * Class that represents the screen drawer
	 * 
	 * Handles the terminal, the framebuffer, and the {@link Shape}s that
	 * are on the screen
	 */ 
	class Rasterizer {
		enum FbMapMode {PAN, DOUBLE, SINGLE}; // check mapping mode of the framebuffer
	private:
		// need to check this, so that only one raster can be instantiated at a time
		// for the sake of singletons~
		static bool instantiated;
		
		// file descriptors
		int fdTty;
		int fdFramebuffer;
		
		byte *ptrFramebuffer;
		byte *ptrBackbuffer;
		
		Mode mode;
		
		// background color for the terminal
		Color background;
		
		ScreenInfoFix finfo;
		ScreenInfoVar vinfo;
		
		long screenSize;
		
		// mode of the mapping, used for determining to where the screen
		// would be drawn
		FbMapMode mapMode;
	public:
		//std::vector<Shape*> shapes; ... need to handle or not?
	public:
		Rasterizer();
		~Rasterizer();
		
		/**
		 * Changes the terminal mode
		 * 
		 * @param mode the terminal mode, defined in {@link Mode}
		 */
		void setMode(Mode mode);
		
		Mode getMode() const;
		
		const Color &getBackground() const;
		void setBackground(const Color &color);
		
		inline void draw(const Shape *shape);
		inline void draw(const ShapeFillable *shape, bool fill = false);
		
		inline void destroy(Shape *shape);
		
		long getScreenSize() const;
		
		inline void update();
		
		inline const byte *getFramebuffer() const;
		
		
	protected:
		long getLocation(int x, int y);
		
		inline void swapBuffers();
		
	private:
		void initFramebuffer();
	};

	typedef Singleton<Rasterizer> Screen; // call Screen when needed
}

#endif
