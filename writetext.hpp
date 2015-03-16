#ifndef writetext_H_
#define writetext_H_

#include "Drawable.hpp"
#include "Point.hpp"
#include "Edge.hpp"
#include "Color.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

namespace Graphics {
	/**
	 * Class that represents a line
	 **/
	class writetext : public Drawable {
	private:
		float weight;
		string text;
		int fontsize;
		int posx;
		int posy;
		vector<string> vbuildcharacter; //Vector penampung readfile
		vector< vector<Edge> > vcharacter; //Vector setiap character;untuk i= 0 adalah A

	public:
		writetext(string text,int fontsize,float weight,int x,int y);
		~writetext();
		void move(int dx,int dy);
		int String2Int(const std::string& str);
		void ReadFromFile(string filename);
		void Check();
		void Allocatechar();
	protected:
		void draw() const;
	};

}

#endif

