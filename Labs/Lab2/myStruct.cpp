//Gabrielle Sims
//January 23, 2019
//A program that sets the month, date, and year to a specific date, prints it, and also contains a method for making every slot in an array January
#include <iostream>
#include <string> 
using namespace std;

const int SIZE = 100;

struct DateType
{
	string month;
	int day;
	int year;
};

// Insert EventType definition HERE
struct EventType
{
	string place;
	DateType date;
};

void PrintStruct (DateType Holiday);
void AssignMonth (EventType Dates[]);

int main()
{
	DateType Holiday;
	EventType Dates[SIZE];
	Holiday.month = "January"; //The string "January" is assigned to the month variable
	Holiday.day = 5; //The integer 5 is assigned to the day variable
	Holiday.year = 2019; //The integer 2019 is assigned to the year variable
	PrintStruct (Holiday);
	AssignMonth (Dates);
	return 0;
}

void PrintStruct (DateType Holiday)
{
	// pre  : Holiday is intialized with three field values
	// post : Function prints date of Holiday in form mm dd, yy
 	cout << Holiday.month << " " << Holiday.day << ", " << Holiday.year;
}

void AssignMonth (EventType Dates[])
{
	// pre  : none 
	// post : The month field of every date record in array is assigned a month 
	for(int i = 0; i < SIZE; i++) //A for loop is used to increment slots within the array and assign "January" to each slot
	{
		Dates[i].date.month = "January";
	}
}
