#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int getMax(const vector<int>& v);
int maxElemLength(const vector<int>& v);
int GetNumDigits(int number);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k);
vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals);
void RadixSort(vector<int>& L, int numDigits);
void PrintVector(const vector<int>& L);


int main(){

	vector<int> L; // the list to be sorted
	vector<queue<int> > QA(10); //vector of queues indexed 0-9
	int i = 0;
	
	//inserting the values into the vector
	L.push_back(380);
	L.push_back(95);
	L.push_back(345);
	L.push_back(382);
	L.push_back(260);
	L.push_back(100);
	L.push_back(492);
	
	cout << "List before Pass: " << endl;
	PrintVector(L);
	RadixSort(L, maxElemLength(L));

	cout << "List after Pass III and Step 2: " << endl;
	PrintVector(L);	
	return 0;
}

//a method that finds the maximum value within the vector
int getMax(const vector<int>& v)
{
	int maxVal = v[0];
	for(int i = 1; i < v.size(); i++)
		if(v[i] > maxVal)
			maxVal = v[i];
	return maxVal;
}

//a method that calls getMax and then finds the length of the maximum element
int maxElemLength(const vector<int>& v)
{
	
	int max, digits = 0;
	max = getMax(v);
	while(max != 0){
		max /= 10;
		digits++;
	}
	return digits;	
	
}

// a method that gets the number of digits for any number that is entered as a parameter
int GetNumDigits(int number)
{
	int numDigits = 0;
	while(number != 0){
		number /= 10;
		numDigits++;
	}
	return numDigits;
}

//a method that gets a specific digit within the number value based on the value of k
//there are three checks that happen, if k is equal to 0, if k does not equal 0 and
//is less than number of digits and if k is greater than number of digits
int GetDigit(int number, int k)
{
	int numDigits = 0, i = 0; int dig[245];
	numDigits = GetNumDigits(number);
	if(k == 0){
		while(number != 0){
			number %= 10;
			return number;
		}
	}
	else if((k < numDigits) && (k != 0)){	
		while(number){	
			dig[i] = number % 10;
			i++;
			number /= 10;
		}
		return dig[k];
	}
	else if(k >= numDigits)
		return 0;

}

//a method that corresponds to the first step in a radix sort
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k)
{
	vector<queue<int> > QA(10);
	int currDigit = 0;
	
	for(int i = 0; i < L.size(); i++){
		currDigit = GetDigit(L[i], k);
		QA[currDigit].push(L[i]);
	}
	return QA;

}

vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals)
{
	vector<int> L;

	for(int i = 0; i < QA.size(); i++){
		numVals++;
	}
	
	for(int j = 0; j < numVals; j++){
		while(!QA[j].empty()){
			L.push_back(QA[j].front());
			QA[j].pop();
		}
	}	
	return L;	
}

//a method that performs the radix sort using ItemsToQueues and QueuesToArray 
void RadixSort(vector<int>& L, int numDigits)
{
	vector<queue<int> > QA(10);
	for(int k = 0; k < numDigits; k++){
		QA = ItemsToQueues(L,k);
		L = QueuesToArray(QA, L.size());
	}
}

void PrintVector(const vector<int>& L)
{
	for(int i = 0; i < L.size(); i++)
		cout << L.at(i) << endl;
}
