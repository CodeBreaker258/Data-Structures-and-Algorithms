//Gabrielle Sims
//January 23, 2019
//A program that tells which name is the first and last name and the middle initial from the format last name, first name middle initial.
#include <string>
#include <iostream>
using namespace std;

void BreakDown (string name, string& first, string& last, string& mi);
int main()
{
	string name, first, last, mi;

	cout << "Name? <Last, First MI.> ";
	getline (cin, name);
		
	BreakDown (name, first, mi, last);

	cout << "First Name Entered :  " << first << endl;
	cout << "Last Name Entered :  " << last << endl;
	cout << "Middle Initial Entered :  " << mi << endl;
	return 0;
}

void BreakDown (string name, string& first, string& mi, string& last)
{
	// pre  : name is initialized with a full name
	// post : first, mi, and last contain the individual components
        //        of that name

	int commaPos = name.find(","); //an integer that contains the value of the location of the comma within the name string
	string lastName = name.substr(0, commaPos); //a string variable for just the last name of a name using the comma position as the
						    //end value
	last = lastName; //the last name string is then stored in the string from the main method

	int periodPos = name.find("."); //an integer that contains the value of the location of the period within the name string
	string middleName = name.substr(periodPos-1, 1); //a string variable for just the middle initial of a name that uses the period
               					    //as the end value
	mi = middleName; //the middlename string is stored into the variable mi

	string firstName = name.substr(commaPos+2, periodPos-4-last.length()); //using the comma position and adding two spaces to it
                				    //starts the first name and using the stirng length, 
                				    //and the period position the first name is found
	first = firstName; //the string value is stored into the first variable since that is the name of the variable in main

} 
