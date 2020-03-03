#define BST_H
#ifdef BST_H
#include "NodeData.h"

using namespace std;

class BST {

public:
	struct Node {
		NodeData* data;
		Node* left;
		Node* right;
	};
	BST();
	~BST();
	void makeEmpty();	//clears the tree
	bool insert(NodeData*);	//adds new nodes to the tree
	bool retrieve(const NodeData&, NodeData*&) const;	 	//gets given node
	void printTree(Node*&) const;

private:

	Node* root;

	void makeEmpty(Node*&);	//makeEmpty helper
	bool insertComedy(Node*&, NodeData*);	//inserts new Comedy into tree
	bool insertDrama(Node*&, NodeData*);	//inserts new Drama into tree
	bool insertClassic(Node*&, NodeData*);	//inserts new Classic into tree
	void retrieve(Node*, const NodeData&, NodeData*&) const;	//retrieve helper
};

#endif