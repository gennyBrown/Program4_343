#include "MovieBST.h"
#include <iostream>

using namespace std;



MovieBST::MovieBST()
{
	root = nullptr;		//set root to null
}

MovieBST::~MovieBST()
{
	//makeEmpty();		//calls recuresive helper
}


void MovieBST::makeEmpty()
{
	helpMakeEmpty(root);	//calls helper
	root = nullptr;		//sets root to null
}

void MovieBST::helpMakeEmpty(Node*&) //removes node
{
	if (root) {		//checks for root
		helpMakeEmpty(root->left);	//goes left
		helpMakeEmpty(root->right);	//goes right
		delete root;	//delete node
	}
	
}

//------------------------- insert(NodeData* newData) ---------------------------------
//inserts a new node into the BinTree
// Preconditions: "this" BinTree must exist
// Postconditions: inserts new data in the correct place
//-------------------------------------------------------------------------------------
bool MovieBST::insert(Movie newData) {
	return helpInsert(this->root, newData);
}



// --------------------- insertHelper -----------------------------------------
// Helper function to insert
// If NodeData is already in BSTree then node is not inserted
// --------------------------------------------------------------
bool MovieBST::helpInsert(Node*& thisNode, Movie newData) {
	if (thisNode == NULL) {
		thisNode = new Node;
		thisNode->data = newData;
		thisNode->left = NULL;
		thisNode->right = NULL;
	}


	else if (newData < thisNode->data)

	{
		helpInsert(thisNode->left, newData);  // traverse left
	}
	else if (newData >  thisNode->data)

	{
		helpInsert(thisNode->right, newData); // traverse right
	}
	else

	{
		return false;   // Node Data already exists
	}

	return true;    //Node inserted successfully
}



bool MovieBST::retrieve(const Movie&, Movie*&) const
{
	return false;
}

void MovieBST::printTree(Node*& movieNode) const
{
	if (movieNode == NULL)
		return;

	/* first recur on left child */
	printTree(movieNode->left);

	/* then print the data of node */
	cout << movieNode->data << endl;

	/* now recur on right child */
	printTree(movieNode->right);

}

void MovieBST::retrieve(Node*, const Movie&, Movie*&) const {};
