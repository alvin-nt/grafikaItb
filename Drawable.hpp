#ifndef DRAWABLE_H_
#define DRAWABLE_H_

namespace Graphics {
	
	/**
	 * Interface for drawable objects
	 */
	class Drawable {
	public:
		virtual void draw() const = 0;
	};
}

#endif
