#include "activity.h"	//my Activity class header

//Creats a new activity instance (not useful in this assignment)
Activity::Activity(){}

//Default destructor
Activity::~Activity(){}

//The show is mainly for me during the coding process.
//Pre:	Data present
//Post: Display an instance of activity w/o an operator
//Input:None
void Activity::showActivity()
{
    cout << "\nActivity Number: " << activityNum
	     << "\nActivity Name: " << activityName
	     << "\nDescription: " << activityDescription
	     << "\nStaff Member: " << activityStaff << endl;
}

//Pre:	None
//Post: Populate an instance of Activity with keyboard data
//Input:None
void Activity::fill()
{	
	string clear_buffer;	//It is a mystery why this was needed.

	cout << "Enter Activity Number.\n: ";
	getline(cin,clear_buffer);

	cout << "Enter the Activitie's Name.\n: ";
	getline(cin,activityNum);

	cout << "Enter the Description of the Activity.\n: ";
	getline(cin,activityName);

	cout << "Enter the Staff Memeber's Name in charge.\n: ";
	getline(cin,activityDescription);

	cout << "\nData captured.  Press Enter to continue ...\n";
	getline(cin,activityStaff);

	//This just makes the data "look" more like the data in the data file.
	// Note that everything works fine without this step.
	activityName = " " + activityName; 
	activityName = " " + activityName; 
	activityDescription = " " + activityDescription;
	activityStaff = " " + activityStaff; 
}

//Pre:	None
//Post: returns private member activityName as a string
//Input:None
string Activity::GetActivityName(){return activityName;}

//Pre:	None
//Post: Displays an instance of Activity
//Input:None
ostream & operator << (ostream &Stream, Activity &a)
{
    cout << endl
		 << "Activity Number: " << a.activityNum << endl
	     << "Activity Name: " << a.activityName << endl
	     << "Description: " << a.activityDescription << endl
	     << "Staff Member: " << a.activityStaff << endl
		 << endl;
	return Stream;
}

//Pre:	None
//Post: Fills up an instance of Activity with data a file
//Input:None
ifstream & operator >> (ifstream &Infile, Activity &a)
{
	getline(Infile, a.activityNum, ',');
	getline(Infile, a.activityName, ',');
	getline(Infile, a.activityDescription, ',');
	getline(Infile, a.activityStaff, '\n');
	return Infile;
}

//Pre:	None
//Post: Display an instance of activity
//Input:None
ofstream & operator << (ofstream &Outfile, Activity &a)
{
	Outfile << a.activityNum + ", "
			+ a.activityName + ", "
			+ a.activityDescription + ", "
			+ a.activityStaff + "\n";
	return Outfile;
}
