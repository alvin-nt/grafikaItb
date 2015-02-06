#ifndef DRAWABLE_H_
#define DRAWABLE_H_

namespace Graphics {
	
	/**
	 * Abstract class for drawable objects
	 * 
	 * Also implicitly declares movable
	 */
	class Drawable {
	protected:
		bool hide = false;
	public:
		/**
		 * Moves the object
		 * 
		 * @param dx movement along the horizonal line
		 * @param dy movement along the vertical line
		 **/
		virtual inline void move(int dx, int dy) = 0;
		
		bool isHidden() const {
			return hide;
		}
		
		bool setHidden(bool hide) {
			this->hide = hide;
		}
		
	protected:
		/**
		 * Draws the object
		 **/
		virtual inline void draw() const = 0;
	};
}

#endif
