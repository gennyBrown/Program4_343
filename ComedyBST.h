#ifndef COMEDY_BST_H
#define COMEDY_BST_H
#include "MovieBST.h"
#include "Comedy.h"

using namespace std;

class ComedyBST : public MovieBST {
	// create a .cpp for each type of movieBST with overloaded function for insert, the rest will be the same.
public:
	struct Node {
		Comedy* data;
		Node* left;
		Node* right;
	};
	//allows for using Node instead of sruct Node
	using Node = struct Node;

	ComedyBST();
	~ComedyBST();
	void makeEmpty();	//clears the tree
	bool insert(Comedy*);	//adds new nodes to the tree
	bool retrieve(const Comedy&, Comedy*&) const;	 	//gets given node
	void printTree(Node*&) const;

private:

	Node* root;

	void makeEmpty(Node*);	//makeEmpty helper
	void retrieve(Node*, const Comedy&, Comedy*&) const;	//retrieve helper
};
#endif	//COMEDY_BST_H