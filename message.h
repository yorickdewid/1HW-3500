#ifndef __MESSAGECLASS
#define __MESSAGECLASS

#include <string>		//string usage
#include <fstream>		//file usage
#include <iostream>		//standard i/o

using namespace std;

class Message
{
private: 
//Nothing really needed ... yet
public:
//Default constructor
	Message();
//Default destructor
	~Message();
//The initial load file menu.
	char LoadMenu();
	char InfoMenu();
	string AskFamily();
	string AskEvent();
	string AskPersonName();
	string AskActivityName();
	void Bye();
	void Pause(int &i);
	void FileErrorMessage();
};

#endif
