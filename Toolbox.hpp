#ifndef TOOLBOX_H_
#define TOOLBOX_H_

#include "ShapeFillable.hpp"
#include "Point.hpp"
#include "Color.hpp"
#include "Rectangle.hpp"

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class Toolbox : public ShapeFillable {
	private:
		Rectangle * rect[4];
	public:
		Toolbox();
		~Toolbox();
	
	protected:
		void drawOutline() const;
		void drawFill() const;
	};

}

#endif
