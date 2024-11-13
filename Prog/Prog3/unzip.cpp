#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
using namespace std;

int GetData(string filename);

int main(int argc, char** argv)
{
	string filename = argv[1];
	ofstream outfile;
	if(argc == 1){
		cout << "File not entered. Terminating program." << endl;
		exit(1);
	}
	string fin(argv[1]);
	if(fin.substr(fin.length() -4) != ".zip"){
		cout << "Invalid file name. Terminating program." << endl;
		exit(1);
	}
	string decode = filename.substr(0, (filename.length()- 4));
	outfile.open(decode.c_str());
	GetData(filename);
	
	return 0;
	
}

//a method that gets and decompresses the data from the zip file
int GetData(string filename)
{
	//variable declarations for input and output files
	//for the char ch, the counter, and a string that
	//gets the values from the inputfile
	
	ifstream infile; ofstream outfile;
	//ifstream infile; ofstream outfile;
	char ch; int  counter;
	string toastedBread;
	
	//the file is opened	
	infile.open(filename.c_str());
	remove(filename.c_str());

	
	//the first value is grabbed
	getline(infile, toastedBread);
	//the first value is turned into a string and stored
	//in an int as a counter value
	counter = atoi(toastedBread.c_str());
	
	map<string, char> characters;
	string lastLine, substri;
	for(int i = 0; i < counter; i++)
	{
		//variable declaration
		int letter; string fileCode, partOne;
		string del = " "; char actualLetter; 

		getline(infile, fileCode);
		substri = fileCode.substr(0, fileCode.find(del));
		partOne = substri;
		
		letter = atoi(partOne.c_str());
		actualLetter = (char) letter;
		
		substri = fileCode.substr(fileCode.find(del) + 1);
		
		//using the map, the codes are assigned values		
		characters[substri] = actualLetter;
		
	}
			getline(infile, lastLine);
			substri = "";
		
		string decode = filename.substr(0, (filename.length()- 4));
		outfile.open(decode.c_str());
		//using a for loop, the string is parsed and if the code is found, it
		//is stored in the outfile, and if it is not found, then the code keeps
		//looping 
		for(int k = 0; k < lastLine.length(); k++){
				if(characters.find(substri) == characters.end()){
					
					substri = substri + lastLine[k];
				}
				else{
					k--;
					outfile << characters[substri];
					substri = "";
				}
		}
	
	outfile.close();
	infile.close();
	cout << "File Successfully Inflated Back to Original." << endl;
	exit(0);
}
	
		
