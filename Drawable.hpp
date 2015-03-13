#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "Rasterizer.hpp"
namespace Graphics {
	
	/**
	 * Abstract class for drawable objects
	 * 
	 * Also implicitly declares movable
	 */
	class Drawable {
		friend class Rasterizer;
	public:
		const static int SCREEN_X_MIN; // minimum screen width
		static int SCREEN_X_MAX; // maximum screen width
		const static int SCREEN_Y_MIN; // minimum screen height
		static int SCREEN_Y_MAX; // maximum screen height
		
	protected:
	
		bool hide = false;
		
	public:
		virtual ~Drawable() {
			
		}
	
		/**
		 * Moves the object
		 * 
		 * @param dx movement along the horizonal line
		 * @param dy movement along the vertical line
		 **/
		virtual void move(int dx, int dy) = 0;
		
		bool isHidden() const {
			return hide;
		}
		
		void setHidden(bool hide) {
			this->hide = hide;
		}
		
	protected:
		/**
		 * Draws the object
		 **/
		virtual void draw() const = 0;
	};
}

#endif
