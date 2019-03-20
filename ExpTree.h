#ifndef EXPTREE_H
#define EXPTREE_H

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

class ExpTree
{
	public: 
    	ExpTree() {root = NULL;}
    	~ExpTree();
    	void makeEmpty();
    	void buildTree (istream& inF);
    	ostream preOrder (ostream& outS);
    	ostream inOrder (ostream& outS);
    	ostream postOrder (ostream& outS);
    	int value();
	private:
    	struct Node
    	{
    		int operand;
        	char optr;
        	Node *left;
        	Node *right;
    	};
    	Node *root;
    	Node* helpBuild(istream& inS);
    	void prefix (Node *r);
    	void infix (Node *r);
    	void postfix (Node *r);
    	void destroy(Node *p);
    	void empty(Node *p);
    	int evaluate(Node *p);
};
#endif
