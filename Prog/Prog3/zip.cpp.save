#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include "huffman.h"
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
	//variable declaration
	HuffmanTree T;
	char ch; 
	string filename; vector <char> numBread; //holds the characters
	string arg1 = argv[1];
	bool useTable = false;
 	int counter = 0;
   	int chars = 0;  
	int Letters[256];

	//checks to see if user gave a file or a special command
	if (argc == 1)
	{
		cout << "File not entered. Program terminated." << endl;
		exit(1);
	}
	if (arg1 == "--t")
  	{
   		filename = argv[2];
		useTable = true;
	}
  	else{
    		filename = argv[1];
    		useTable = false;
 	}
  	if(arg1 == "--help"){
         	string whatEver;
         	ifstream helpFile;
         	helpFile.open("help");
           	while(getline(helpFile, whatEver)){
             		cout << whatEver << endl;
             	}
           	helpFile.close();
		exit(1);
  	}
	//userinput for a file within the directory is given
	ifstream infile;
	ofstream outfile;
  

	//getting file input
	infile.open(filename.c_str());

	//zeros out all values and gets rid of values that are not
	//used
	for( int x = 0; x < 256; x++ ) 
		Letters[x] = 0; 


	for (char ch = char(0); ch <= char(128); ch++)
		Letters[ch] = 0;


	while (infile.get(ch))
	{
		numBread.push_back(ch);
		Letters[ch] += 1;
    		counter++;
	}

	for (int i = 0; i <= 256; i++)
	{
		if (Letters[i] > 0){
			T.insert(i, Letters[i]);
      			chars++;
		}
	}

	T.build();

	//a loop that determines if the boolean useTable is true
	//if true, the table will be printed
	if(useTable){
    		T.PrintTable();		
   	}

   	infile.close();
  
  	//Data compression
    		T.compression(filename, chars, counter);
  	
   
   return 0;
}


