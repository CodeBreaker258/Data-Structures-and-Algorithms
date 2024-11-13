#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include "stack.h"
using namespace std;

int OperateCheck(string s, Stack<int>& iStack);
int OpReturn(char s, Stack<int>& iStack);
void isValid(char s, Stack<int>& iStack);
bool allDigits(string s);

int main()
{
	string s;
	Stack<int> iStack;
	while (getline(cin, s)) {
		OperateCheck(s, iStack);
	}
	return 0;
}
//Pre: the user inputs their string
//Post: based on the string input, certain operations
//will be carried out and the validity of the input will
//be determined
int OperateCheck(string s, Stack<int>& iStack)
{
	int i = 0, num, inumber;

	while (i < s.length()) {
		if (s[i] == '_') {
			string a = "-";
			while (isdigit(s[i + 1])) {
				a += s[i + 1];
				i++;
			}
			inumber = atoi(a.c_str());
			try {
				iStack.push(inumber);
			}
			catch (Overflow obj) { cerr << "Illegal push - I'm full" << endl; }
		}
		else if (isdigit(s[i])) {
			string digit;
			while (isdigit(s[i])) {

				digit += s[i];
				i++;
			}
			num = atoi(digit.c_str());
			iStack.push(num);
		}

		else if (isalpha(s[i])) {
			isValid(s[i], iStack);

		}
		else if (isgraph(s[i])) {

			num = OpReturn(s[i], iStack);
			iStack.push(num);
		}
		i++;
	}
}
//Pre: a string is entered by the user
//Post: the method will determine if that 
//string contains valid characters or not
void isValid(char s, Stack<int>& iStack)
{
	int num1, num2;
	try {
		if (s == 'p')
			cout << iStack.top() << '\n';
		else if (s == 'n')
		{
			cout << iStack.topAndPop();
		}
		else if (s == 'f') {
			Stack<int> copyStack(iStack);
			while (!copyStack.isEmpty())
				cout << copyStack.topAndPop() << '\n';
		}
		else if (s == 'c')
		{
			iStack.makeEmpty();
		}
		else if (s == 'd')
		{
			iStack.push(iStack.top());
		}
		else if (s == 'r') {
			{
				num1 = iStack.topAndPop();
				num2 = iStack.topAndPop();
				iStack.push(num1);
				iStack.push(num2);
			}

		}
		else {
			throw DataError();
		}
	}
	catch (DataError obj) { cerr << "Illegal option -- Please try again." << endl; }
}
//Pre: The string is given
//Post: The string is checked for digits
//and the underscore since it represents a
//negative number
bool allDigits(string s)
{
	bool test = true;

	test = test && (isdigit(s[0]) || (s[0] == '_'));
	for (int i = 1; i < s.length(); i++)
		test = test && (isdigit(s[i]));

	return test;
}
//Pre: The user gives a string input
//Post: Based on the userinput, the string is
//evaluated for a valid operator
int OpReturn(char s, Stack<int>& iStack)
{
	int num1, num2;
	try {
		if (s == '+')
		{
			num1 = iStack.topAndPop();
			num2 = iStack.topAndPop();
			return num2 + num1;
		}
		else if (s == '-')
		{
			num1 = iStack.topAndPop();
			num2 = iStack.topAndPop();
			return num2 - num1;
		}
		else if (s == '*')
		{
			num1 = iStack.topAndPop();
			num2 = iStack.topAndPop();
			return num1 * num2;
		}
		else if (s == '/') {
			try
			{

				num1 = iStack.topAndPop();
				num2 = iStack.topAndPop();
				if (num1 == 0)
					throw DivisionByZero();
				else
					return num2 / num1;
			}
			catch (DivisionByZero obj) { cerr << "Illegal division -- Cannot divide by zero." << endl; }

		}
		else if (s == '%')
		{
			num1 = iStack.topAndPop();
			num2 = iStack.topAndPop();
			return num2 % num1;
		}
		else
			cout << "Invalid character. Please try again." << endl;
	}
	catch (Underflow obj) { cerr << "Illegal action -- I'm empty." << endl; }
}
