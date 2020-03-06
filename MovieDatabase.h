#define MOVIE_DATABASE_H
#ifdef MOVIE_DATABASE_H
#include "NodeData.h"
#include "Movie.h"
#include "MovieBST.h"
#include <vector>

using namespace std;

class MovieDatabase {

public:

	MovieDatabase(); // constructor
	~MovieDatabase();		//destructor
	MovieBST getComedies();	//gets the BST for comedies
	MovieBST getDramas();	//gets the BST for dramas
	MovieBST getClassics();	//gets the BST for classics

protected:
	vector <vector<MovieBST>> trees;
	
	MovieBST comedies;	//stores comedies
	MovieBST dramas;		//stores dramas
	MovieBST classics;	//stores classics
};

#endif