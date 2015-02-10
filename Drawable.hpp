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
	protected:
		const static int SCREEN_X_MIN;
		static int SCREEN_X_MAX;
		const static int SCREEN_Y_MIN;
		static int SCREEN_Y_MAX;
	
		bool hide = false;
	public:
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
