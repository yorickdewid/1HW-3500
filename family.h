#ifndef __FAMILYCLASS
#define __FAMILYCLASS

#include <string>		//string usage
#include <fstream>		//file usage
#include <iostream>		//standard i/o

using namespace std;

class Family
{
public:
//Variables
	string familyNum;	
//Constructor
	Family();
//Destructor
	~Family();
//Functions	
	string getFamilyNum();
};

#endif
