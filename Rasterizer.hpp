#ifndef RASTERIZER_H_
#define RASTERIZER_H_

#include "Singleton.hpp"
#include "Types.hpp"
#include "Drawable.hpp"
#include "ShapeFillable.hpp"

#include "Color.hpp"

#include <vector>

namespace Graphics {
	enum Mode {TEXT, GRAPHICS};
	
	void clearScreen();
	
	/**
	 * Class that represents the screen drawer
	 * 
	 * Handles the terminal, the framebuffer, and the {@link Drawable}s that
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
		std::vector<Drawable*> drawObject; // for Z-index
	public:
		Rasterizer();
		~Rasterizer();
		
		/**
		 * Changes the terminal mode
		 * 
		 * @param mode the terminal mode, defined in {@link Graphics::Mode}
		 */
		void setMode(Mode mode);
		
		/**
		 * Gets the current terminal mode
		 * 
		 * @return {@link Graphics::mode}
		 */
		Mode getMode() const;
		
		/**
		 * Sets the background color of the screen
		 * 
		 * @return background
		 */
		const Color &getBackground() const;
		
		/**
		 * Sets the background color of the screen
		 * 
		 * @param color new screen color
		 */
		void setBackground(const Color &color);
		
		/**
		 * Gets the variable screen information struct, such as 
		 * current size of the screen, bits per pixel, and color offsets
		 * 
		 * @return vinfo
		 */
		inline const ScreenInfoVar& getVarInfo() const;
		
		/**
		 * Gets the fixed screen information struct, such as
		 * screen clocks and refresh rate
		 * 
		 * @return finfo
		 */
		inline const ScreenInfoFix& getFixInfo() const;
		
		/**
		 * Gets the memory offset for the framebuffer at a certain coordinate
		 * 
		 * @param x the horizontal coordinate
		 * @param y the vertical coordinate
		 * 
		 * @return framebuffer offset for coordinate(x, y)
		 */
		inline long getDrawLocation(int x, int y);
		
		/**
		 * Draws a drawable object onto the screen
		 * 
		 * @param shape drawable object
		 **/
		inline void draw(const Drawable *shape);
		
		/**
		 * Put a color in the (x, y) coordinate
		 * 
		 * @param x the horizontal coordinate
		 * @param y the vertical coordinate
		 * @param pixel the pixel number
		 **/
		inline void setPixel(int x, int y, Pixel pixel);
		
		/**
		 * Put a color in the (x, y) coordinate
		 * 
		 * @param x the horizontal coordinate
		 * @param y the vertical coordinate
		 * @param color the color object
		 **/
		inline void setPixel(int x, int y, const Color& color);
		
		/**
		 * Draws a shape onto the screen, with the apropriate fill mode.
		 * 
		 * @param shape fillable object
		 * @param fill draws the filled shape (true) or only the outline (false). Defaults to false.
		 */
		inline void draw(const ShapeFillable *shape, bool fill = false);
		
		/**
		 * Deletes the drawable object from the screen and from the memory
		 */
		inline void destroy(Drawable *drawable);
		
		/**
		 * Refreshes the screen:
		 * 
		 * repaints all elements onto the backBuffer, then
		 * draws them to the screen
		 **/
		inline void refresh();
		
		/**
		 * Gets the current screen size
		 * 
		 * @return current screen size
		 */
		long getScreenSize() const;
		
		/**
		 * Updates the screen. Used for swapping the buffers
		 * 
		 * Wraps the call to swapBuffers()
		 * 
		 * if MapMode is set to SINGLE, this function does nothing.
		 */
		inline void update();
		
		/**
		 * Gets the apropriate pointer to framebuffer
		 * 
		 * @return pointer to framebuffer
		 */
		inline const byte *getFramebuffer() const;
		
	protected:
		inline void swapBuffers();
		
	private:
		/**
		 * Initializes the framebuffer
		 **/
		void initFramebuffer();
		
		inline void drawBackground();
	};

	typedef Singleton<Rasterizer> Screen; // call Screen when needed
}

#endif
