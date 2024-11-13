#include <iostream>
#include "linelist.h"
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void JustEndAlready(char *argv[], LineList& L);
int main(int argc, char *argv[])
{	
	//checks to see if the user forgot to enter a filename
	if(argc == 1)
	{
		cout <<"File not entered. Program will now end." << endl;
		exit(1);
	}

	//user input for a file within the directory can now be used
	LineList L;
	string filename = argv[1];
	ifstream infile;
	infile.open(filename.c_str());
	string uline;
	char userinput;
	
	//using getline, the file is opened and the information is taken from the file
	if(infile.is_open())
	{
		while(getline(infile, uline))
 		{
			L.insertLine(uline);
		}
  		infile.close();
	}
	//Displays a main menu of some sort
	cout << "Welcome to the Simple Line Editor: Programmer Edition" << endl;
	cout << "----------------------------------------------------" << endl;
	L.goToTop();
	L.printList();
	L.goToBottom();
	cout << L.getCurrLineNum() << "> ";
	while(cin >> userinput)
	{
		if(userinput == 'I')
		{
			cout << L.getCurrLineNum() + 1 << "> ";
      			cin.ignore();
			getline(cin, uline);
			L.insertLine(uline);
		}
		if(userinput == 'D')
		{
			L.deleteLine();
		}
		if(userinput == 'L')
		{		
			L.printList();
		}
		if(userinput == 'P')
		{
			L.movePrevLine();
		}
		if(userinput == 'N')
		{
			L.moveNextLine();
		}	
		if(userinput == 'E')
		{
     			JustEndAlready(argv, L);
			exit(1);
		}
    		cout << L.getCurrLineNum() << "> ";	
	}
	return 0;
}
void JustEndAlready(char *argv[], LineList& L)
{
  ofstream outfile;
  string filename = argv[1];
  
  outfile.open(filename.c_str());
  L.goToTop();
  
  for(int i = 1; i <= L.getLength(); i++)
  {
    outfile << L.getCurrLine() << endl;
    L.moveNextLine();
  }
  outfile.close();
}  
