#include <iostream>
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"
#include "MovieFactory.h"

MovieFactory::MovieFactory()
{

}

MovieFactory::~MovieFactory()
{

}

void MovieFactory::storeMovie(ifstream& input)
{
	while (!input.eof()) {
		input >> movieType;			//reads movie type
		if (movieType == 'F') {		//if comedy
			
			//Comedy(string director, string title, char type, int quantity, int year);
		}
		else if (movieType == 'D') {	//if drama
			
			//Drama(string director, string title, char type, int quantity, int year);
		}
		else if (movieType == 'C') {	//if classic
			
			//Classic(string director, string title, char type, int quantity, string releaseDate, string actor);
		}
		else {	//if incorrect formatting
			cout << "Incorrect input formatting" << endl;
		}
	}//end while loop
}

bool MovieFactory::makeMovie(char movieType)
{
	return false;
}
