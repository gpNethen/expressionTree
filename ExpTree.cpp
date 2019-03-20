#include <cstdlib>
#include <iostream>
#include <cstring>
#include "ExpTree.h"
using namespace std;

// Default constructor is inline.

void ExpTree::destroy(Node *p)
{
	if (p!=NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
	}
}
ExpTree::~ExpTree()
{
	destroy(root);
}

void ExpTree::empty(Node *p)
{
	destroy(p->left);
	destroy(p->right);
	p=NULL;
}
void ExpTree::makeEmpty()
{
	empty(root);
}

ExpTree::Node* ExpTree::helpBuild(istream & inS)
{
	char ch;
	Node *temp;
	inS >> ch;
	if ( isdigit(ch) )
	{
		temp= new Node;
		temp->operand = ch-'0';
		temp->left = NULL;
		temp->right = NULL;
	}
	else
	{
		temp = new Node;
		temp->left = helpBuild(inS);
		inS >> temp->optr;
		temp->right = helpBuild(inS);
		inS >> ch;
	}
	return temp;
}
void ExpTree::buildTree(istream& inF)
{
	destroy(root);
	root = helpBuild(inF);
}

void ExpTree::prefix(Node *r)
{
	if (r->left ==NULL)
		cout << r->operand << " ";
	else
	{
		cout << r->optr << " ";
		prefix(r->left);
		prefix(r->right);
	}
}
ostream ExpTree::preOrder(ostream& outS)
{
	outS << prefix(root);
	return outS;
}

void ExpTree::infix(Node *r)
{
	if (r->left ==NULL)
		cout << r->operand << " ";
	else
	{
		cout << "( ";
		infix(r->left);
		cout << r->optr << " ";
		infix(r->right);
		cout << " )";
	}
}
ostream ExpTree::inOrder(ostream& outS)
{
	outS << infix(root);
	return outS;
}

void ExpTree::postfix(Node *r)
{
	if (r->left ==NULL)
		cout << r->operand << " ";
	else
	{
		prefix(r->left);
		prefix(r->right);
		cout << r->optr << " ";
	}
}
ostream ExpTree::postOrder(ostream& outS)
{
	outS << postfix(root);
	return outS;
}

int ExpTree::evaluate(Node *p)
{
	if (p->left == NULL && p->right == NULL)
		return p->operand;
	else
		return evaluate(p->left) p->optr evaluate(p->right);
}
int ExpTree::value()
{
	evaluate(root);
}


