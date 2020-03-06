#ifndef CLASSIC_BST_H
#define CLASSIC_BST_H
#include "MovieBST.h"
#include "Classic.h"

using namespace std;

class ClassicBST : public MovieBST {
	// create a .cpp for each type of movieBST with overloaded function for insert, the rest will be the same.
public:
	struct Node {
		Classic* data;
		Node* left;
		Node* right;
	};
	//allows for using Node instead of sruct Node
	using Node = struct Node;

	ClassicBST();
	~ClassicBST();
	void makeEmpty();	//clears the tree
	bool insert(Classic*);	//adds new nodes to the tree
	bool retrieve(const Classic&, Classic*&) const;	 	//gets given node
	void printTree(Node*&) const;

private:

	Node* root;

	void makeEmpty(Node*);	//makeEmpty helper
	void retrieve(Node*, const Classic&, Classic*&) const;	//retrieve helper
};
#endif	//CLASSSIC_BST_H#endif	//CLASSSIC_BST_H