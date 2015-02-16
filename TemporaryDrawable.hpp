#ifndef TEMPORARY_DRAWABLE_H_
#define TEMPORARY_DRAWABLE_H_

#include "Drawable.hpp"

namespace Graphics {
	class TemporaryDrawable : public Drawable {
	protected:
		bool drawn; // true if the object has been drawn on the screen
		int drawSteps; // number of draws/frames before the object should be destroyed
		
	public:
		/**
		 * Gets the number of drawing steps
		 * @return number of drawing steps
		 **/
		int getDrawSteps() const;
		
		/**
		 * Sets the number of drawing steps
		 * @param steps the number of drawing steps
		 **/
		void setDrawSteps(int steps);
		
		/**
		 * Checks whether the object is expired
		 **/
		bool isExpired() const;
	};
}

#endif
