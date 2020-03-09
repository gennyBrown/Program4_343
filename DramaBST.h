#ifndef DRAMA_BST_H
#define DRAMA_BST_H
#include "MovieBST.h"
#include "Drama.h"
#include "Movie.h"

using namespace std;

class DramaBST : public MovieBST {
	// create a .cpp for each type of movieBST with overloaded function for insert, the rest will be the same.
	//friend ostream& operator<<(ostream& output, DramaBST& bst);
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
	//bool insert(Drama& drama);	//adds new nodes to the tree
	bool insert(Drama& newData);
	bool helpInsert(Node* thisNode, Drama* newData);

	void printTree();

	void printTree(Node* movieNode) const;

	void displaySideways() const;

	void sideways(Node* current, int level) const;

	ostream& sideways(ostream& output, Node* current, int level) const;

	/*
	bool operator==(const Drama&) const;	//equal operator overload
	bool operator!=(const Drama&) const;	//not equal operator overload
	bool operator<(const Drama&) const;	//less-than operator overload
	bool operator>(const Drama&) const;	//greater-than operator overload
//less-than-or-equal- to operator overload
	bool operator<=(const Drama&) const;
	//greater-than-or-equal- to operator overload	
	bool operator>=(const Drama&) const;
	Drama& operator=(const Drama&);	//assignment operator
	*/
private:

	Node* root;
};
#endif	//DRAMA_BST_H