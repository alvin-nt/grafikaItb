#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "Edge.hpp"
#include "Point.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

namespace Graphics {
	class Dictionary {
		private:
		std::vector<std::string> read;
		std::vector<struct assocArray_postProcess> finProduct;

		struct assocArray_preProcess {
			std::string id;
			std::vector<std::string> coords;
		};
		struct assocArray_postProcess {
			std::string id;
			std::vector<Edge> edges; //change type to edges later
		};
		
		
		std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems);
		std::vector<std::string> split(const std::string &s, char delim);
		
		public:
		Dictionary();
		~Dictionary();
		void print();
	};
}

#endif
