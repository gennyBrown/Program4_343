#include "DramaBST.h"
#include "Movie.h"
#include "MovieFactory.h"
#include <iostream>

using namespace std;

DramaBST::DramaBST()
{
}

DramaBST::~DramaBST()
{
}
/*
bool DramaBST::insert(Drama& newData) {
	
}
*/


bool DramaBST::insert(Drama& newData)
{
	return helpInsert(this->root, &newData);
}

// --------------------- insertHelper -----------------------------------------
// Helper function to insert
// If NodeData is already in BSTree then node is not inserted
// --------------------------------------------------------------
bool DramaBST::helpInsert(Node* thisNode, Drama *newData) {
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
/*void DramaBST::printTree() {
	printTree(root);
}

/*void DramaBST::printTree(Node* movieNode) const
{
	if (movieNode == NULL)
		return;
	else {
		// first recur on left child 
		printTree(movieNode->left);

		// then print the data of node 
		cout << "PrintTree Test" << endl;
		cout << movieNode->data->type << endl;
		cout << (&movieNode->data->quantity) << endl;
		cout << (&movieNode->data->title) << endl;
		cout << (&movieNode->data->year) << endl;

		// now recur on right child 
		printTree(movieNode->right);
	}

}*/

void DramaBST::displaySideways() const {
	sideways(root, 0);
}
//end displaySideways

//-------------------- sideways(Node* current, int level) const --------------
// Helper method for displaySideways
// Preconditions: curr != nullptr
// Postconditions: BinTree is printed.
//--------------------------------------------------------------------------
void DramaBST::sideways(Node* current, int level) const
{
	if (current != nullptr) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}
//end sideways(Node* current, int level) const 

//-------- sideways(ostream& output, Node* current, int level) const ---------
// function overlod helper for <<operator
// Preconditions: curr != nullptr
// Postconditions: BinTree is printed.
//--------------------------------------------------------------------------
ostream& DramaBST::sideways(ostream& output, Node* current, int level) const
{
	//check current
	if (current != nullptr) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			output << "    ";
		}
		output << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
	return output;
}
//end sideways(ostream& output, Node* current, int level) const


//--------------------- operator<<(ostream& output, BinTree& bst) -------------
// calls sideways function overload to print bst
// Preconditions: NONE
// Postconditions: bst printed
//--------------------------------------------------------------------------
/*ostream& operator<<(ostream& output, DramaBST& bst)
{
	return bst.sideways(output, bst.root, 0);
}*/
//end operator<<(ostream& output, BinTree& bst)