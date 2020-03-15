/// ----------------------------- DramaBST.cpp ---------------------------------

// Steven Bollman & Genny Brown CSS 343 C

// Creation Date - 3/3/2020

// Date of Last Modification - 3/14/2020

// ----------------------------------------------------------------------------

// Purpose - This program provides constructors, destructor, insert with helper,
// retrieve with and without output for testing purposes and helper
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#include "DramaBST.h"
#include "Movie.h"
#include "MovieFactory.h"
#include <iostream>

using namespace std;

// ----------------------DramaBST()--------------------------------
//
// Description
//	default constructor for DramaBST 
//
// preconditions: the DramaBST object was called by another function
// 
// postconditions: DramaBST object was created
// ---------------------------------------------------------------------------
DramaBST::DramaBST()
{
}
//end DramaBST()

// ----------------------~DramaBST()--------------------------------
//
// Description
//	destructor for dramaBST object
//
// preconditions: DramaBST object created
// 
// postconditions: memory reallocated
// ---------------------------------------------------------------------------
DramaBST::~DramaBST()
{
}
//end ~DramaBST()

// ----------------------insert(Drama &newData)--------------------------------
//
// Description
//	calls helper to insert a new node
//
// preconditions: valid parameter passed
// 
// postconditions: helper called
// ---------------------------------------------------------------------------
bool DramaBST::insert(Drama &newData)
{
	return helpInsert(this->root, &newData);
}
//end insert(Drama &newData)


// ------------helpInsert(Node*& thisNode, Drama *newData)---------------------
//
// Description
//	insert a new node into the tree
//
// preconditions: valid parameter passed
// 
// postconditions: node inserted
// ---------------------------------------------------------------------------
bool DramaBST::helpInsert(Node*& thisNode, Drama *newData) {
	if (thisNode == NULL) {	//if node null, create node
		thisNode = new Node;
		thisNode->data = newData;
		thisNode->left = NULL;
		thisNode->right = NULL;
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
//end helpInsert(Node*& thisNode, Drama *newData)

// ------------------------------printTree()---------------------------------
//
// Description
//	calls helper to print tree
//
// preconditions: tree exists to print
// 
// postconditions: helper called
// ---------------------------------------------------------------------------
void DramaBST::printTree()
{
	printTree(*&root);	//call helper, pass in root
}
//end printTree()

// ----------------------printTree(Node*& movieNode)--------------------------
//
// Description
//	print the tree
//
// preconditions: valid parameter passed
// 
// postconditions: tree printed
// ---------------------------------------------------------------------------
void DramaBST::printTree(Node*& movieNode) 
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
//end printTree(Node*& movieNode)

// ---------------------retrieve(Drama& pd)--------------------------------
//
// Description
//	search tree for given node
//
// preconditions: valid parameter passed
// 
// postconditions: helper called, node found
// ---------------------------------------------------------------------------
Drama* DramaBST::retrieve(Drama& pd)
{
	Drama* nd;
	//check if tree is empty
	if (root == nullptr) {
		cout << &(pd) << endl;
		return &(pd);
	}
	//check value in root
	if (*(root->data) == pd) {
		nd = root->data;
		cout << *(nd) << endl;
		return nd;
	}
	//create new node pointer with retrun value of contains
	Node* newNode = contains(root, pd);
	//check contains != nullptr
	if (newNode == nullptr) {
		cout << "nullptr" << endl;
		return nullptr;
	}
	//assign pointer
	nd = newNode->data;
	cout << *(nd) << endl;
	return nd;
}
//end retrieve(Drama& pd)

// ---------------------retrieveNoOutput(Drama& pd)---------------------------
//
// Description
//	search tree for given node
//
// preconditions: valid parameter passed
// 
// postconditions: node found
// ---------------------------------------------------------------------------
Drama* DramaBST::retrieveNoOutput(Drama& pd)
{
	Drama* nd;
	//check if tree is empty
	if (root == nullptr) {
		return &(pd);
	}
	//check value in root
	if (*(root->data) == pd) {
		nd = root->data;
		return nd;
	}
	//create new node pointer with retrun value of contains
	Node* newNode = contains(root, pd);
	//check contains != nullptr
	if (newNode == nullptr) {
		cout << "nullptr" << endl;
		return nullptr;
	}
	//assign pointer
	nd = newNode->data;
	return nd;
}
//end retrieveNoOutput(Drama& pd)

// ---------------contains(Node* curr, const Drama& pd) const------------------
//
// Description
//	search tree for given node rucursively
//
// preconditions: valid parameter passed
// 
// postconditions: node found, and passed to retrieve
// ---------------------------------------------------------------------------
DramaBST::Node* DramaBST::contains(Node* curr, const Drama& pd) const
{
	//check curr for nullptr
	if (curr == nullptr) {
		return nullptr;
	}
	//check curr->data
	if (*(curr->data) == pd) {
		return curr;
	}
	//check size of pd, if larger traverse right
	else if (pd > * (curr->data)) {
		return contains(curr->right, pd);
	}
	//check size of pd, if smaller traverse left
	else if (pd < *(curr->data)) {
		return contains(curr->left, pd);
	}
	return curr;
}
//end contains(Node* curr, const Drama& pd) const