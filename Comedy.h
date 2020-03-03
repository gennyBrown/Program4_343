#define COMEDY_H
#ifdef COMEDY_H
#include "Movie.h"
using namespace std;

class Comedy:: public Movie {

public:
	Comedy();	//default constructor
	//constructor with parameters for creation in factory
	Comedy(string director, string title, char type, int quantity, int year);
	virtual ~Comedy();	//destructor

	virtual void setYear(int year);	//set the release year of the movie
	virtual int getYear();		//returns the release year of the movie


	virtual char getMovieType();	//returns the movie type

protected:
	int year;	//holds the release year of the movie
};

#endif