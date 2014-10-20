#ifndef __PEOPLECLASS
#define __PEOPLECLASS

#include <string>		//string usage
#include <fstream>		//file usage
#include <iostream>		//standard i/o
#include "family.h"

using namespace std;

//class People extends class Family
class People : public Family
{
private: 
	string personName;
	string personStreet;
	string personCity;
	string personState;
	string personZip;
	string staffFlag;
	string activityFlags;

public:
//Constructiors
	People();
//	People(string, string, string, string, 
//		   string, string, string, string);
//Destructor
	~People();
//Functions
	void PeopleShow();			//Good idea to be able to show what we have.
	string getActivityFlags();	//gets the activity flags
	string getStaffFlag();		//gets the staff flag
	string getPersonName();
	void fill();
//Operators
	friend ifstream & operator >> (ifstream &fIn, People &p);
	friend ofstream & operator << (ofstream &fOut, People &p);
	friend ostream & operator << (ostream &Strm, People &p);
	//People People::operator = (People &p);
	//bool People::operator == (People &p);
};

#endif
