/// ----------------------------- DramaBST.cpp ---------------------------------

// Steven Bollman & Genny Brown CSS 343 C

// Creation Date - 3/3/2020

// Date of Last Modification - 3/14/2020

// ----------------------------------------------------------------------------

// Purpose - This program provides constructors, destructor, insert with helper,
// retrieve with and without output for testing purposes and helper
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#include "ComedyBST.h"
#include <iostream>

// ----------------------ComedyBST()--------------------------------
//
// Description
//	default constructor for ComedyBST 
//
// preconditions: the ComedyBST object was called by another function
// 
// postconditions: ComedyBST object was created
// ---------------------------------------------------------------------------
ComedyBST::ComedyBST()
{
}
//end ComedyBST

// ----------------------~ComedyBST()--------------------------------
//
// Description
//	destructor for ComedyBST object
//
// preconditions: ComedyBST object created
// 
// postconditions: memory reallocated
// ---------------------------------------------------------------------------
ComedyBST::~ComedyBST()
{
}
//end ComedyBST()

// ----------------------insert(Comedy &newData)--------------------------------
//
// Description
//	calls helper to insert a new node
//
// preconditions: valid parameter passed
// 
// postconditions: helper called
// ---------------------------------------------------------------------------
bool ComedyBST::insert(Comedy& newData)
{
	return helpInsert(this->root, &newData);
}
//end insert(Comedy& newData)

// ------------helpInsert(Node*& thisNode, Comedy *newData)---------------------
//
// Description
//	insert a new node into the tree
//
// preconditions: valid parameter passed
// 
// postconditions: node inserted
// ---------------------------------------------------------------------------
bool ComedyBST::helpInsert(Node*& thisNode, Comedy* newData)
{
	if (thisNode == NULL) {
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
//end helpInsert(Node*& thisNode, Comedy* newData)

// ------------------------------printTree()---------------------------------
//
// Description
//	calls helper to print tree
//
// preconditions: tree exists to print
// 
// postconditions: helper called
// ---------------------------------------------------------------------------
void ComedyBST::printTree()
{
	printTree(*&root);
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
void ComedyBST::printTree(Node*& movieNode)
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

// ---------------------retrieve(Comedy& pd)--------------------------------
//
// Description
//	search tree for given node
//
// preconditions: valid parameter passed
// 
// postconditions: helper called, node found
// ---------------------------------------------------------------------------
Comedy* ComedyBST::retrieve(Comedy& pd)
{
	Comedy* nd;
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
//end retrieve(Comedy& pd)

// ---------------------retrieveNoOutput(Comedy& pd)---------------------------
//
// Description
//	search tree for given node
//
// preconditions: valid parameter passed
// 
// postconditions: node found
// ---------------------------------------------------------------------------
Comedy* ComedyBST::retrieveNoOutput(Comedy& pd)
{
	Comedy* nd;
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
//end retrieveNoOutput(Comedy& pd)

// ---------------contains(Node* curr, const Comedy& pd) const------------------
//
// Description
//	search tree for given node rucursively
//
// preconditions: valid parameter passed
// 
// postconditions: node found, and passed to retrieve
// ---------------------------------------------------------------------------
ComedyBST::Node* ComedyBST::contains(Node* curr, const Comedy& pd) const
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
//end contains(Node* curr, const Comedy& pd) const