#include <vector>
#include <string>
using namespace std;

struct HNode {
    char ch;
    int weight;
    int parent;
    int childType;
};

class HuffmanTree {
    public:
	HuffmanTree();				// constructor

	void insert(char ch, int weight);	// inserts a character and its associated weight
						// into a node of the Huffman tree

	bool inTree(char ch);			// returns a boolean value indicating whether
						// a given character is stored in the tree
		
	int GetFrequency(char ch);		// returns the weight of a given character

	
	void build();				// Builds the Huffman Tree;
	

	string GetCode(char ch);		// returns the compressed code of a given
						// character in the tree using recursion

	void PrintTable();			// displays the Huffman encoding table used in
						// the compression process
	
	int numNodes();				// returns the number of nodes currently in Huffman 
						// tree
	
	vector<char> fetchBread();		//gets the chars from the file to help with zipping and unzipping

	
	void compression(string file, int chars, int counter); //a method that performs compression on the input file 
							       //and sends it to the outfile
		
    private:
	vector<HNode> nodes;
	int numChars;
	bool built;                             
	
	int lookUp(char ch);			// returns the index of a given character in tree
	int GetFrequency(int i);		// returns the weight at a given index
	string GetCode(int i);			// returns the compressed code of the character at 
						// a given index
	//void findSmall(int& min1, int& min2);
};
