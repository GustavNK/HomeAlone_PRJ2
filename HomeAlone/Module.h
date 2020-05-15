#pragma once
#include <string>;

using namespace std;

class Module
{
public:
	Module(string type,string x10_id);

	//Getter
	Virtuel string getType()const; 

	//Setter

private: 
	string _type;
	string _x10_id;

};

