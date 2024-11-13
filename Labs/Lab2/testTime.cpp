//Gabrielle Sims
//January 23, 2019
//A program that instantiates a variable of time to a specific value, tells if it is am or pm, determines if it is mealtime or not, and 
//deconstruct. A specific time is then entered an array and output each time that the array goes through the loop
#include "time.h"
#include <iostream>
using namespace std;

int SIZE = 10; //initialization of the int SIZE
int main()
{
	Time myTime(9, 30, 0); //instantiation of the variable my time with 9:30:00
	myTime.Write(); //the time 9:30:00 is printed out
	myTime.WriteAmPm(); //the time 9:30:00 is printed once again this time telling if it is am or pm (in this case am)
	
	myTime.Set(8, 0, 0); //the time is not set to be 8:00:00
	myTime.WriteAmPm(); // the new time is written with am or pm depending on the hour's number (in this case am)
	myTime.Mealtime(); //depending on if the time is set to a specific hour or not determines a specific meal time (breakfast here)
	
	Time Schedules[SIZE]; //a new array named Schedules is created
	for(int i = 0; i < SIZE; i++) //a for loop that runs ten times is ran, setting each slot in the array to 11:00:00 AM
	{
		Schedules[i].Set(11, 0, 0);
		Schedules[i].WriteAmPm();
	}	
	return 0;
}
