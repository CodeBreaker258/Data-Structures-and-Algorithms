//Gabrielle Sims
//February 15, 2019
//Lab4
#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
	//instantiate the variable T as a BinarySearchTree type that holds integers
	BinarySearchTree<int> T(0);

	//insert the values into the tree
	T.insert(6);
	T.insert(2);
	T.insert(8);
	T.insert(1);
	T.insert(4);
	T.insert(3);
	T.insert(9);
	
	//a call to print out the tree after values are added
	T.printTree();

	//a method call to post order
	T.postOrder();

	//a method call to height
	cout << T.height() << endl;

	//a method call to tell the number of leaves within the tree
	cout << T.numLeaves() << endl;
	
	//a method that determines if the tree is balanced or not
	T.isBalanced();

	if(T.isBalanced() != 0)
		cout << "It's Balanced!" << endl;
	else
		cout <<"It's Not Balanced!" << endl;
	return 0;
}
