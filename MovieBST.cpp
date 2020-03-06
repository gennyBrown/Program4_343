#include "MovieBST.h"

using namespace std;

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

void MovieBST::makeEmpty(Node*&)
{
	if (root) {		//checks for root
		makeEmpty(root->left);	//goes left
		makeEmpty(root->right);	//goes right
		delete root;	//delete node
	}

}

bool MovieBST::insert(Movie*)
{
	return false;
}

bool MovieBST::retrieve(const Movie&, Movie*&) const
{

}

void MovieBST::printTree(Node*&) const
{

}

void MovieBST::retrieve(Node*, const Movie&, Movie*&) const {};