#include <vector>		//vector containers
#include <map>			//map containers
#include <iterator>		//iterators for the containers
#include "people.h"		//my people class
#include "message.h"	//the various menus
#include "activity.h"   //my activties class

typedef vector<People> People_vector;			//A vector of people
typedef map<string, People_vector> Family_map;	//A map of people vector and family num
typedef vector<Activity> Activity_vector;		//A vectir if activities

using namespace std;

int main()
{//BEGIN MAIN
	int i=0;							//counter
	char choice = '\0';					//menu choices
	Family_map family;					//an instance of the families
	Activity_vector activities;			//an instance of the activities
	Message messages;					//the menu instance
	People_vector::iterator people_it;  //People iterator.
	Family_map::iterator family_it;		//Family iterator.
	Activity_vector::iterator act_it;	//Activity vector.
	People peopleBuffer;				//the temp people storage
	Activity activityBuffer;			//the temp activity storage
	string stringBuffer;				//temp string storage
	ifstream FamInfile;					//family input file instance
	ofstream FamOutfile;				//family ouput file instance
	ifstream ActInfile;					//activity input file instance
	ofstream ActOutfile;				//activity ouput file instance
	char filename[100];					//input output file names

	do	//Part One: what kind of file.
	{	choice = messages.LoadMenu();

		switch(choice)	//Decied whether to open a file or just start from scratch.
		{	case '1' :	cout <<"Type in the people file to open (or path with file):";
						cin >> filename;
						FamInfile.open(filename);
						if(!FamInfile)
						{	//Forces another try
							choice = -1;
							cout << "Not a file!\n\n";
							FamInfile.close();FamInfile.clear();cin.clear();
							break;
						}
						while(FamInfile >> peopleBuffer)
							family[peopleBuffer.getFamilyNum()].push_back(peopleBuffer);
						FamInfile.close();FamInfile.clear();cin.clear();

						cout <<"Type in the activity file to open (or path with file):";
						cin >> filename;
						ActInfile.open(filename);
						if(!ActInfile)
						{	//Forces another try
							choice = -1;
							cout << "Not a file!\n\n";
							ActInfile.close();ActInfile.clear();cin.clear();
							break;
						}
						while(ActInfile >> activityBuffer)
						  activities.push_back(activityBuffer);
						ActInfile.close();ActInfile.clear();cin.clear();

						break;
			case '2' :	break; //No file opened

			default  :	cout << "Not a choice!\n\n";
		}
	}while( !((choice == '1') || (choice == '2')) );

	do	//Part Two: what to do with the data accumulated.
	{	choice = messages.InfoMenu();

		switch(choice)
		{	//List every person and their data.
			case '1' :	for(family_it=family.begin();family_it!=family.end();++family_it)
						 for(people_it=family_it->second.begin();
						     people_it!=family_it->second.end();++people_it)
						 {	 cout << *people_it;
							 messages.Pause(i);
						 }
						break;
			//List everyone from one family.
			case '2' :	stringBuffer = messages.AskFamily();
						for(family_it=family.begin();family_it!=family.end();++family_it)
						 for(people_it=family_it->second.begin();
						     people_it!=family_it->second.end();++people_it)
							if(stringBuffer == people_it->getFamilyNum())
								cout << people_it->getPersonName() << endl;
						break;
			//List every activity and it's data
			case '3' :	for(act_it=activities.begin();act_it!=activities.end();act_it++)
							cout << *act_it;
						break;
			//List everyone from an event
			case '4' :	stringBuffer = messages.AskEvent();
						for(family_it=family.begin();family_it!=family.end();++family_it)
						 for(people_it=family_it->second.begin();
						     people_it!=family_it->second.end();++people_it)
							if(stringBuffer.find_first_not_of(people_it->getActivityFlags()))
								cout << people_it->getPersonName() << endl;
						break;
			//List all the staff members
			case '5' :  stringBuffer.assign("yes");
				        for(family_it=family.begin();family_it!=family.end();++family_it)
						 for(people_it=family_it->second.begin();
						     people_it!=family_it->second.end();++people_it)
							if(stringBuffer.find_first_not_of(people_it->getStaffFlag()))
								cout << people_it->getPersonName() << endl;
						break;
			//Makes a new person
			case '6' :	peopleBuffer.fill();
				        family[peopleBuffer.getFamilyNum()].push_back(peopleBuffer);
						break;
			//Makes a new activity
			case '7' :  activityBuffer.fill();
						activities.push_back(activityBuffer);
						break;
			//Saves all the information to data files
			case '8' :  cout << "Type in the new people file's name:";
						cin >> filename;
						FamOutfile.open(filename);
						for(family_it=family.begin();family_it!=family.end();++family_it)
						 for(people_it=family_it->second.begin();
						     people_it!=family_it->second.end();++people_it)
							FamOutfile << *people_it;
						FamOutfile.close();FamOutfile.clear();

						cout << "Type in the new activity file's name:";
						cin >> filename;
						ActOutfile.open(filename);
						for(act_it=activities.begin();act_it!=activities.end();act_it++)
							ActOutfile << *act_it;
						ActOutfile.close();ActOutfile.clear();
						break;
			//Shows all the information for just one person //Last minute addition
			case '9' :  stringBuffer = messages.AskPersonName();
						for(family_it=family.begin();family_it!=family.end();++family_it)
						 for(people_it=family_it->second.begin();
						     people_it!=family_it->second.end();++people_it)
							if(stringBuffer.find_first_not_of(people_it->getPersonName()))
								cout << *people_it;
			 			break;
			//Shows all the information for just one activity //Last minute addition
			case 'a' : case 'A' :
				        stringBuffer = messages.AskActivityName();
						for(act_it=activities.begin();act_it!=activities.end();act_it++)
							if(stringBuffer.find_first_not_of(act_it->GetActivityName()))
								cout << *act_it;
					    break;
			//Quits the program
			case 'q' :	case 'Q' : break;
			//default switch
			default  :	cout << "Not a choice!\n\n";
		}
	}while( !((choice == 'q') || (choice == 'Q')) );

	//Close out anything that might be open still ...
	FamInfile.close();FamInfile.clear();
	ActInfile.close();ActInfile.clear();
	messages.Bye();
	return 0;
}//END MAIN
