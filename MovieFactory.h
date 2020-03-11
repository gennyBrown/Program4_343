#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H
#include <fstream>

#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"
using namespace std;


class MovieFactory {
public:
	//	MovieFactory();
	//	virtual ~MovieFactory();
	void readFile();
	bool storeMovie(ifstream& input);
	Movie* makeMovie(char movieType);

	char movieType;
	int releaseDate, quantity, year;
	string title, actor, director, inventory, releaseYear;
};

#endif