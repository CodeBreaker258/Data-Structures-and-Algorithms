//Gabrielle Sims
//January 30, 2019
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void Initialize(vector<int>& v)
{
	int input;

	for(int i = 0; i < 5; i++)
	{
		cin >> input;
		v.push_back(input);
	}	
}

void Print(vector<int>& v)
{
	for(int i = 0; i < 5; i++)
		cout << v[i] << " ";
		cout << endl;
}

void Reverse(vector<int>& v)
{
	for(int i = 0; i < 5; i++)
		reverse(v.begin(), v.end());	
}	
int main()
{
	stack<string> s1, s2;
	s1.push("Hi there");
	s2.push("Hey there");
	
	if(s1 == s2)
	   cout << "s1 == s2" << endl;
	else if(s1 < s2)
	   cout << "s1 < s2" << endl;
	else if(s2 < s1)
	   cout << "s2 < s1" << endl;

	vector <int> v;
	Initialize(v);
	Print(v);
	Reverse(v);
	Print(v);
	sort(v.begin(), v.end());
	Print(v);
	return 0;
}
