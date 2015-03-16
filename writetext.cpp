#include "writetext.hpp"
#include <cmath>
#include <string>

using namespace Graphics;

writetext::writetext(string text,int fontsize,float weight,int x,int y)
{
	this->weight = weight;
	this->text = text;
	this->fontsize = fontsize;
	this->posx = x;
	this->posy = y;
}

writetext::~writetext(){
	
}
void writetext::move(int dx, int dy){
	//TBD
}
void writetext::draw() const{
	int counterx = 0;
	int countery = 0;
	Edge temp;
	for(int i = 0;i <= text.length()-1;i++)
	{
		if(text[i] == 's')
		{
			for(int j = 0;j<=vcharacter[0].size()-1;j++)
			{
				temp = (vcharacter.at(0)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == 't')
		{
			for(int j = 0;j<=vcharacter[1].size()-1;j++)
			{
				temp = (vcharacter.at(1)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == 'a')
		{
			for(int j = 0;j<=vcharacter[2].size()-1;j++)
			{
				temp = (vcharacter.at(2)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'r')
		{
			for(int j = 0;j<=vcharacter[3].size()-1;j++)
			{
				temp = (vcharacter.at(3)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == 'e')
		{
			for(int j = 0;j<=vcharacter[4].size()-1;j++)
			{
				temp = (vcharacter.at(4)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == 'n')
		{
			for(int j = 0;j<=vcharacter[5].size()-1;j++)
			{
				temp = (vcharacter.at(5)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == 'd')
		{
			for(int j = 0;j<=vcharacter[6].size()-1;j++)
			{
				temp = (vcharacter.at(6)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'c')
		{
			for(int j = 0;j<=vcharacter[8].size()-1;j++)
			{
				temp = (vcharacter.at(8)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == 'y')
		{
			for(int j = 0;j<=vcharacter[11].size()-1;j++)
			{
				temp = (vcharacter.at(11)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'o')
		{
			for(int j = 0;j<=vcharacter[12].size()-1;j++)
			{
				temp = (vcharacter.at(12)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'u')
		{
			for(int j = 0;j<=vcharacter[13].size()-1;j++)
			{
				temp = (vcharacter.at(13)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'w')
		{
			for(int j = 0;j<=vcharacter[14].size()-1;j++)
			{
				temp = (vcharacter.at(14)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'i')
		{
			for(int j = 0;j<=vcharacter[10].size()-1;j++)
			{
				temp = (vcharacter.at(10)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == '?')
		{
			for(int j = 0;j<=vcharacter[15].size()-1;j++)
			{
				temp = (vcharacter.at(15)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == '!')
		{
			for(int j = 0;j<=vcharacter[16].size()-1;j++)
			{
				temp = (vcharacter.at(16)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == 'z')
		{
			for(int j = 0;j<=vcharacter[17].size()-1;j++)
			{
				temp = (vcharacter.at(17)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == 'p')
		{
			for(int j = 0;j<=vcharacter[18].size()-1;j++)
			{
				temp = (vcharacter.at(18)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'h')
		{
			for(int j = 0;j<=vcharacter[19].size()-1;j++)
			{
				temp = (vcharacter.at(19)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'g')
		{
			for(int j = 0;j<=vcharacter[20].size()-1;j++)
			{
				temp = (vcharacter.at(20)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'l')
		{
			for(int j = 0;j<=vcharacter[21].size()-1;j++)
			{
				temp = (vcharacter.at(21)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'k')
		{
			for(int j = 0;j<=vcharacter[22].size()-1;j++)
			{
				temp = (vcharacter.at(22)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == 'v')
		{
			for(int j = 0;j<=vcharacter[23].size()-1;j++)
			{
				temp = (vcharacter.at(23)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		
		if(text[i] == '.')
		{
			for(int j = 0;j<=vcharacter[24].size()-1;j++)
			{
				temp = (vcharacter.at(24)).at(j);
				temp.move2(counterx,countery);
				temp.draw();
			}
			counterx += 30;
		}
		if(text[i] == ' ')
		{
			counterx += 30;
		}
		if(text[i] == '\n')
		{
			counterx = 0;
			countery += 30;
		}
	}/*
	int i = 1;
	counterx = 0;
		Edge temp;
		
		for(int j = 0;j<=vcharacter[i].size()-1;j++)
		{
			((vcharacter.at(i)).at(j)).draw();
			
			//temp = (vcharacter.at(1)).at(j);
			//temp.move2(counterx,countery);
			//temp.draw();
		}*/
}

void writetext::Check() {
	//for(int i = 0;i <= vcharacter.size()-1;i++)
	//{
		/*switch(text[i])
		{
			case 't': 
				for(int j = 0;j<=vcharacter[i].size()-1;j++)
				{
					(vcharacter[4].at(j)).draw();
				}
				break;
		}*/
		int i = 3;
		for(int j = 0;j<=vcharacter[i].size()-1;j++)
		{
			cout<<"Character "<<i<<endl;
			//((vcharacter.at(i)).at(j)).Print();
		}
	//}
}

int writetext::String2Int(const std::string& str)
{
	int result = 0;
    std::string::const_iterator i = str.begin();
 
    if (i == str.end())
        return -999;
 
    bool negative = false;
 
    if (*i == '-')
    {
        negative = true;
        ++i;
 
        if (i == str.end())
            return -999;;
    }
 
    result = 0;
 
    for (; i != str.end(); ++i)
    {
        if (*i < '0' || *i > '9')
            return -999;;
 
        result *= 10;
        result += *i - '0';
    }
 
    if (negative)
    {
        result = -result;
    }
 
    return result;
}

void writetext::ReadFromFile(string filename){
	  ifstream myfile (filename.c_str());
	  string line;
	if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
		vbuildcharacter.push_back(line.substr(2,line.length()));
    }
    myfile.close();
  }
}

void writetext::Allocatechar(){
	std::string delimiter = ",";
	size_t pos = 0;
	int token[50];
	string linez;

	for(int i =0;i<vbuildcharacter.size();i++){
		linez = vbuildcharacter.at(i);
		//cout<<linez<<endl;
		int ctoken = 0;
		while (linez.length() >1 && ctoken <20)
		{
			pos = linez.find(delimiter);
			token[ctoken] = atoi((linez.substr(0, pos)).c_str());
			linez = linez.substr(pos+delimiter.length(),linez.length());
			ctoken++;
		}
		vector<Edge> vtemp;
		for(int j = 0;j<=ctoken-1;j+=4)
		{
			Edge temp(token[j]+posx,token[j+1]+posy,Color::WHITE,token[j+2]+posx,token[j+3]+posy,Color::WHITE,0.05f);
			vtemp.push_back(temp);
		}
		vcharacter.push_back(vtemp);
	}
}
