#include <iostream>
using namespace std;

void swap1 (int& num1, int& num2);
void swap2 (int *num1, int *num2);

int main()
{
	int num1 = 5, num2 = 3;
	
	swap1 (num1, num2);
	cout << num1 << " " << num2 << endl;
	swap2 (&num1, &num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}
void swap1(int& num1, int& num2)
{
	int temp;
	
	temp = num1;
	num1 = num2;
	num2 = temp;
}
void swap2(int *num1, int *num2)
{
	int temp;
	
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
