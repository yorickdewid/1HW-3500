#ifndef __ACTIVITYCLASS
#define __ACTIVITYCLASS

#include <string>		//string usage
#include <fstream>		//file usage
#include <iostream>

using namespace std;

class Activity
{
private:
	string activityNum;
	string activityName;
	string activityDescription;
	string activityStaff;
	
public:
//Constructors
	Activity();
//Destructor
	~Activity();
//Functions
	void showActivity();
	void fill();
	string GetActivityName();
//Operators
	friend ostream & operator << (ostream &Strm, Activity &a);
	friend ifstream & operator >> (ifstream &fIn, Activity &a);
	friend ofstream & operator << (ofstream &fOut, Activity &a);

};

#endif
