#include "MovieDatabase.h"


MovieDatabase::MovieDatabase() {

}
MovieDatabase::~MovieDatabase() { //destructor

} 

MovieBST MovieDatabase::getComedies() { //gets the BST for comedies
	return comedies;
}

MovieBST MovieDatabase::getDramas() { //gets the BST for dramas
	return dramas;
}	
MovieBST MovieDatabase::getClassics() { //gets the BST for classics
	return classics;
}	

vector <vector<MovieBST>> trees;

MovieBST comedies;	//stores comedies
MovieBST dramas;		//stores dramas
MovieBST classics;	//stores classics