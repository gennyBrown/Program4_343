#ifndef CLASSSIC_H
#define CLASSIC_H
//#ifdef CLASSIC_H
#include "Movie.h"

using namespace std;

//class Movie{};


class Classic:public Movie {

public:
	Classic();	//default constructor 
	//constructor with parameters for use in the factory
	Classic(char type, int quantity, string director, string title,
		string actor,string releaseDate);
	virtual ~Classic();		//destructor

		//sets the release date of the movie
	virtual void setReleaseDate(string releaseDate);
	virtual string getReleaseDate();		//returns the release date of the movie

	virtual void setActor(string name);	//sets the actor of the movie
	virtual string getActor();	//returns the actor of the movie
	virtual char getMovieType();	//returns the movie type

protected:
	string releaseDate;		//stores the release date of the movie
	string actor;		//stores actor name
};


#endif // CLASSIC_H
