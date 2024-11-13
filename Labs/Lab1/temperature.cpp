//Gabrielle Sims
//January 16,2018
//A program that converts a temperature from Celsius to Fahrenheit
#include <iostream>

using namespace std;
double convert(double value);
int main()
{
	double Celsius;
	cout << "Please enter a Celsius value: ";
	cin >> Celsius;
	cout <<Celsius<<" degrees Celsius is " <<convert(Celsius)<<" degrees Fahrenheit."<<endl;
	return 0;
}
double convert(double tmp)
{
	tmp = 1.8 * tmp + 32.0;
	return tmp;
}
