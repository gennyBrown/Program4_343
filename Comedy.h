#define COMEDY_H
#ifdef COMEDY_H
#include "Movie.h"
//#include "MovieFactory.h"
using namespace std;

class Comedy:public Movie {

public:
	Comedy();	//default constructor
	//constructor with parameters for creation in factory
	Comedy(char type, int quantity, string director, string title, int year);
	virtual ~Comedy();	//destructor

	void setYear(int year);	//set the release year of the movie
	int getYear();		//returns the release year of the movie


	virtual char getMovieType();	//returns the movie type

protected:
	int year;	//holds the release year of the movie
};

#endif