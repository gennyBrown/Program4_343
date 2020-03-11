#ifndef CLASSIC_H
#define CLASSIC_H
#include "Movie.h"
#include <string>

using namespace std;


class Classic : public Movie {
	friend ostream& operator<<(ostream& output, Classic& nd);
public:
	Classic();	//default constructor 
	//constructor with parameters for use in the factory
	Classic(char type, int quantity, string director, string title,
		string actor, string releaseDate);
	virtual ~Classic();		//destructor

		//sets the release date of the movie
	virtual void setReleaseDate(string releaseDate);
	virtual string getReleaseDate();		//returns the release date of the movie

	virtual void setActor(string name);	//sets the actor of the movie
	virtual string getActor();	//returns the actor of the movie
	virtual char getMovieType();	//returns the movie type

	string releaseDate;		//stores the release date of the movie
	string actor;		//stores actor name

	bool operator==(const Classic&) const;	//equal operator overload
	bool operator!=(const Classic&) const;	//not equal operator overload
	bool operator<(const Classic&) const;	//less-than operator overload
	bool operator>(const Classic&) const;	//greater-than operator overload
//less-than-or-equal- to operator overload
	bool operator<=(const Classic&) const;
	//greater-than-or-equal- to operator overload	
	bool operator>=(const Classic&) const;
	Classic& operator=(const Classic&);	//assignment operator
};
#endif // CLASSIC_H

