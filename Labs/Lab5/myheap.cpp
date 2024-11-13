#include <string>
#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main()
{
	BinaryHeap<char> PQ(50);

	for(char i = 'A'; i < 'K'; i++)
		PQ.insert(i);
	
	PQ.deleteMin();
	cout <<"Printing Left Subtree of the Root of Heap: ";	
	PQ.printLtSubtree( );
	cout << "\nThe Height of Heap Is : " << PQ.Height() << endl;
	cout << "The Maximum Value of Heap Is: " << PQ.findMax() << endl;
	return 0;
}
