#include "Dictionary.hpp"

using namespace Graphics;

Dictionary::Dictionary() {
	std::vector<struct assocArray_preProcess> preProcess;
	
	std::ifstream file;
	file.open("dictionary.txt", std::ios::in);
	std::string process;
	while (getline(file, process)) {
		read.push_back(process);
	}
	for (int i = 0; i < read.size(); i++) {
		process = read[i].substr(2);
		struct assocArray_preProcess temp;
		temp.id = read[i].substr(0,1);
		temp.coords = split(process, ';');
		preProcess.push_back(temp);
	}
	
	for (int i = 0; i < preProcess.size(); i++) {
		struct assocArray_postProcess tempP;
		tempP.id = preProcess[i].id;
		for(int j = 0; j < preProcess[i].coords.size(); j++) {
			std::vector<std::string> temp_vec = split(preProcess[i].coords[j], ',');
			int x1,x2,y1,y2;
			x1 = atoi(temp_vec[0].c_str());
			y1 = atoi(temp_vec[1].c_str());
			x2 = atoi(temp_vec[2].c_str());
			y2 = atoi(temp_vec[3].c_str());
			Edge *e1 = new Edge(x1, y1, Color::WHITE, x2, y2, Color::WHITE, 1.0f);
			tempP.edges.push_back(e1);
		}
		finProduct.push_back(tempP);
	}
	
	/*for(int i = 0; i < finProduct.size(); i++) {
		std::cout << finProduct[i].id << " sp " ;
		for (int j = 0; j < finProduct[i].edges.size(); j++) {
			std::cout << finProduct[i].edges[j] << " la ";
		}
		std::cout << std::endl;
	}*/
}

Dictionary::~Dictionary() {
}

void Dictionary::print() {

}

std::vector<std::string> Dictionary::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> Dictionary::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
