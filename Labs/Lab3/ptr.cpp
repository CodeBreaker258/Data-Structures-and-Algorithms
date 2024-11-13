//Gabrielle Sims
//January 30, 2019
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

struct RecType
{
	int age;
	float weight;
	char gender;
};

int main()
{
	int num = 5;
	int *intPtr = new int;
	intPtr = NULL;
	intPtr = &num;
	cout<< "intPtr points to: " << *intPtr*10 << endl;
	
	RecType rec;
	RecType *recPtr = new RecType;
	recPtr -> age = 25;
	recPtr -> weight = 190.0;
	recPtr -> gender = 'M';
	recPtr -> age += 5;
	cout << "Three Fields Pointed to By recPtr : " << recPtr -> age << " " << recPtr -> weight << " " <<  recPtr -> gender  << endl;

	delete recPtr;
	recPtr = NULL;
	
	char *strPtr = new char [50];
	strcpy(strPtr, "Operating Systems");
	cout << "strPtr points to : " << strPtr  << endl;
	
	int lowercount = 0;
	for(int i = 0; i < strlen(strPtr); i++)
		if(islower(*(strPtr + i)))
			lowercount++;
	cout << "LowerCase Letters Pointed to By strPtr : " << lowercount <<  endl;

	strPtr += 10;
	cout << "Priting strPtr after adding 10 : " << strPtr << endl;
	strPtr -= 10;
	delete [] strPtr;
	return 0;
}
