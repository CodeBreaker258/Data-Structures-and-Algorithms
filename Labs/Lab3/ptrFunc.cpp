//Gabrielle Sims
//January 30, 2019
#include<iostream>
using namespace std;

bool identical (double *ptr1, double *ptr2)
{
	return (*ptr1 == *ptr2);
	/*if(*ptr1 == *ptr2)
		return true;
	else
		return false;*/
}	

bool addIdentical (double *ptr1, double *ptr2)
{
	return (ptr1 == ptr2);
	/*if(ptr1 == ptr2)
		return true;
	else 
		return false;*/
}

int main()
{
	double dub1 = 5.0;
	double dub2 = 10.0;
	double *ptrs = &dub1;
	double *ptrz = &dub2;

	cout << ptrs << endl;
	cout << ptrz << endl;
	cout<<  addIdentical(ptrs, ptrz) << endl;
	
	cout << *ptrs << endl;
	cout << *ptrz << endl;
	cout << identical(ptrs, ptrz) << endl;
	return 0;
}
