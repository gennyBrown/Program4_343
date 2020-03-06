#ifndef MOVIE_BST_H

#define MOVIE_BST_H

#include "Movie.h"



using namespace std;



class MovieBST {



public:

	struct Node {

		Movie* data;

		Node* left;

		Node* right;

	};

	MovieBST();

	~MovieBST();

	void makeEmpty();	//clears the tree

	bool insert(Movie*);	//adds new nodes to the tree

	bool retrieve(const Movie&, Movie*&) const;	 	//gets given node

	void printTree(Node*&) const;



private:



	Node* root;



	void makeEmpty(Node*&);	//makeEmpty helper

	bool insertComedy(Node*&, Movie*);	//inserts new Comedy into tree

	bool insertDrama(Node*&, Movie*);	//inserts new Drama into tree

	bool insertClassic(Node*&, Movie*);	//inserts new Classic into tree

	void retrieve(Node*, const Movie&, Movie*&) const;	//retrieve helper

};



#endif // !MOVIE_BST_H