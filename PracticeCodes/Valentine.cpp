#include <iostream>
using namespace std;

int main()
{
	string holiday = "Valentine's Day";
	int day = holiday.find("Day");
	string half = holiday.substr(day);
	cout << half << endl;
	return 0;
}
