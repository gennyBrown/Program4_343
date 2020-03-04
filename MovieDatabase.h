#define MOVIE_DATABASE_H
#ifdef MOVIE_DATABASE_H
#include "BST.h"
#include "Movie.h"
#include <vector>

using namespace std;

class MovieDatabase {

public:
	~MovieDatabase();		//destructor
	BST getComedies();	//gets the BST for comedies
	BST getDramas();	//gets the BST for dramas
	BST getClassics();	//gets the BST for classics

protected:
	vector <BST<Movies>> trees;
	
	BST comedies;	//stores comedies
	BST dramas;		//stores dramas
	BST classics;	//stores classics
};

#endif