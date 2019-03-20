#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "ExpTree.h"
#include "ExpTree.cpp"
using namespace std;

void openInputFile ( ifstream& inputFile );
int apply( char optr, int opnd1, int opnd2 );
bool isLowerPriority(char op1, char op2);

int main()
{
	ifstream inFile;            // The input file stream
	char ch;                    // Each char read
	ExpTree t;                  // Expression tree to be reused
	ostream outP;
	
	openInputFile(inFile);      // Open the input file.
	inFile.get( ch );
	while ( !inFile.eof() )
	{
		while ( ch >= ' ' )
		{
  			t.buildTree(ch);
			inFile.get( ch );
  		}
  		cout << "Prefix: " << t.preOrder(outP) << endl;
  		cout << "Infix: " << t.inOrder(outP) << endl;
  		cout << "Postfix: " << t.postOrder(outP) << endl;
  		cout << "Value: " << t.value() << endl;
  		t.makeEmpty();
		inFile.get(ch);
  	}
	inFile.close();             // Close the input file.

	return EXIT_SUCCESS;
}

void openInputFile ( ifstream &inputFile )
{
	char inputFileName[80];

	do
	{ inputFile.clear();
    	cout << "Enter input file name: ";
    	cin >> inputFileName;
    	inputFile.open(inputFileName);
    	cout << endl;
  	} while ( inputFile.fail() );
}
