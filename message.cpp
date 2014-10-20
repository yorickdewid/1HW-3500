#include "message.h"	//My menu header

//Default constructor
Message::Message(){}

//Default destructor
Message::~Message(){}

//Pre:	None
//Post: Displays message and returns the choice as a character
//Input:The char choice
char Message::LoadMenu()
{	char choice;
	cout << "Load Menu\n"
		 << "(1) Open a database\n"
		 << "(2) Create database.\n:";
	cin >> choice;
	cout << endl;
	return choice;
}

//Pre:	None
//Post: Displays message and returns the choice as a character
//Input:The char choice
char Message::InfoMenu()
{	char choice;
	cout << "\n\n~Information Menu~\n"
		 << "(1) Print all summer camp data to the screen.\n"
		 << "(2) List everyone from one family.\n"
		 << "(3) Print all camp activity data to the screen.\n"
		 << "(4) List everyone participating in an event.\n"
		 << "(5) List all the staff members.\n"
		 << "(6) Add a person to the database.\n"
		 << "(7) Add an activity to the database.\n"
		 << "(8) Save the current data files.\n"
		 << "(9) Print the information on one person.\n"
		 << "(A) Print the information on one activity.\n"
		 << "(Q) Exit the program.\n:";
	cin >> choice;
	return choice;
}

//Pre:	None
//Post: Displays message and returns the choice as a string
//Input:The string choice
string Message::AskFamily()
{
	string choice;
	cout << "\nEnter the family number of the campers you want" <<
		    "to list.\n:";
	cin >> choice;
	return choice;
}

//Pre:	None
//Post: Displays message and returns the choice as a string
//Input:The string choice
string Message::AskEvent()
{
	string choice;
	cout << "\nEnter the event number of the event you want" <<
		    " a list of particapents for.\n:";
	cin >> choice;
	return choice;
}

//Pre:	None
//Post: Displays message and returns the choice as a string
//Input:The string choice
string Message::AskPersonName()
{
	string fname, lname;

	cout << "\nEnter the first name person's name you want information about.\n";
	cin >> fname;

	cout << "\nEnter the last name person's name you want information about.\n";
	cin >> lname;

	cout << "\nPress Enter to continue ...\n";
	cin.ignore(1);

	return (fname + ' ' + lname);
}

//Pre:	None
//Post: Displays message and returns the choice as a string
//Input:The string choice
string Message::AskActivityName()
{
	string clear_buffer, temp;
	cout << "Enter the Activity Name you want information about.\n: ";
	getline(cin,clear_buffer);
	cout << "\nPress Enter to continue ...\n";
	getline(cin,temp);
	return temp;
}

//Pre:	None
//Post: Displays a message
//Input:None
void Message::Bye()
{ cout << "\n\n\nGoodbye!!\n\n\n"; }

//Pre:	None
//Post: Displays a message
//Input:None
void Message::Pause(int &i)
{	if(++i > 2)
	{	cout << "\nPress Enter to show more ...\n";
		cin.get();
		i = 0;
	}
}

//Pre:	None
//Post: Displays a message
//Input:None
void Message::FileErrorMessage()
{ cerr << "\nError!  Could not open that file!\n"; }
