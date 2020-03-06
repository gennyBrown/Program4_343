// ---------------------------------- MovieFactory.cpp -----------------------

// Genny Brown CSS 343

// 03/02/2020

// 02/15/2020

// ----------------------------------------------------------------------------

// this file implements the movie factory

// ----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "MovieFactory.h"

// ----------------------storeMovie(ifstream& input)-----------------------
//
// Description
// reads from the file and calls the helper function to create the movie objects
//
// preconditions: there is a valid file to be read from
// 
// postconditions: helper function is called and the variables for the oject are 
// initalized
// ---------------------------------------------------------------------------
bool MovieFactory::storeMovie(ifstream& input)
{
	while (!input.eof()) {	//checks to see if at end of file
		input >> movieType;			//reads movie type
		if (movieType == 'F') {		//if comedy
			
			getline(input, quantity, ',');	//reads inventory
			getline(input, director, ',');	//reads director
			getline(input, title, ',');	//reads title
			getline(input, year, ',');	//reads release year
			inventory = stoi(quantity);	//converts from string to int
			releaseYear = stoi(year);	//converts from string to int
			
			//makeMovie('F');		//creates the comedy object
			return true;
		}

		else if (movieType == 'D') {	//if drama
			getline(input, quantity, ',');	//reads inventory
			getline(input, director, ',');	//reads director
			getline(input, title, ',');	//reads title
			getline(input, year, ',');	//reads release year
			inventory = stoi(quantity);	//converts from string to int
			releaseYear = stoi(year);	//converts from string to int
			
			//makeMovie('D');	//creates the drama object
			return true;
		}

		else if (movieType == 'C') {	//if classic
			getline(input, quantity, ',');	//reads inventory
			getline(input, director, ',');	//reads director
			getline(input, title, ',');	//reads title
			getline(input, actor, ',');	//reads actor name
			getline(input, year, ',');	//reads release year
			inventory = stoi(quantity);	//converts from string to int
			releaseYear = stoi(year);	//converts from string to int
			
			//makeMovie('C');		//creates the classic object
			return true;
		}

		else {	//if incorrect formatting
			cout << "Incorrect input formatting" << endl;
			return false;
		}
	}//end while loop
}
//end storeMovie(ifstream& input)


// ----------------------makeMovie(char movieType)-----------------------
//
// Description
//	creates the movie objects
//
// preconditions: there is a movie type passed into the function
// 
// postconditions: movie objects are created with variables initalized
// ---------------------------------------------------------------------------
Movie* MovieFactory::makeMovie(char movieType)
{
	if (movieType == 'F') {	//if comedy
		Movie* comedy = new Comedy();	//creates new comedy oject
		comedy->setDirector(director);	//sets director
		comedy->setMovieType('F');	//sets movie type
		comedy->setQuantity(10);	//sets quantity
		comedy->setTitle(title);	//sets title
		comedy->setActor(actor);	//sets actor
		comedy->setYear(releaseYear);	//sets year
		return comedy;
			 
	}

	else if (movieType == 'D') {	//if drama
		Movie* drama = new Drama();		//creates new drama object
		drama->setDirector(director);	//sets director
		drama->setMovieType('D');	//sets movie type
		drama->setQuantity(10);		//sets quantity
		drama->setTitle(title);		//sets title
		drama->setActor(actor);		//sets actor
		drama->setYear(releaseYear); //sets year
		return drama;
	}

	else if(movieType == 'C') {	//if classic
		Movie* classic = new Classic();	//creates classic object
		classic->setActor(actor);	//sets actor
		classic->setDirector(director);	//sets director
		classic->setMovieType('C');		//sets movie type
		classic->setQuantity(10);	//sets quantity
		classic->setTitle(title);	//sets title
		classic->setYear(releaseDate);	//sets release date
		return classic;
	}
	else {	//if not F,D or C
		cout << "invalid movie type" << endl;
	}
}
//end makeMovie(char movieType)