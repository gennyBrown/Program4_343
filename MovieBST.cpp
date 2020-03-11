#include <iostream>
#include "MovieBST.h"


MovieBST::MovieBST()
{
	root = nullptr;		//set root to null
}

MovieBST::~MovieBST()
{
	makeEmpty(root);		//calls recuresive helper
}

void MovieBST::makeEmpty()
{
	
	makeEmpty(root);	//calls helper
	root = nullptr;		//sets root to null
	
}

void MovieBST::makeEmpty(Node*& root)
{
	if (root) {		//checks for root
		makeEmpty(root->left);	//goes left
		makeEmpty(root->right);	//goes right
		delete root;	//delete node
	}
	
}


//------------------------- insert(NodeData* newData) ---------------------------------
//inserts a new node into the BinTree
// Preconditions: "this" BinTree must exist
// Postconditions: inserts new data in the correct place
//-------------------------------------------------------------------------------------
bool MovieBST::insert(Movie &newData) {
	return helpInsert(this->root, &newData);
}



// --------------------- insertHelper -----------------------------------------
// Helper function to insert
// If NodeData is already in BSTree then node is not inserted
// --------------------------------------------------------------
bool MovieBST::helpInsert(Node*& thisNode, Movie *newData) {
	if (thisNode == NULL) {
		thisNode = new Node;
		thisNode->data = newData;
		thisNode->left = NULL;
		thisNode->right = NULL;
		cout << "New node created" << endl;
		cout << *(thisNode->data) << endl;
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


bool MovieBST::retrieve(const Movie&, Movie*&) const
{
	return true;
}

void MovieBST::printTree()
{
	printTree(*&root);
}


void MovieBST::printTree(Node*& movieNode)
{
	if (movieNode == NULL)
		return;
	else{
		/* first recur on left child */
		printTree(movieNode->left);

		/* then print the data of node */
		cout << *(movieNode->data) << endl;
		
		/* now recur on right child */
		printTree(movieNode->right);
	}
}

void MovieBST::retrieve(Node*, const Movie&, Movie*&) const 
{

}
