#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "ShapeFillable.hpp"
#include "Point.hpp"

namespace Graphics {
	/**
	 * Class that represents a Ellipse
	 **/
	class Ellipse : public ShapeFillable {
	private:
		Point center;
		float theta;
		float jari;
		float weight;
		float smash;
	public:
		Ellipse(const Point& center,float theta,float jari,float weight,float smash);
		Ellipse(int x1, int y1, const Color& c1,float theta,float jari,float weight,float smash);
		Ellipse(const Ellipse&);
		~Ellipse();
		
		Ellipse& operator=(const Ellipse&);
		
		friend bool operator!=(const Ellipse& lhs, const Ellipse& rhs);
		
		friend bool operator==(const Ellipse& lhs, const Ellipse& rhs);
		
		/**
		 * Gets the center point of the Ellipse
		 * 
		 * @return center point
		 **/
		const Point& getCenter() const;
		
		/**
		 * Sets the center point of the Ellipse
		 * 
		 * @param point the new point
		 **/
		void setCenter(const Point& point);
		
		/**
		 * Gets the theta of the Ellipse
		 * 
		 * @return jari float
		 **/
		float getTheta();
		
		/**
		 * Sets the Theta of the Ellipse
		 * 
		 * @param point the new point
		 **/
		void setTheta(float theta);
		
		/**
		 * Gets the jari of the Ellipse
		 * 
		 * @return jari float
		 **/
		float getJari();
		
		/**
		 * Sets the radius point of the Ellipse
		 * 
		 * @param point the new point
		 **/
		void setJari(float jari);
		
		
		/**
		 * Gets the weight parameter of the Ellipse
		 * 
		 * @return weight
		 **/
		float getWeight();
		
		/**
		 * Sets the weight parameter of the Ellipse
		 * 
		 * @param weight the new weight
		 **/
		void setWeight(float weight);
		
			
		/**
		 * Gets the smash of the Ellipse
		 * 
		 * @return smash float
		 **/
		float getSmash();
		
		/**
		 * Sets the smash value of the Ellipse
		 * 
		 * @param int new smash value
		 **/
		void setSmash(int smash);
		
		
		double getLength() const;
		float getLengthFloat() const;
		
		void rotate(int degree);
		
		void move(int dx, int dy);
		
		void scale(int scale);
	
	protected:
		void scale(int x);
		void drawFill() const;
		void drawOutline() const;
	};

}

#endif

