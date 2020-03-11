#include "ClassicBST.h"
#include <iostream>

ClassicBST::ClassicBST()
{
}

ClassicBST::~ClassicBST()
{
}

bool ClassicBST::insert(Classic& newData)
{
	return helpInsert(this->root, &newData);
}

bool ClassicBST::helpInsert(Node*& thisNode, Classic* newData)
{
	if (thisNode == NULL) {
		thisNode = new Node;
		thisNode->data = newData;
		thisNode->left = NULL;
		thisNode->right = NULL;
		cout << "new Node Created" << endl;
		cout << *(thisNode->data) << endl;
		return true;
	}
	else if (newData < thisNode->data)
	{
		helpInsert(thisNode->left, newData);  // traverse left
	}
	else if (newData > thisNode->data)
	{
		helpInsert(thisNode->right, newData); // traverse right
	}
	else
	{
		return false;   // Node Data already exists
	}
	return true;    //Node inserted successfully
}

void ClassicBST::printTree()
{
	printTree(*&root);
}

void ClassicBST::printTree(Node*& movieNode)
{
	if (movieNode == NULL) {
		return;
	}
	else {

		/* first recur on left child */
		printTree(movieNode->left);

		/* then print the data of node */
		cout << *(movieNode->data) << endl;

		/* now recur on right child */
		printTree(movieNode->right);
	}
}
