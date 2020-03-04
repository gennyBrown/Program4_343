/// ------------------------------------------------ Movie.h -------------------------------------------------------

// Steven Bollman CSS 343 C

// Creation Date - 3/3/2020

// Date of Last Modification - 3/3/2020

// --------------------------------------------------------------------------------------------------------------------

// Purpose - This is the header file for the Movie class, and outlines constructors, getters and setters for director,
//title, quantity, movieType, and year.
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------




#define MOVIE_H
#ifdef MOVIE_H
#include <string>

using namespace std;

class Movie {

public:
	Movie();	//constructor
	Movie(string director, string title, char movieType, int quantity, int year); //constructor
	virtual ~Movie();	//destructor

	virtual void setDirector(string name);	//sets the name of the director
	virtual string getDirector();		//returns the name of the director for aa movie

	virtual void setTitle(string name);	//sets the title
	virtual string getTitle();	//returns the title for a given movie

	virtual void setQuantity(int amount);	//sets quantity
	virtual int getQuantity();	//returns quantity

	virtual void setMovieType(char type);	//sets the movie type
	virtual char getMovieType() const;	//virtual function to return movie type 
	// Took out =0... add back after the rest of classes are implemented

	virtual void setYear(int year); //sets the movie year
	virtual int getYear();    // returns the movie year


protected:
	string director;	//holds the movie director
	string title;		//holds the movie title
	char type;		//holds the movie type
	int quantity;		//holds the quantity of the movie
	int year;		// hold year movie was released
};

#endif