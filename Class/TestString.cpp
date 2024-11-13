//Breaking down TestString.cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string a = "hello";
   string b = "world";
   string c;  //should be ""

   c = a + " "; //should be "hello"
   c += b; //should be "hello world"
 
   //Print c the easy way
   cout << "c is: " << c << endl;

   //Print c the primitive way
   cout << "c is: " << c.c_str() << endl;

   //Print c character-by-character
   cout<< "c is: ";
   for(int i = 0; i < c.length(); i++)
      cout << c[i];
   cout << endl;

   return 0;
}

