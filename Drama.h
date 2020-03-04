#ifndef DRAMA_H
#define DRAMA_H
//#ifdef DRAMA_H
#include "Movie.h"

using namespace std;

//class Movie {};

class Drama:public Movie{

public:
	Drama();		//default constructor
	//constructor with parameters for use in the factory
	Drama(char type, int quantity, string director, string title, int year);
	~Drama();		//destructor

	virtual void setYear(int year);	//sets the release year of the movie
	virtual int getYear();		//returns the release year of the movie

	virtual char getMovieType();	//returns the type of the movie

protected:
	int year;		//stores the release year of the movie
};


#endif // DRAMA_
