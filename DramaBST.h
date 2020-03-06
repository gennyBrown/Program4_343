#ifndef DRAMA_BST_H
#define DRAMA_BST_H
#include "MovieBST.h"
#include "Drama.h"

using namespace std;

class DramaBST : public MovieBST {
	// create a .cpp for each type of movieBST with overloaded function for insert, the rest will be the same.
public:
	struct Node {
		Drama* data;
		Node* left;
		Node* right;
	};
	//allows for using Node instead of sruct Node
	using Node = struct Node;

	DramaBST();
	~DramaBST();
	void makeEmpty();	//clears the tree
	bool insert(Drama*);	//adds new nodes to the tree
	bool retrieve(const Drama&, Drama*&) const;	 	//gets given node
	void printTree(Node*&) const;

private:

	Node* root;

	void makeEmpty(Node*);	//makeEmpty helper
	void retrieve(Node*, const Drama&, Drama*&) const;	//retrieve helper
};
#endif	//DRAMA_BST_H