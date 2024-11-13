#include "huffman.h"
#include <string>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, -1, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;
    
    int i, j;
    char temp;
    for(i = 0; i < numChars; i++)
    {
      for(j = 0; j < numChars - i - 1; j++)
      {
          if(nodes[j].ch > nodes[j+1].ch){
              temp = nodes[j].ch;
              nodes[j].ch = nodes[j+1].ch;
              nodes[j+1].ch = temp;
          }
      }
    }
}

bool HuffmanTree:: inTree(char ch) {
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].ch == ch)
			return true;
		else
			return false;
	}

}

int HuffmanTree:: GetFrequency(char ch) {
	if(!inTree(ch))
		return 0;
	else
		return nodes[lookUp(ch)].weight;
}

int HuffmanTree:: GetFrequency(int i) {
	int counter = 0;
	for (int j = 0; j < nodes.size(); j++)
	{
		if (nodes[j].ch == i)
			counter++;
	}
	return counter;
}

int HuffmanTree:: lookUp(char ch) {
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].ch == ch) {
			return i;
		}
	}
 	return -1;
}

string HuffmanTree:: GetCode(char ch) {
	return GetCode(lookUp(ch)); 
}

string HuffmanTree:: GetCode(int i) {
	//Private function called w/ location of letter
	if (nodes[i].parent == 0)
		return ""; //base case
	else
		return (GetCode(nodes[i].parent) + (char)(nodes[i].childType + '0'));
}
//a method that gets chars and not bread (sadly)
vector<char> HuffmanTree:: fetchBread(){
	vector<char> bread;
	for(int i =0; i < nodes.size(); i++)
		bread.push_back(nodes[i].ch);
		
	sort(bread.begin(), bread.end());
	
	return bread;
}

void HuffmanTree:: PrintTable() {
	//A method that displays the number of values within the vector, what values are present, how many there are,
	//who the values are tied to, and determines if the char is to the right or left in the tree
	int tcount = 1;
	cout << '\t' <<  "++++ ENCODING TABLE ++++" << endl;
	cout << endl;
	cout << "Index" << '\t' << "Char" << '\t' << "Weight" << '\t' << "Parent" << '\t' << "ChildType";
	cout << endl;
	for (int i = 0; i < nodes.size(); i++)
	{	
		if((nodes[i].ch != '\n') && (nodes[i].ch != ' ') && (nodes[i].ch != '\0')){
			cout << i << '\t' << nodes[i].ch << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t';
			if(nodes[i].childType == -1){
				cout << "N/A" << endl;
			}
			else{	
				cout << nodes[i].childType << endl;
			}
		}
		if(nodes[i].ch == '\n'){
			cout << i << '\t' << "nl" << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t';
			if(nodes[i].childType == -1){
				cout << "N/A" << endl;
			}
			else{
				cout << nodes[i].childType << endl;
			}
		}
		if(nodes[i].ch == ' '){
			cout << i << '\t' << "sp" << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t';
			if(nodes[i].childType == -1){
				cout << "N/A" << endl;
			}
			else{
				cout << nodes[i].childType << endl;
			}
		}
		if(nodes[i].ch == '\0'){
			cout << i << '\t' << "T" << tcount << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t';
			if(nodes[i].childType == -1){
				cout << "N/A " << endl;
			}
			else{
				cout << nodes[i].childType << endl;
			}
			tcount++;
		}
	}
}

int HuffmanTree:: numNodes() {
	//returns the value of nodes in the tree
	return nodes.size();
}
//determines the parent and childType for each char in the tree
void HuffmanTree:: build() {
	for(int i = 0; i <  numChars - 1; i++){

		int minDex,minIndex2;
		int min1 = 9999; int min2 = 9999;
		
		for(int j = 0; j < nodes.size(); j++)
		{
			if((nodes[j].parent == -1) && (nodes[j].weight < min1)){
				min1 = nodes[j].weight;
				minDex = j;
			}
		}
		for(int l = 0; l < nodes.size(); l++)
		{
			if((nodes[l].parent == -1) && (nodes[l].weight < min2) && (l != minDex)){
				min2 = nodes[l].weight;
				minIndex2 = l;
			}
		}
		
		nodes[minDex].parent = nodes.size();
		nodes[minIndex2].parent = nodes.size();

		nodes[minDex].childType = 0;
		nodes[minIndex2].childType = 1;

		HNode temp = {'\0', (min1 + min2), -1, -1};
		nodes.push_back(temp);
	}
		nodes[nodes.size() - 1].parent = 0;
		built = true; 
}

//a method that compresses the information from the input file and sends it
//into an outfile once it is zipped
void HuffmanTree:: compression(string file, int chars, int counter){
  	int bitNums = 0; char ch;
  	ifstream infile(file.c_str()); ofstream outfile;
  	double compressionRatio;
  	string binaryString;
  
  	string zipFile = file + ".zip";
  	outfile.open(zipFile.c_str());
  	outfile << chars << endl;
  	for(int i = 0; i < chars; i++)
  	{
     		outfile << (int)nodes[i].ch << " " << GetCode(nodes[i].ch) << endl;
  	}     
	while(infile.get(ch)){

  	string binaryLength = GetCode(ch);
  	bitNums += binaryLength.length();
  	binaryString += binaryLength;
   
	}
      	outfile << binaryString;
      
  	outfile.close();
	remove(file.c_str());
  	compressionRatio = (1.0 - ((double)bitNums / ((double)counter * 8))) * 100;
  	cout <<"File Successfully Compressed to " << bitNums << " Bits (" << setprecision(4) << compressionRatio << "% Less)." << endl;
}
