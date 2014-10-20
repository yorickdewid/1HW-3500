#include "people.h"		//my People class header

People::People(){}

//Default Destructor
People::~People(){}

//Pre:	Data present, but the program can handle it if their is none.
//Post: All people are displayed on the screen
//Input:None
void People::PeopleShow()
{
	cout << endl;
	cout << "Family Number:     "<< familyNum << endl;
	cout << "Name:             " << personName << endl;
	cout << "Street Address:   " << personStreet << endl;
	cout << "City:             " << personCity << endl;
	cout << "State:            " << personState << endl;
	cout << "Zip:              " << personZip << endl;
	cout << "Staff?:           " << staffFlag << endl;
	cout << "Activity Numbers: " << activityFlags << endl;
	cout << endl;
}

//Pre:	Data present, but the program can handle it if their is none.
//Post: Returns the private member activityFlags as a string
//Input:None
string People::getActivityFlags(){return activityFlags;}

//Pre:	Data present, but the program can handle it if their is none.
//Post: Returns the private member staffFlag as a string
//Input:None
string People::getStaffFlag(){return staffFlag;}

//Pre:	Data present, but the program can handle it if their is none.
//Post: Returns the private member personName as a string
//Input:None
string People::getPersonName(){return personName;}

//Pre:	None
//Post: Fills up an instance of People with data from the keyboard
//Input:The fields of people
void People::fill()
{	
	string clear_buffer;	//It is a mystery why this was needed.

	cout << "Enter Family Number.\n: ";
	getline(cin,clear_buffer);
	cout << "Enter the person's Name.\n: ";
	getline(cin,familyNum);
	cout << "Enter the Street Address.\n: ";
	getline(cin,personName);
	cout << "Enter the City.\n: ";
	getline(cin,personStreet);
	cout << "Enter the State.\n: ";
	getline(cin,personCity);
	cout << "Enter the Zip Code.\n: ";
	getline(cin,personState);
	cout << "Enter the whether they are a staff member (yes or no).\n: ";
	getline(cin,personZip);
	cout << "Enter the Activity Numbers of the Person.\n: ";
	getline(cin,staffFlag);
	cout << "\nData captured.  Press Enter to continue ...\n";
	getline(cin,activityFlags);

	//This just makes the data "look" more like the data in the data file.
	// Note that everything works fine without this step.
	personName = " " + personName; 
	personStreet = " " + personStreet; 
	personCity = " " + personCity;
	personState = " " + personState; 
	personZip = " " + personZip; 
	staffFlag = " " + staffFlag;
	activityFlags = " " + activityFlags;
}

//Pre:	File open
//Post: Populate an instance of People with data from a file
//Input:None
ifstream & operator >> (ifstream &Infile, People &p)
{
	getline(Infile, p.familyNum, ',');
	getline(Infile, p.personName, ',');
	getline(Infile, p.personStreet, ',');
	getline(Infile, p.personCity, ',');
	getline(Infile, p.personState, ',');
	getline(Infile, p.personZip, ',');
	getline(Infile, p.staffFlag, ',');
	getline(Infile, p.activityFlags, '\n');
	return Infile; //Not always needed
}

//Pre:	File open
//Post: Saves an instance of People to a data file
//Input:None
ofstream & operator << (ofstream &Outfile, People &p)
{
	Outfile << p.familyNum + ", "
			+ p.personName + ", "
			+ p.personStreet + ", "
			+ p.personCity + ", "
			+ p.personState + ", "
			+ p.personZip + ", "
			+ p.staffFlag + ", "
			+ p.activityFlags + "\n";
	return Outfile;
}

//Pre:	Data present in People instance, but nothing bad happen if not.
//Post: Display an instance of People to the screen
//Input:None
ostream & operator << (ostream &Stream, People &p)
{
	cout << endl;
	cout << "Family Number:     "<< p.familyNum << endl;
	cout << "Name:             " << p.personName << endl;
	cout << "Street Address:   " << p.personStreet << endl;
	cout << "City:             " << p.personCity << endl;
	cout << "State:            " << p.personState << endl;
	cout << "Zip:              " << p.personZip << endl;
	cout << "Staff?:           " << p.staffFlag << endl;
	cout << "Activity Numbers: " << p.activityFlags << endl;
	cout << endl;
	return Stream;
}

