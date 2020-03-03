#define MOVIE_H
#ifdef MOVIE_H
#include <string>

using namespace std;

class Movie {

public:
	Movie();	//constructor
	virtual ~Movie();	//destructor

	virtual void setDirector(string name);	//sets the name of the director
	virtual string getDirector();		//returns the name of the director for aa movie

	virtual void setTitle(string name);	//sets the title
	virtual string getTitle();	//returns the title for a given movie

	virtual void setQuantity(int amount);	//sets quantity
	virtual int getQuantity();	//returns quantity

	virtual void setMovieType(char type);	//sets the movie type
	virtual char getMovieType() const = 0;	//virtual function to return movie type

protected:
	string director;	//holds the movie director
	string title;		//holds the movie title
	char type;		//holds the movie type
	int quantity;		//holds the quantity of the movie

};

#endif