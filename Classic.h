#define CLASSIC_H
#ifdef CLASSIC_H
#include "Movie.h"

using namespace std;

class Classic::public Movie {

public:
	Classic();	//default constructor 
	//constructor with parameters for use in the factory
	Classic(string director, string title, char type, int quantity,
		string releaseDate, string actor);
	virtual ~Classic();		//destructor

		//sets the release date of the movie
	virtual void setReleaseDate(string releaseDate);
	virtual string getReleaseDate();		//returns the release date of the movie

	virtual void setActor(string name);	//sets the actor of the movie
	virtual string getActor(string name);	//returns the actor of the movie
	virtual char getMovieType();	//returns the movie type

protected:
	string releaseDate;		//stores the release date of the movie
	string actor;		//stores actor name
};


#endif // CLASSIC_H
